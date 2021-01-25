#include "EnemyPlaneShooter.h"
#include "PhysicsWorldScene.h"
#include "MovePatternManager.h"
#include "Unit.h"
#include "EnemyPlaneFive.h"
#include "Region.h"
#include "Box2D/Box2D.h"
#include "PlayerPlaneManager.h"
#include "PlayerPlane.h"
#include "EnemyPlaneOne.h"
#include "EnemyPlaneTwo.h"
#include "EnemyPlaneThree.h"
#include "ShootPattern.h"
#include "ShootPattenManager.h"
#include "EnemyPlaneFour.h"
using namespace std;
USING_NS_CC;
using namespace SpaceWar;


bool SpaceWar::EnemyPlaneShooter::init()
{
	Node::init();
	//加入到层里面
	auto layer = PhysicsWorldScene::getLayerSpr();
	layer->addChild(this);
	setEnemyPerCall(1);
	return true;
}

void SpaceWar::EnemyPlaneShooter::ShootANotShootingEnmeyPlane()
{
	//5个飞机选择随机化，阻尼随机化
	int random_plane = (rand() % 5) + 1;
	EnemyPlane* enemy_plane;
	float random_linear_damping = ((rand() % 100) + 1) / 100;
	for (int i = 0; i < getEnemPerCall(); i++)
	{
		Vec2 pos;
		Vec2 some_point;
		some_point = Region::GetRandPointInUpperLeftRight();
		Vec2 dest_pos = Region::Center::GetPoint(4, 4);
		if (PlayerPlaneManager::getInstance()->getPlayerPlaneAgent()->isValid()) {
			auto player = static_cast<PlayerPlane*>(PlayerPlaneManager::getInstance()->getPlayerPlaneAgent()->getSpaceObject());
			dest_pos = player->convertToWorldSpace(player->getMiddlePoint());
		}
		//飞机头方向
		auto plane_head_vec = dest_pos - some_point;

		//create a enemy_plane
		switch (random_plane) {
		case 1:
			enemy_plane = EnemyPlaneOne::create("EnemyPlaneOne");
			break;
		case 2:
			enemy_plane = EnemyPlaneTwo::create("EnemyPlaneTwo");

			break;
		case 3:
			enemy_plane = EnemyPlaneThree::create("EnemyPlaneThree");

			break;
		case 4:
			enemy_plane = EnemyPlaneFour::create("EnemyPlaneFour");

			break;
		case 5:
			enemy_plane = EnemyPlaneFive::create("EnemyPlaneFive");

			break;
		}

		/*set pos and angle。*/

		float twist_angle;
		//原向量
		auto origin_vec2 = enemy_plane->getSprayUnitVector();
		Vec3 origin_vec3 = Vec3(origin_vec2.x, origin_vec2.y, 0);
		//目标向量
		Vec3 dest_vec3 = Vec3(plane_head_vec.x, plane_head_vec.y, 0);

		//angle
		auto angle = Vec3::angle(origin_vec3, dest_vec3);
		//叉乘
		Vec3 result;
		Vec3::cross(origin_vec3, dest_vec3, &result);

		if (result.z > 0) {
			//逆时针转！
			twist_angle = angle;
		}
		else if (result.z < 0) {
			//顺时针转！
			twist_angle = -angle;
		}
		//set damping
		enemy_plane->GetBody()->SetLinearDamping(random_linear_damping);
		b2Body* body = enemy_plane->GetBody();
		body->SetTransform(Unit::Tob2Vec2(some_point), twist_angle);
		enemy_plane->synchronize();


		//set move Pattern
		enemy_plane->setMovePattern(MovePatternManager::getInstance()->getMovePatternThree(enemy_plane, 40000));
		//set shooting pattern
		enemy_plane->setShootBulletPattern(nullptr);
		//add to layer...
		Layer* layer = PhysicsWorldScene::getLayerSpr();
		layer->addChild(enemy_plane);
		enemy_plane->activate();
	}
}

void SpaceWar::EnemyPlaneShooter::ShootAShootingEnemyPlane()
{
	//5飞机选择随机化，3个发弹模式随机化，放置位置随机化，还有一个线速度阻尼随机化（0~0.5）
	EnemyPlane* enemy_plane;
	ShootPattern* shoot_pattern;
	int random_plane = (rand() % 5) + 1;
	int random_shoot = (rand() % 3) + 1;
	float random_linear_damping = ((rand() % 100) + 1) / 100;
	for (int i = 0; i < getEnemPerCall(); i++)
	{
		Vec2 pos;
		Vec2 some_point;
		some_point = Region::GetRandPointInUpperLeftRight();
		Vec2 dest_pos = Region::Center::GetPoint(4, 4);
		if (PlayerPlaneManager::getInstance()->getPlayerPlaneAgent()->isValid()) {
			auto player = static_cast<PlayerPlane*>(PlayerPlaneManager::getInstance()->getPlayerPlaneAgent()->getSpaceObject());
			dest_pos = player->convertToWorldSpace(player->getMiddlePoint());
		}
		//飞机头方向
		auto plane_head_vec = dest_pos - some_point;

		//create a enemy_plane

		switch (random_plane) {
		case 1:
			enemy_plane = EnemyPlaneOne::create("EnemyPlaneOne");
			break;
		case 2:
			enemy_plane = EnemyPlaneTwo::create("EnemyPlaneTwo");

			break;
		case 3:
			enemy_plane = EnemyPlaneThree::create("EnemyPlaneThree");

			break;
		case 4:
			enemy_plane = EnemyPlaneFour::create("EnemyPlaneFour");

			break;
		case 5:
			enemy_plane = EnemyPlaneFive::create("EnemyPlaneFive");

			break;
		}

		switch (random_shoot) {
		case 1:
			shoot_pattern = ShootPattenManager::getInstance()->getShootPatternOne(enemy_plane);
			break;
		case 2:
			shoot_pattern = ShootPattenManager::getInstance()->getShootPatternThree(enemy_plane);

			break;
		case 3:
			shoot_pattern = ShootPattenManager::getInstance()->getShootPatternFive(enemy_plane);

			break;
		}
		//set damping
		enemy_plane->GetBody()->SetLinearDamping(random_linear_damping);
		/*set pos and angle。*/

		float twist_angle;
		//原向量
		auto origin_vec2 = enemy_plane->getSprayUnitVector();
		Vec3 origin_vec3 = Vec3(origin_vec2.x, origin_vec2.y, 0);
		//目标向量
		Vec3 dest_vec3 = Vec3(plane_head_vec.x, plane_head_vec.y, 0);

		//angle
		auto angle = Vec3::angle(origin_vec3, dest_vec3);
		//叉乘
		Vec3 result;
		Vec3::cross(origin_vec3, dest_vec3, &result);

		if (result.z > 0) {
			//逆时针转！
			twist_angle = angle;
		}
		else if (result.z < 0) {
			//顺时针转！
			twist_angle = -angle;
		}

		b2Body* body = enemy_plane->GetBody();
		body->SetTransform(Unit::Tob2Vec2(some_point), twist_angle);
		enemy_plane->synchronize();


		//set move Pattern
		enemy_plane->setMovePattern(MovePatternManager::getInstance()->getMovePatternSpecialOne(enemy_plane));
		//set shooting pattern
		enemy_plane->setShootBulletPattern(shoot_pattern);
		//add to layer...
		Layer* layer = PhysicsWorldScene::getLayerSpr();
		layer->addChild(enemy_plane);
		enemy_plane->activate();

	}
}

SpaceWar::EnemyPlaneShooter* SpaceWar::EnemyPlaneShooter::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new EnemyPlaneShooter();
		if (m_instance != nullptr) {
			m_instance->init();
		}
	}
	return m_instance;
}

void SpaceWar::EnemyPlaneShooter::destroy()
{
	this->stopAllActions();
	this->removeFromParent();
	if (m_instance != nullptr)
		do { delete (m_instance); (m_instance) = nullptr; } while (0);
}

SpaceWar::EnemyPlaneShooter* SpaceWar::EnemyPlaneShooter::m_instance;

SpaceWar::EnemyPlaneShooter::EnemyPlaneShooter()
{

}

SpaceWar::EnemyPlaneShooter::~EnemyPlaneShooter()
{

}


