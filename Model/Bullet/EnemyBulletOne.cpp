#include "EnemyBulletOne.h"

using namespace std;
USING_NS_CC;
using namespace SpaceWar;



SpaceWar::EnemyBulletOne* SpaceWar::EnemyBulletOne::create()
{
	EnemyBulletOne *sprite = new (std::nothrow) EnemyBulletOne();
		if (sprite && sprite->init())
		{
			sprite->autorelease();
			return sprite;
		}
		CC_SAFE_DELETE(sprite);
		return nullptr;
}

void SpaceWar::EnemyBulletOne::destroy()
{
	delete this;
}

void SpaceWar::EnemyBulletOne::BeginContact(b2Contact* contact, CPhysicsSprite* other)
{

}

void SpaceWar::EnemyBulletOne::EndContact(b2Contact* contact, CPhysicsSprite* other)
{

}

void SpaceWar::EnemyBulletOne::PreSolve(b2Contact* contact, const b2Manifold* oldManifold, CPhysicsSprite* other)
{

}

void SpaceWar::EnemyBulletOne::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse, CPhysicsSprite* other)
{

}


bool SpaceWar::EnemyBulletOne::init()
{
		bool bRet = false;
		do
		{
			CC_BREAK_IF(!Bullet::init());
			//Do Sth..
	
	
			//Do Sth..
			bRet = true;
		} while (0);
	
		return bRet;
}

SpaceWar::EnemyBulletOne::~EnemyBulletOne()
{

}

SpaceWar::EnemyBulletOne* SpaceWar::EnemyBulletOne::create(const std::string& filename)
{
	    EnemyBulletOne *sprite = new (std::nothrow) EnemyBulletOne();
	    if (sprite && sprite->initWithFile(filename) && sprite->init())
	    {
	        sprite->autorelease();
	        return sprite;
	    }
	    CC_SAFE_DELETE(sprite);
	    return nullptr;
}
