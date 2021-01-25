#include "PlayerBullet.h"

using std::string;
USING_NS_CC;
bool SpaceWar::PlayerBullet::init()
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

SpaceWar::PlayerBullet::~PlayerBullet()
{
	log("PlayerBullet::~PlayerBullet");
}

void SpaceWar::PlayerBullet::BeginContact(cocos2d::Vec2 contact, CPhysicsSprite* other)
{
	//log("SpaceWar::PlayerBullet::BeginContact");
	SpaceObject::BeginContact(contact,other);
}

void SpaceWar::PlayerBullet::EndContact(cocos2d::Vec2 contact, CPhysicsSprite* other)
{
	//log("SpaceWar::PlayerBullet::EndContact");
}


