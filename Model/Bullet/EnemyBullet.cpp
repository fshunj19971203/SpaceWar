#include "EnemyBullet.h"
#include "Box2D/Box2D.h"
#include "Box2D/Box2D.h"
#include "SpaceObject.h"



using namespace std;
USING_NS_CC;
using namespace SpaceWar;

bool SpaceWar::EnemyBullet::init()
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

SpaceWar::EnemyBullet::~EnemyBullet()
{

}

void SpaceWar::EnemyBullet::BeginContact(cocos2d::Vec2 contact, CPhysicsSprite* other)
{
	log("EnemyBullet::BeginContact");
}

void SpaceWar::EnemyBullet::EndContact(cocos2d::Vec2 contact, CPhysicsSprite* other)
{
	log("EnemyBullet::EndContact");
}

void SpaceWar::EnemyBullet::PreSolve(b2Contact* contact, const b2Manifold* oldManifold, CPhysicsSprite* other)
{

}

void SpaceWar::EnemyBullet::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse, CPhysicsSprite* other)
{

}

