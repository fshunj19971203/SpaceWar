#include "PlayerBulletOne.h"
#include "PhysicsObjectLoadManager.h"
#include "PhysicsManager.h"
#include "Unit.h"

using namespace std;
USING_NS_CC;
using namespace SpaceWar;



SpaceWar::PlayerBulletOne* SpaceWar::PlayerBulletOne::create()
{
	PlayerBulletOne *sprite = new (std::nothrow) PlayerBulletOne();
		if (sprite && sprite->init())
		{
			sprite->autorelease();
			return sprite;
		}
		CC_SAFE_DELETE(sprite);
		return nullptr;
}

void SpaceWar::PlayerBulletOne::destroy()
{
	delete this;
}

void SpaceWar::PlayerBulletOne::BeginContact(b2Contact* contact, CPhysicsSprite* other)
{

}

void SpaceWar::PlayerBulletOne::EndContact(b2Contact* contact, CPhysicsSprite* other)
{

}

void SpaceWar::PlayerBulletOne::PreSolve(b2Contact* contact, const b2Manifold* oldManifold, CPhysicsSprite* other)
{

}

void SpaceWar::PlayerBulletOne::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse, CPhysicsSprite* other)
{

}


bool SpaceWar::PlayerBulletOne::init()
{
		bool bRet = false;
		do
		{
			CC_BREAK_IF(!PlayerBullet::init());
			//Do Sth..
				//create a b2BodyDef..
				b2BodyDef body_def;
				body_def.type = b2_dynamicBody;
				body_def.position.Set(Unit::PTM(500),Unit::PTM(500));
				body_def.linearVelocity = b2Vec2(0, 10.0);
	
				//bind the sprite and the body..
				body_def.userData = this;
				this->SetBody(PhysicsManager::getInstance()->getWorld()->CreateBody(&body_def));
	
				//add fixtures to body..
				PhysicsObjectLoadManager::getInstance()->getSc()->addFixturesToBody(GetBody(), "3_1");
	
	
				//anchorpoint :left_down corner..
				this->setAnchorPoint(PhysicsObjectLoadManager::getInstance()
					->getSc()->anchorPointForShape("3_1"));
	
			//Do Sth..
			bRet = true;
		} while (0);
	
		return bRet;
}

SpaceWar::PlayerBulletOne::~PlayerBulletOne()
{

}

SpaceWar::PlayerBulletOne* SpaceWar::PlayerBulletOne::create(const std::string& filename)
{
	    PlayerBulletOne *sprite = new (std::nothrow) PlayerBulletOne();
	    if (sprite && sprite->initWithFile(filename) && sprite->init())
	    {
	        sprite->autorelease();
	        return sprite;
	    }
	    CC_SAFE_DELETE(sprite);
	    return nullptr;
}
