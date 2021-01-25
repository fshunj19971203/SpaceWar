#include "CPhysicsSprite.h"
#include "Astroid.h"



using namespace std;
USING_NS_CC;
using namespace SpaceWar;

bool SpaceWar::Astroid::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!SpaceObject::init());
		//Do Sth..
		this->setBlastRadius(500);

		//Do Sth..
		bRet = true;
	} while (0);

	return bRet;
}

SpaceWar::Astroid::~Astroid()
{

}

void SpaceWar::Astroid::onExit()
{
	SpaceObject::onExit();
}

cocos2d::Vec2 SpaceWar::Astroid::getMiddlePoint()
{
	auto rect = this->getBoundingBox();
	return Vec2(rect.size.width / 2, rect.size.height / 2);
}

void SpaceWar::Astroid::BeginContact(cocos2d::Vec2 contact, CPhysicsSprite* other)
{
	SpaceObject::BeginContact(contact, other);
}

void SpaceWar::Astroid::EndContact(cocos2d::Vec2 contact, CPhysicsSprite* other)
{

	SpaceObject::EndContact(contact, other);

}




