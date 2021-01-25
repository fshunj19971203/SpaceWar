#include "TestPlayerBullet.h"
#include "PhysicsObjectLoadManager.h"
#include "PhysicsManager.h"
#include "CPhysicsSprite.h"
#include "GameTexture.h"
#include "EnemyPlane.h"
#include "Astroid.h"
#include "PlayerPlane.h"
#include "PlayerBullet.h"

using namespace std;
USING_NS_CC;
using namespace SpaceWar;



void SpaceWar::TestPlayerBullet::update(float dt)
{
	PlayerBullet::update(dt);
}

void SpaceWar::TestPlayerBullet::onEnter()
{
	PlayerBullet::onEnter();
}

void SpaceWar::TestPlayerBullet::onExit()
{
	PlayerBullet::onExit();
}

void SpaceWar::TestPlayerBullet::cleanup()
{
	PlayerBullet::cleanup();
}



void SpaceWar::TestPlayerBullet::activate()
{
	Bullet::activate();
}

void SpaceWar::TestPlayerBullet::BeginContact(cocos2d::Vec2 contact, CPhysicsSprite* other)
{
	if (dynamic_cast<Astroid*>(other)) {
		log("it is going to remove!......");
		this->manualDestroy(0);
	}
	if (dynamic_cast<PlayerPlane*>(other)) {
		log("it is going to remove!......");
		this->manualDestroy(0);

	}
	if (dynamic_cast<PlayerBullet*>(other)) {
		log("it is going to remove!......");
		this->manualDestroy(0);

	}

	if (dynamic_cast<EnemyPlane*>(other)) {
		log("it is going to remove!......");
		this->manualDestroy(0);

	}

	PlayerBullet::BeginContact(contact, other);

}

void SpaceWar::TestPlayerBullet::EndContact(cocos2d::Vec2 contact, CPhysicsSprite* other)
{
	PlayerBullet::EndContact(contact, other);
}

bool SpaceWar::TestPlayerBullet::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!PlayerBullet::init());
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
		this->initBody(body_def, getFilename());
		//Do Sth..
		bRet = true;
	} while (0);

	return bRet;
}

SpaceWar::TestPlayerBullet::~TestPlayerBullet()
{

}

SpaceWar::TestPlayerBullet* SpaceWar::TestPlayerBullet::create(const std::string& filename)
{
	TestPlayerBullet *sprite = new (std::nothrow) TestPlayerBullet();
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

SpaceWar::TestPlayerBullet* SpaceWar::TestPlayerBullet::clone()
{
	TestPlayerBullet *sprite = new (std::nothrow) TestPlayerBullet();
	sprite->setFilename(this->getFilename());
	if (sprite && sprite->initWithFile(GameTexture::getInstance()->getTextureRelativePath(this->getFilename())) && sprite->init())
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}




