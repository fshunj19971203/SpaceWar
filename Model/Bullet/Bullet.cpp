#include "Bullet.h"
#include "cocos2d.h"
using namespace std;
USING_NS_CC;
using namespace SpaceWar;



bool SpaceWar::Bullet::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!SpaceObject::init());
		//Do Sth..
		//setState(Active);

		//Do Sth..
		bRet = true;
	} while (0);

	return bRet;
}

SpaceWar::Bullet::~Bullet()
{
	log("Bullet::~Bullet()");
}

cocos2d::Vec2 SpaceWar::Bullet::getDirection()
{
	Vec2 head = Vec2(5, 5);
	Vec2 end = Vec2(5, 6);
	return (this->convertToWorldSpace(end) - this->convertToWorldSpace(head)).getNormalized();
}
