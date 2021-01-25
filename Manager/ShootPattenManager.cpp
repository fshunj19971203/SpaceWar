#include <string>
#include "ShootPattenManager.h"
#include "ShootPattern.h"
#include "GameTexture.h"
#include "PhysicsWorldScene.h"
#include "Plane.h"
#include "EnemyPlane.h"
#include "cocos2d.h"
#include "TestPlayerBullet.h"
#include "Unit.h"
#include "Box2D/Box2D.h"
#include "TestPlayerPlane.h"
#include "TestEnemyBullet.h"
#include "PlayerPlaneManager.h"
using namespace std;
USING_NS_CC;
using namespace SpaceWar;

bool SpaceWar::ShootPattenManager::init()
{
	setSpTwoShootAngle(0);
	return true;
}

SpaceWar::ShootPattern* SpaceWar::ShootPattenManager::getShootPatternOne(Plane* plane)
{
	/////////////////////////////////////////////////////////////////////////////////////
	ShootPattern* shoot = ShootPattern::create(plane);
	////////////////////do sth..

	shoot->m_shoot = [](ShootPattern* shoot_pattern) {
		//get plane info..
		EnemyPlane* enemy_plane = static_cast<EnemyPlane*>(shoot_pattern->getPlane());
		//发射点
		auto temp = enemy_plane->getShootingPoint();
		temp.y += 2;
		temp.x -= 8;
		Vec2 shoot_point = enemy_plane->convertToWorldSpace(temp);
		Vec2 shoot_direction = enemy_plane->getSprayUnitVector();


		///////////////do sth...
		//build bullets..
		auto bullet = TestEnemyBullet::create("EB_4");
		//set some important traits..

		bullet->GetBody()->SetTransform(Unit::Tob2Vec2(shoot_point), enemy_plane->GetBody()->GetAngle());
		bullet->synchronize();
		//apply forces..
		bullet->GetBody()->ApplyForceToCenter(Unit::Tob2Vec2(bullet->getDirection() * 5), true);



		///////////////do sth...
		//activate it..
		bullet->activate();
		//add it to layer..
		Layer* layer = PhysicsWorldScene::getLayerSpr();
		layer->addChild(bullet, 1, bullet->getGuid());
	};

	////////////////////do sth..
	return shoot;
}
//for player
SpaceWar::ShootPattern* SpaceWar::ShootPattenManager::getShootPatternTwo(Plane* plane)
{

	//初始化是0度.
	ShootPattern* shoot = ShootPattern::create(plane);
	////////////////////do sth..

	shoot->m_shoot = [this](ShootPattern* shoot_pattern) {
		//get plane info..
		TestPlayerPlane* player_plane = static_cast<TestPlayerPlane*>(shoot_pattern->getPlane());
		//射的点
		Vec2 middle_shoot_point = player_plane->getMiddleShootingPoint();
		middle_shoot_point = player_plane->convertToWorldSpace(middle_shoot_point);
		//射的两个炮孔
		auto left_shoot_point = player_plane->convertToWorldSpace(player_plane->getLeftShootPoint());

		auto right_shoot_point = player_plane->convertToWorldSpace(player_plane->getRightShootPoint());

		//射的方向
		Vec2 shoot_direct = (player_plane->convertToWorldSpace(player_plane->getMiddleShootingPoint()) - player_plane->convertToWorldSpace(player_plane->getMiddlePoint())).getNormalized();



		///////////////do sth...
		Vec2 place_pos;
		//第一个左子弹
		auto bullet1 = TestPlayerBullet::create(string("PB_1"));
		//set some important traits..
		//左子放在左炮孔
		place_pos = Vec2(left_shoot_point.x, left_shoot_point.y);
		bullet1->GetBody()->SetTransform(Unit::Tob2Vec2(place_pos), spTwo_shoot_angle
		);
		bullet1->setPosition(place_pos);
		bullet1->setRotation(-1 * CC_RADIANS_TO_DEGREES(bullet1->GetBody()->GetAngle()));
		bullet1->GetBody()->ApplyForceToCenter(Unit::Tob2Vec2(bullet1->getDirection() * 10), true);


		//第二右子弹
		auto bullet2 = bullet1->clone();
		place_pos = Vec2(right_shoot_point.x, right_shoot_point.y);
		bullet2->GetBody()->SetTransform(Unit::Tob2Vec2(place_pos), -spTwo_shoot_angle
		);
		bullet2->setPosition(place_pos);
		bullet2->setRotation(-1 * CC_RADIANS_TO_DEGREES(bullet2->GetBody()->GetAngle()));

		bullet2->GetBody()->ApplyForceToCenter(Unit::Tob2Vec2(bullet2->getDirection() * 10), true);
		///////////////do sth...

		//activate it..
		bullet1->activate();
		bullet2->activate();
		//add it to layer..
		Layer* layer = PhysicsWorldScene::getLayerSpr();
		layer->addChild(bullet1, 1, bullet1->getGuid());
		layer->addChild(bullet2, 1, bullet2->getGuid());

	};

	////////////////////do sth..
	return shoot;
}



void SpaceWar::ShootPattenManager::setSpTwoShootAngle(float val)
{
	if (val < 0 || val > Unit::degToRad(60))
		return;
	else
		this->spTwo_shoot_angle = val;
}

SpaceWar::ShootPattern* SpaceWar::ShootPattenManager::getShootPatternThree(Plane* plane)
{
	/////////////////////////////////////////////////////////////////////////////////////
	ShootPattern* shoot = ShootPattern::create(plane);
	////////////////////do sth..

	shoot->m_shoot = [](ShootPattern* shoot_pattern) {
		//get plane info..
		EnemyPlane* enemy_plane = static_cast<EnemyPlane*>(shoot_pattern->getPlane());
		//玩家飞机一旦无效就返回
		if (!PlayerPlaneManager::getInstance()->getPlayerPlaneAgent()->isValid()) {
			return;
		}
		auto player_plane = PlayerPlaneManager::getInstance()->getPlayerPlaneAgent()->getSpaceObject();
		auto rect = player_plane->getBoundingBox();
		auto player_pos = player_plane->getPosition();
		player_pos.x += rect.size.width / 2;
		player_pos.y += rect.size.height / 2;

		//左发射点
		auto left_temp = enemy_plane->getShootingLeftPoint();
		left_temp.y += 2;
		left_temp.x -= 8;
		Vec2 left_shoot_point = enemy_plane->convertToWorldSpace(left_temp);
		//左发射方向
		Vec2 left_shoot_direction = (player_pos - left_shoot_point).getNormalized();

		/////右发射点
		auto right_temp = enemy_plane->getShootingRightPoint();
		right_temp.y += 2;
		right_temp.x -= 8;
		Vec2 right_shoot_point = enemy_plane->convertToWorldSpace(right_temp);
		//右发射方向
		Vec2 right_shoot_direction = (player_pos - right_shoot_point).getNormalized();

		///////////////do sth...
		///////左炮孔发射的子弹
		auto bullet1 = TestEnemyBullet::create("EB_4");
		//set some important traits..

		bullet1->GetBody()->SetTransform(
			Unit::Tob2Vec2(left_shoot_point),
			Unit::rotateToAVec(Vec2(0, 1), left_shoot_direction));
		bullet1->setPosition(left_shoot_point);
		bullet1->setRotation(-1 * CC_RADIANS_TO_DEGREES(Unit::rotateToAVec(Vec2(0, 1), left_shoot_direction)));
		//apply forces..
		bullet1->GetBody()->ApplyForceToCenter(Unit::Tob2Vec2(bullet1->getDirection() * 5), true);


		//////////////右炮孔发射的子弹
		auto bullet2 = TestEnemyBullet::create("EB_4");
		//set some important traits..

		bullet2->GetBody()->SetTransform(
			Unit::Tob2Vec2(right_shoot_point),
			Unit::rotateToAVec(Vec2(0, 1), right_shoot_direction));
		bullet2->setPosition(right_shoot_point);
		bullet2->setRotation(-1 * CC_RADIANS_TO_DEGREES(Unit::rotateToAVec(Vec2(0, 1), right_shoot_direction)));
		//apply forces..
		bullet2->GetBody()->ApplyForceToCenter(Unit::Tob2Vec2(bullet2->getDirection() * 5), true);


		///////////////do sth...
		//activate it..
		bullet1->activate();
		bullet2->activate();
		//add it to layer..
		Layer* layer = PhysicsWorldScene::getLayerSpr();
		layer->addChild(bullet1, 1, bullet1->getGuid());
		layer->addChild(bullet2, 1, bullet2->getGuid());

	};

	////////////////////do sth..
	return shoot;
}

SpaceWar::ShootPattern* SpaceWar::ShootPattenManager::getShootPatternFive(Plane* plane)
{
	/////////////////////////////////////////////////////////////////////////////////////
	ShootPattern* shoot = ShootPattern::create(plane);
	////////////////////do sth..

	shoot->m_shoot = [](ShootPattern* shoot_pattern) {
		//get plane info..
		EnemyPlane* enemy_plane = static_cast<EnemyPlane*>(shoot_pattern->getPlane());
		//玩家飞机一旦无效就返回
		if (!PlayerPlaneManager::getInstance()->getPlayerPlaneAgent()->isValid()) {
			return;
		}
		auto player_plane = PlayerPlaneManager::getInstance()->getPlayerPlaneAgent()->getSpaceObject();
		auto rect = player_plane->getBoundingBox();
		auto player_pos = player_plane->getPosition();
		player_pos.x += rect.size.width / 2;
		player_pos.y += rect.size.height / 2;

		//左发射点
		auto left_temp = enemy_plane->getShootingLeftPoint();
		left_temp.y += 2;
		left_temp.x -= 8;
		Vec2 left_shoot_point = enemy_plane->convertToWorldSpace(left_temp);
		//左发射方向
		Vec2 left_shoot_direction = (player_pos - left_shoot_point).getNormalized();

		//中发射点
		Vec2 center_shoot_point = enemy_plane->getShootingPoint();
		center_shoot_point.y += 20;
		center_shoot_point.x -= 8;
		center_shoot_point = enemy_plane->convertToWorldSpace(center_shoot_point);

		//中发射方向
		Vec2 center_shoot_direction = (player_pos - center_shoot_point).getNormalized();

		/////右发射点
		auto right_temp = enemy_plane->getShootingRightPoint();
		right_temp.y += 2;
		right_temp.x -= 8;
		Vec2 right_shoot_point = enemy_plane->convertToWorldSpace(right_temp);
		//右发射方向
		Vec2 right_shoot_direction = (player_pos - right_shoot_point).getNormalized();



		/*build bullet__left*/
//////////////左炮孔发射的子弹
		auto bullet1 = TestEnemyBullet::create("EB_4");
		//set some important traits..

		bullet1->GetBody()->SetTransform(
			Unit::Tob2Vec2(left_shoot_point),
			Unit::rotateToAVec(Vec2(0, 1), left_shoot_direction));
		bullet1->setPosition(left_shoot_point);
		bullet1->setRotation(-1 * CC_RADIANS_TO_DEGREES(Unit::rotateToAVec(Vec2(0, 1), left_shoot_direction)));
		//apply forces..
		bullet1->GetBody()->ApplyForceToCenter(Unit::Tob2Vec2(bullet1->getDirection() * 5), true);

		/*build bullet__right*/

//////////////右炮孔发射的子弹
		auto bullet2 = TestEnemyBullet::create("EB_4");
		//set some important traits..

		bullet2->GetBody()->SetTransform(
			Unit::Tob2Vec2(right_shoot_point),
			Unit::rotateToAVec(Vec2(0, 1), right_shoot_direction));
		bullet2->setPosition(right_shoot_point);
		bullet2->setRotation(-1 * CC_RADIANS_TO_DEGREES(Unit::rotateToAVec(Vec2(0, 1), right_shoot_direction)));
		//apply forces..
		bullet2->GetBody()->ApplyForceToCenter(Unit::Tob2Vec2(bullet2->getDirection() * 5), true);


		/*build bullet__middle*/
		auto bullet3 = TestEnemyBullet::create("EB_4");
		//set some important traits..

		bullet3->GetBody()->SetTransform(
			Unit::Tob2Vec2(center_shoot_point),
			Unit::rotateToAVec(Vec2(0, 1), center_shoot_direction));
		bullet3->setPosition(center_shoot_point);
		bullet3->setRotation(-1 * CC_RADIANS_TO_DEGREES(Unit::rotateToAVec(Vec2(0, 1), center_shoot_direction)));
		//apply forces..
		bullet3->GetBody()->ApplyForceToCenter(Unit::Tob2Vec2(bullet3->getDirection() * 5), true);


		/*activate it..*/
		bullet1->activate();
		bullet2->activate();
		bullet3->activate();
		/*add it to layer..*/
		Layer* layer = PhysicsWorldScene::getLayerSpr();
		layer->addChild(bullet1, 1, bullet1->getGuid());
		layer->addChild(bullet2, 1, bullet2->getGuid());
		layer->addChild(bullet3, 1, bullet3->getGuid());


	};

	////////////////////do sth..
	return shoot;
}

SpaceWar::ShootPattenManager* SpaceWar::ShootPattenManager::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new ShootPattenManager();
		if (m_instance != nullptr) {
			m_instance->init();
		}
	}
	return m_instance;
}

void SpaceWar::ShootPattenManager::destroy()
{
	if (m_instance != nullptr)
		do { delete (m_instance); (m_instance) = nullptr; } while (0);
}

SpaceWar::ShootPattenManager* SpaceWar::ShootPattenManager::m_instance;

SpaceWar::ShootPattenManager::ShootPattenManager()
{

}

SpaceWar::ShootPattenManager::~ShootPattenManager()
{

}
