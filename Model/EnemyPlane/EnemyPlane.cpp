#include "EnemyPlane.h"
#include "ShootPattern.h"
#include "Time.h"
#include "PlayerPlaneManager.h"
#include "DataShared.h"
#include "SpaceObjectAgent.h"
#include "PhysicsWorldScene.h"
#include "InfoProcessingManager.h"



using namespace std;
USING_NS_CC;
using namespace SpaceWar;



bool SpaceWar::EnemyPlane::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Plane::init());
		//Do Sth..

		//

		__NotificationCenter::getInstance()->addObserver(
			this,
			CC_CALLFUNCO_SELECTOR(EnemyPlane::processPlayerPlaneMissileFiring),
			string("Mess[Missile->EnemyPlane:Distance]"),
			nullptr
		);



		//Do Sth..
		bRet = true;
	} while (0);

	return bRet;
}



void SpaceWar::EnemyPlane::activate()
{
	Plane::activate();
}



SpaceWar::EnemyPlane::~EnemyPlane()
{

}

void SpaceWar::EnemyPlane::onExit()
{
	Plane::onExit();
	//销毁订阅的消息
	__NotificationCenter::getInstance()->removeObserver(this, string("Mess[Missile->EnemyPlane:Distance]"));


}

void SpaceWar::EnemyPlane::manualDestroy(float time)
{
	//销毁订阅的消息
	__NotificationCenter::getInstance()->removeObserver(this, string("Mess[Missile->EnemyPlane:Distance]"));


	Plane::manualDestroy(time);
}


void SpaceWar::EnemyPlane::processPlayerPlaneMissileFiring(cocos2d::Ref* sender)
{
	auto info_process_center = InfoProcessingManager::getInstance();
	//检查此时玩家飞机是否有效
	if (PlayerPlaneManager::getInstance()->getPlayerPlaneAgent()->isValid()) {
		Vec2 player_plane_pos = PlayerPlaneManager::getInstance()->getPlayerPlaneAgent()->getSpaceObject()->getPosition();
		float dist = this->getPosition().distance(player_plane_pos);
		if (dist < info_process_center->getDistance()) {
			info_process_center->setTracedObject(static_cast<void*>(this));
			info_process_center->setDistance(dist);
		}
	}

}



cocos2d::Vec2 SpaceWar::EnemyPlane::getSprayUnitVector()
{
	return (this->convertToWorldSpace(getShootingPoint()) - this->convertToWorldSpace(getMiddlePoint())).getNormalized();
}



