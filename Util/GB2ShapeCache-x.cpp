

#include "GB2ShapeCache-x.h"
#include "Box2D/Box2D.h"
#include "base/CCNS.h"
#include <string>

using namespace cocos2d;

/**
* Internal class to hold the fixtures
//对应于每一个fixture的属性
*/
class FixtureDef {
public:
	FixtureDef()
		: next(NULL) {}

	~FixtureDef() {
		delete next;
		delete fixture.shape;
	}

	FixtureDef *next;
	b2FixtureDef fixture;
	int callbackData;
};

class BodyDef {
public:
	BodyDef()
		: fixtures(NULL) {}

	~BodyDef() {
		if (fixtures)
			delete fixtures;
	}

	FixtureDef *fixtures;
	Point anchorPoint;
};

static GB2ShapeCache *_sharedGB2ShapeCache = NULL;

GB2ShapeCache* GB2ShapeCache::sharedGB2ShapeCache(void) {
	if (!_sharedGB2ShapeCache) {
		_sharedGB2ShapeCache = new GB2ShapeCache();
		_sharedGB2ShapeCache->init();
	}

	return _sharedGB2ShapeCache;
}

bool GB2ShapeCache::init() {
	return true;
}

void GB2ShapeCache::reset() {
	std::map<std::string, BodyDef *>::iterator iter;
	for (iter = shapeObjects.begin(); iter != shapeObjects.end(); ++iter) {
		delete iter->second;
	}
	shapeObjects.clear();
}

void GB2ShapeCache::addFixturesToBody(b2Body *body, const std::string &shape) {
	std::map<std::string, BodyDef *>::iterator pos = shapeObjects.find(shape);
	CCASSERT(pos != shapeObjects.end(),
		(std::string(__FILE__)+std::string("-->")).c_str());
	BodyDef *so = (*pos).second;

	FixtureDef *fix = so->fixtures;
	while (fix) {
		body->CreateFixture(&fix->fixture);
		fix = fix->next;
	}
}

cocos2d::CCPoint GB2ShapeCache::anchorPointForShape(const std::string &shape) {
	std::map<std::string, BodyDef *>::iterator pos = shapeObjects.find(shape);
	assert(pos != shapeObjects.end());

	BodyDef *bd = (*pos).second;
	return bd->anchorPoint;
}

void GB2ShapeCache::addShapesWithFile(const std::string &plist,float scale_factor) {
	std::string fullPath = CCFileUtils::getInstance()->fullPathForFilename(plist);
	Dictionary *dict = Dictionary::createWithContentsOfFileThreadSafe(fullPath.c_str());
	CCAssert(dict != NULL, "Shape-file not found"); // not triggered - cocos2dx delivers empty dict if non was found
	CCAssert(dict->count() != 0, "plist file empty or not existing");

	Dictionary* metadataDict = static_cast<Dictionary*>(dict->objectForKey("metadata"));

	int format = metadataDict->valueForKey("format")->intValue();
	ptmRatio = metadataDict->valueForKey("ptm_ratio")->floatValue();
	//change..
	if (scale_factor != 1.0f)
	{
		ptmRatio *= scale_factor;
	}
	CCAssert(format == 1, "Format not supported");

	Dictionary *bodyDict = static_cast<Dictionary*>(dict->objectForKey("bodies"));

	//一个fixture的多边形shape最多8个顶点
	b2Vec2 vertices[b2_maxPolygonVertices];
	std::string bodyName;
	DictElement* element = NULL;
	//可能多个body
	CCDICT_FOREACH(bodyDict, element)
	{
		bodyName = element->getStrKey();
		BodyDef *bodyDef = new BodyDef();
		Dictionary* bodyData = static_cast<Dictionary*>(element->getObject());
		bodyDef->anchorPoint = PointFromString(bodyData->valueForKey("anchorpoint")->getCString());

		Array* fixtureList = static_cast<Array*>(bodyData->objectForKey("fixtures"));

		FixtureDef **nextFixtureDef = &(bodyDef->fixtures);

		Object* pObj = NULL;
		CCARRAY_FOREACH(fixtureList, pObj)
		{

			b2FixtureDef basicData;
			Dictionary *fixtureData = static_cast<Dictionary*>(pObj);

			basicData.filter.categoryBits = fixtureData->valueForKey("filter_categoryBits")->intValue();
			basicData.filter.maskBits = fixtureData->valueForKey("filter_maskBits")->intValue();
			basicData.filter.groupIndex = fixtureData->valueForKey("filter_groupIndex")->intValue();
			basicData.friction = fixtureData->valueForKey("friction")->floatValue();
			basicData.density = fixtureData->valueForKey("density")->floatValue();
			basicData.restitution = fixtureData->valueForKey("restitution")->floatValue();
			basicData.isSensor = fixtureData->valueForKey("isSensor")->boolValue();

			const String *cb = fixtureData->valueForKey("userdataCbValue");

			int callbackData = 0;

			if (cb)
				callbackData = cb->intValue();

			const String* fixtureType = fixtureData->valueForKey("fixture_type");

			if (fixtureType->compare("POLYGON") == 0) {
				Array* polygonsArray = static_cast<Array*>(fixtureData->objectForKey("polygons"));
				Object* pPolygon = NULL;
				CCARRAY_FOREACH(polygonsArray, pPolygon)
				{
					FixtureDef *fix = new FixtureDef();
					fix->fixture = basicData; // copy basic data
					fix->callbackData = callbackData;

					b2PolygonShape *polyshape = new b2PolygonShape();
					int vindex = 0;

					Array* polygonArray = static_cast<Array*>(pPolygon);
					assert(polygonArray->count() <= b2_maxPolygonVertices);

					Object* pSinglePolygon = NULL;
					CCARRAY_FOREACH(polygonArray, pSinglePolygon)
					{
						String* pStr = dynamic_cast<String*>(pSinglePolygon);
						Point offset = PointFromString(pStr->getCString());
						vertices[vindex].x = (offset.x / ptmRatio);
						vertices[vindex].y = (offset.y / ptmRatio);
						vindex++;
					}

					polyshape->Set(vertices, vindex);
					fix->fixture.shape = polyshape;

					// create a list
					*nextFixtureDef = fix;
					nextFixtureDef = &(fix->next);
				}

			}
			else if (fixtureType->compare("CIRCLE") == 0) {
				FixtureDef *fix = new FixtureDef();
				fix->fixture = basicData; // copy basic data
				fix->callbackData = callbackData;

				Dictionary *circleData = static_cast<Dictionary*>(fixtureData->objectForKey("circle"));

				b2CircleShape *circleShape = new b2CircleShape();

				circleShape->m_radius = circleData->valueForKey("radius")->floatValue() / ptmRatio;
				Point p = PointFromString(circleData->valueForKey("position")->getCString());
				circleShape->m_p = b2Vec2(p.x / ptmRatio, p.y / ptmRatio);
				fix->fixture.shape = circleShape;

				// create a list
				*nextFixtureDef = fix;
				nextFixtureDef = &(fix->next);

			}
			else {
				CCAssert(0, "Unknown fixtureType");
			}

			// add the body element to the hash
			shapeObjects[bodyName] = bodyDef;
		}
	}
}

void cocos2d::GB2ShapeCache::reLoad(const std::string& plist,float scale_factor)
{
	auto iter = shapeObjects.find(plist);
	if (iter != shapeObjects.end())
	{
		delete iter->second;
	}
	shapeObjects.erase(iter);
	this->addShapesWithFile(plist);
}
