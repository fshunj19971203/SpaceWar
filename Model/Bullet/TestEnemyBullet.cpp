#include "TestEnemyBullet.h"
#include "Astroid.h"
#include "PlayerPlane.h"
#include "PlayerBullet.h"
#include "GameTexture.h"
#include "CPhysicsSprite.h"


using namespace std;
USING_NS_CC;
using namespace SpaceWar;

//#TestEnemyBullet

SpaceWar::TestEnemyBullet* SpaceWar::TestEnemyBullet::create(const std::string& filename)
{
	TestEnemyBullet *sprite = new (std::nothrow) TestEnemyBullet();
	sprite->setFilename(filename);
	if (sprite &&
		sprite->initWithFile(GameTexture::getInstance()->getTextureRelativePath(filename)) &&
		sprite->init())
	{

		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

SpaceWar::TestEnemyBullet* SpaceWar::TestEnemyBullet::clone()
{
	TestEnemyBullet *sprite = new (std::nothrow) TestEnemyBullet();
	sprite->setFilename(this->getFilename());
	if (sprite && sprite->initWithFile(GameTexture::getInstance()->getTextureRelativePath(this->getFilename())) && sprite->init())
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void SpaceWar::TestEnemyBullet::update(float dt)
{
	EnemyBullet::update(dt);
}

void SpaceWar::TestEnemyBullet::onEnter()
{
	EnemyBullet::onEnter();
}

void SpaceWar::TestEnemyBullet::onExit()
{
	EnemyBullet::onExit();
}

void SpaceWar::TestEnemyBullet::cleanup()
{
	EnemyBullet::cleanup();
}

void SpaceWar::TestEnemyBullet::activate()
{
	EnemyBullet::activate();
}

void SpaceWar::TestEnemyBullet::BeginContact(cocos2d::Vec2 contact, CPhysicsSprite* other)
{
	EnemyBullet::BeginContact(contact, other);
	if (dynamic_cast<Astroid*>(other)) {
		log("it is going to remove!......");
		this->manualDestroy(0.3f);

	}
	if (dynamic_cast<PlayerPlane*>(other)) {
		log("it is going to remove!......");
		this->manualDestroy(0.3f);

	}
	if (dynamic_cast<PlayerBullet*>(other)) {
		log("it is going to remove!......");
		this->manualDestroy(0);
	}
}

void SpaceWar::TestEnemyBullet::EndContact(cocos2d::Vec2 contact, CPhysicsSprite* other)
{

}

bool SpaceWar::TestEnemyBullet::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!EnemyBullet::init());
		Size visibleSize = Director::getInstance()->getVisibleSize();
		//Do Sth..
		//set some trait
		b2BodyDef body_def;
		body_def.type = b2_dynamicBody;
		body_def.allowSleep = true;
		body_def.position = b2Vec2(0, 0);
		body_def.linearVelocity = b2Vec2(0, 0);
		body_def.linearDamping = 0;
		body_def.angularVelocity = 0;
		body_def.angularDamping = 0;
		body_def.gravityScale = 0;
		body_def.fixedRotation = false;//ÄÜ×Ô×ª..
		body_def.userData = this;
		//
		this->setPosition(Vec2(0, 0));
		this->initBody(body_def, this->getFilename());


		//Do Sth..
		bRet = true;
	} while (0);

	return bRet;
}

SpaceWar::TestEnemyBullet::~TestEnemyBullet()
{

}

