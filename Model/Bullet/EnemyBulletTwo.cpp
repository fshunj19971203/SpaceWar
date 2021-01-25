#include "EnemyBulletTwo.h"
#include "PhysicsObjectLoadManager.h"
#include "PhysicsManager.h"
#include "Unit.h"


using namespace std;
USING_NS_CC;
using namespace SpaceWar;

SpaceWar::EnemyBulletTwo* SpaceWar::EnemyBulletTwo::create()
{
	EnemyBulletTwo *sprite = new (std::nothrow) EnemyBulletTwo();
	if (sprite && sprite->init())
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void SpaceWar::EnemyBulletTwo::destroy()
{
	delete this;
}

void SpaceWar::EnemyBulletTwo::BeginContact(b2Contact* contact, CPhysicsSprite* other)
{

}

void SpaceWar::EnemyBulletTwo::EndContact(b2Contact* contact, CPhysicsSprite* other)
{

}

void SpaceWar::EnemyBulletTwo::PreSolve(b2Contact* contact, const b2Manifold* oldManifold, CPhysicsSprite* other)
{

}

void SpaceWar::EnemyBulletTwo::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse, CPhysicsSprite* other)
{

}


bool SpaceWar::EnemyBulletTwo::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!EnemyBullet::init());
		//Do Sth..
					//create a b2BodyDef..
		b2BodyDef body_def;
		body_def.type = b2_dynamicBody;
		body_def.position.Set(Unit::PTM(500), Unit::PTM(500));
		body_def.linearVelocity = b2Vec2(0, 10.0);

		//bind the sprite and the body..
		body_def.userData = this;
		this->SetBody(PhysicsManager::getInstance()->getWorld()->CreateBody(&body_def));

		//add fixtures to body..
		PhysicsObjectLoadManager::getInstance()->getSc()->addFixturesToBody(GetBody(), "1_2");


		//anchorpoint :left_down corner..
		this->setAnchorPoint(PhysicsObjectLoadManager::getInstance()
			->getSc()->anchorPointForShape("1_2"));


		//Do Sth..
		bRet = true;
	} while (0);

	return bRet;
}

SpaceWar::EnemyBulletTwo::~EnemyBulletTwo()
{

}

SpaceWar::EnemyBulletTwo* SpaceWar::EnemyBulletTwo::create(const std::string& filename)
{
	EnemyBulletTwo *sprite = new (std::nothrow) EnemyBulletTwo();
	if (sprite && sprite->initWithFile(filename) && sprite->init())
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}
