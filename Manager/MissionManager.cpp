#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "MissionManager.h"
#include "EnemyPlaneFive.h"
#include "GameTexture.h"
#include "Region.h"
#include "Unit.h"
#include "ShootPattern.h"
#include "MovePatternManager.h"
#include "PhysicsWorldScene.h"
#include "Mission.h"
#include "ShootPattenManager.h"
#include <vector>
#include <iterator>
#include "TestPlayerBullet.h"
#include "EnemyPlaneShooter.h"
#include "AstroidShooter.h"

using namespace std;
USING_NS_CC;
using namespace SpaceWar;


bool SpaceWar::MissionManager::init()
{
	return true;
}

SpaceWar::Mission* SpaceWar::MissionManager::getMission100(float start)
{
	Mission* miss = Mission::create();
	miss->setExecuteTime(start);
	miss->ExecuteMission = [](Mission* miss) {
		//////////////do sth..
		EnemyPlaneFive* plane = EnemyPlaneFive::create(string("EnemyPlaneFive"));

		//set some important traits..
		auto pos = Region::Up::GetPoint(4, 4);
		plane->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI);
		plane->synchronize();


		//set shooting pattern..
		plane->setShootBulletPattern(nullptr);

		//set move pattern..����ֱ��
		plane->setMovePattern(MovePatternManager::getInstance()->getMovePatternThree(plane, 10000));


		// temperarily saved
		miss->m_objects.push_back(plane);



		//������в��Ҽ�������
		float i = 0;
		Layer* layer = PhysicsWorldScene::getLayerSpr();
		for (auto elem : miss->m_objects) {
			layer->addChild(elem);
			elem->activateAfter(i);
		}




	};
	return miss;
}

SpaceWar::Mission* SpaceWar::MissionManager::getMission1(float start)
{
	Mission* miss = Mission::create();
	miss->setExecuteTime(start);
	miss->ExecuteMission = [](Mission* miss) {

		//////////////do sth..
		EnemyPlaneFive* plane = EnemyPlaneFive::create(string("EnemyPlaneFive"));

		//set some important traits..
		auto pos = Region::Center::GetPoint(4, 4);
		plane->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI);
		plane->synchronize();


		//set shooting pattern..
		plane->setShootBulletPattern(nullptr);

		//set move pattern..����ֱ��
		plane->setMovePattern(MovePatternManager::getInstance()->getMovePatternOne(plane, 1200, 100));


		// temperarily saved
		miss->m_objects.push_back(plane);
		miss->m_objects.push_back(plane->clone());



		//������в��Ҽ�������
		float i = 0;
		Layer* layer = PhysicsWorldScene::getLayerSpr();
		for (auto elem : miss->m_objects) {
			layer->addChild(elem);
			i += 2;
			elem->activateAfter(i);
		}
	};
	return miss;
}

//4�����ŷɻ���Up�������½�
SpaceWar::Mission* SpaceWar::MissionManager::getMission2(float start)
{
	Mission* miss = Mission::create();
	miss->setExecuteTime(start);
	miss->ExecuteMission = [](Mission* miss) {
		EnemyPlaneFive* plane = EnemyPlaneFive::create(string("EnemyPlaneFive"));

		//set some important traits..
		auto pos = Region::Up::GetPoint(4, 2);
		plane->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI);
		plane->synchronize();

		//set shooting pattern..
		plane->setShootBulletPattern(nullptr);

		//set move pattern..����ֱ��
		plane->setMovePattern(MovePatternManager::getInstance()->getMovePatternOne(plane, 100, 10));



		//�ڶ����ɻ�
		auto sec = plane->clone();
		pos = Vec2(Region::Up::GetPoint(4, 3));
		sec->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI);
		sec->setPosition(pos);


		//�������ɻ�
		auto third = plane->clone();
		pos = Vec2(Region::Up::GetPoint(4, 4));
		third->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI);
		third->setPosition(pos);

		//���ĸ��ɻ�
		auto fourth = plane->clone();
		pos = Vec2(Region::Up::GetPoint(4, 5));
		fourth->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI);
		fourth->setPosition(pos);
		// 
		// 
		//������ɻ�
		auto fifth = plane->clone();
		pos = Vec2(Region::Up::GetPoint(4, 6));
		fifth->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI);
		fifth->setPosition(pos);


		// save it
		miss->m_objects.push_back(sec);
		miss->m_objects.push_back(third);
		miss->m_objects.push_back(fourth);
		miss->m_objects.push_back(fifth);
		miss->m_objects.push_back(plane);

		//������в��Ҽ�������
		float i = 0;
		Layer* layer = PhysicsWorldScene::getLayerSpr();
		for (auto elem : miss->m_objects) {
			layer->addChild(elem);
			//ȫ��ͬʱ����
			elem->activateAfter(i);
		}

		//////do sth..
	};
	return miss;
}

SpaceWar::Mission* SpaceWar::MissionManager::getMissionMakePlane1(float start,float interval,int calls)
{

	Mission* miss = Mission::create();
	miss->setExecuteTime(start);
	miss->ExecuteMission = [=](Mission* miss) {
		EnemyPlaneShooter::getInstance()->schedule(CC_CALLBACK_0(EnemyPlaneShooter::ShootANotShootingEnmeyPlane, EnemyPlaneShooter::getInstance()),
			interval,
			calls,
			0,
			string("ShootANotShootingEnmeyPlane"));

	};
	return miss;
}



SpaceWar::Mission* SpaceWar::MissionManager::getMissionMakePlane2(float start,float interval,int calls)
{
	Mission* miss = Mission::create();
	miss->setExecuteTime(start);
	miss->ExecuteMission = [=](Mission* miss) {
		EnemyPlaneShooter::getInstance()->schedule(CC_CALLBACK_0(EnemyPlaneShooter::ShootAShootingEnemyPlane, EnemyPlaneShooter::getInstance()),
			interval,
			calls,
			0,
			string("ShootAShootingEnemyPlane"));

	};
	return miss;
}



SpaceWar::Mission* SpaceWar::MissionManager::getMissionMakeAsdroid(float start,float interval,int calls)
{
	Mission* miss = Mission::create();
	miss->setExecuteTime(start);
	miss->ExecuteMission = [=](Mission* miss) {
		AstroidShooter::getInstance()->schedule(CC_CALLBACK_0(AstroidShooter::shootAstroid, AstroidShooter::getInstance()),
			interval,
			calls,//
			0,
			string("shootAstroid"));

	};
	return miss;
}

// 
// SpaceWar::Mission* SpaceWar::MissionManager::getMission3(float start)
// {
// 	Mission* miss = Mission::create();
// 
// 	miss->ExecuteMissionPrepare = [](Mission* miss) {
// 
// 		//////////////////do sth..
// 		EnemyPlaneFive* plane = EnemyPlaneFive::create("EnemyPlaneFive");
// 
// 		//set some important traits..
// 		auto pos = Region::Up::GetPoint(4, 2);
// 		plane->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI);
// 		plane->synchronize();
// 		//set shooting pattern..
// 		plane->setShootBulletPattern(nullptr);
// 
// 		//set move pattern..
// 		plane->setMovePattern(MovePatternManager::getInstance()->getMovePatternSeven(plane, Vec2(0, 1)));
// 
// 
// 		auto sec = plane->clone();
// 		pos = Vec2(Region::Up::GetPoint(4, 3));
// 		sec->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI);
// 		sec->synchronize();
// 
// 
// 		//////////////////do sth..
// 
// 		//save the objects...
// 		miss->m_objects.push_back(sec);
// 		miss->m_objects.push_back(plane);
// 
// 		//add to layer
// 		Layer* layer = PhysicsWorldScene::getLayerSpr();
// 		for (auto elem : miss->m_objects)
// 			layer->addChild(elem);
// 
// 	};
// 
// 	miss->ExecuteMission = [](Mission* miss) {
// 		/////do sth...
// 		float i = 1;
// 		//ͬʱ����
// 		for (auto elem : miss->m_objects)
// 			elem->activateAfter(i);
// 
// 		/////do sth...
// 
// 	};
// 
// 
// 	miss->setExecuteTime(start);
// 	return miss;
// }
// 
// // n�����ŷɻ���Left��ֱ�ߺ���ͷ
// SpaceWar::Mission* SpaceWar::MissionManager::getMission14(float start)
// {
// 	Mission* miss = Mission::create();
// 
// 	miss->ExecuteMissionPrepare = [](Mission* miss) {
// 
// 		//////////////////do sth..
// 		EnemyPlaneFive* plane = EnemyPlaneFive::create(GameTexture::getInstance()->getTextureRelativePath("EnemyPlaneFive"));
// 
// 		//set some important traits..
// 		auto pos = Region::Left::GetPoint(6, 4);
// 		plane->setPosition(pos);
// 		plane->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI / 2);
// 
// 		//set shooting pattern..
// 		plane->setShootBulletPattern(nullptr);
// 
// 		//set move pattern..
// 		plane->setMovePattern(MovePatternManager::getInstance()->getMovePatternSeven(plane, Vec2(-1, 0)));
// 
// 
// 
// 
// 
// 		//////////////////do sth..
// 
// 		//save the objects...
// 		miss->m_objects.push_back(plane->clone());
// 		miss->m_objects.push_back(plane->clone());
// 		miss->m_objects.push_back(plane->clone());
// 		miss->m_objects.push_back(plane->clone());
// 		miss->m_objects.push_back(plane->clone());
// 		miss->m_objects.push_back(plane);
// 
// 		//add to layer
// 		Layer* layer = PhysicsWorldScene::getLayerSpr();
// 		for (auto elem : miss->m_objects)
// 			layer->addChild(elem);
// 
// 	};
// 
// 	miss->ExecuteMission = [](Mission* miss) {
// 		/////do sth...
// 		float i = 0;
// 		//ͬʱ����
// 		for (auto elem : miss->m_objects)
// 		{
// 			i += 0.5;
// 			elem->activateAfter(i);
// 
// 		}
// 
// 		/////do sth...
// 
// 	};
// 
// 
// 	miss->setExecuteTime(start);
// 	return miss;
// }
// 
// SpaceWar::Mission* SpaceWar::MissionManager::getMission15(float start)
// {
// 	Mission* miss = Mission::create();
// 
// 	miss->ExecuteMissionPrepare = [](Mission* miss) {
// 
// 		//////////////////do sth..
// 		EnemyPlaneFive* plane = EnemyPlaneFive::create(GameTexture::getInstance()->getTextureRelativePath("EnemyPlaneFive"));
// 
// 		//set some important traits..
// 		auto pos = Region::Right::GetPoint(2, 4);
// 		plane->setPosition(pos);
// 		plane->GetBody()->SetTransform(Unit::Tob2Vec2(pos), -Unit::PI / 2);
// 
// 		//set shooting pattern..
// 		plane->setShootBulletPattern(nullptr);
// 
// 		//set move pattern..
// 		plane->setMovePattern(MovePatternManager::getInstance()->getMovePatternSeven(plane, Vec2(1, 0)));
// 
// 
// 
// 
// 
// 		//////////////////do sth..
// 
// 		//save the objects...
// 		miss->m_objects.push_back(plane->clone());
// 		miss->m_objects.push_back(plane->clone());
// 		miss->m_objects.push_back(plane->clone());
// 		miss->m_objects.push_back(plane->clone());
// 		miss->m_objects.push_back(plane->clone());
// 		miss->m_objects.push_back(plane);
// 
// 		//add to layer
// 		Layer* layer = PhysicsWorldScene::getLayerSpr();
// 		for (auto elem : miss->m_objects)
// 			layer->addChild(elem);
// 
// 	};
// 
// 	miss->ExecuteMission = [](Mission* miss) {
// 		/////do sth...
// 		float i = 0;
// 		//ͬʱ����
// 		for (auto elem : miss->m_objects)
// 		{
// 			i += 1;
// 			elem->activateAfter(i);
// 
// 		}
// 
// 		/////do sth...
// 
// 	};
// 
// 
// 	miss->setExecuteTime(start);
// 	return miss;
// }
// 
// SpaceWar::Mission* SpaceWar::MissionManager::getMission4(float start)
// {
// 	Mission* miss = Mission::create();
// 
// 	miss->ExecuteMissionPrepare = [](Mission* miss) {
// 
// 		//////////////////do sth..
// 		EnemyPlaneFive* plane = EnemyPlaneFive::create(GameTexture::getInstance()->getTextureRelativePath("EnemyPlaneFive"));
// 
// 		//set some important traits..
// 		auto pos = Region::Up::GetPoint(6, 4);
// 		plane->setPosition(pos);
// 		plane->GetBody()->SetTransform(Unit::Tob2Vec2(pos), 0);
// 
// 		//set shooting pattern..
// 		plane->setShootBulletPattern(ShootPattenManager::getInstance()->getShootPattern(plane));
// 
// 		//set move pattern..
// 		plane->setMovePattern(MovePatternManager::getInstance()->getMovePatternEight(plane, Vec2(1, 0)));
// 
// 		// 		//����λ�úͽǶ��������һ��..
// 		// 		this->setPosition(pos);
// 		// 		this->setRotation(-1 * CC_RADIANS_TO_DEGREES(plane->GetBody()->GetAngle()));
// 
// 		auto sec = plane->clone();
// 		pos = Vec2(Region::Up::GetPoint(5, 4));
// 		sec->GetBody()->SetTransform(Unit::Tob2Vec2(pos), 0);
// 		sec->setPosition(pos);
// 
// 
// 		//////////////////do sth..
// 
// 		//save the objects...
// 		miss->m_objects.push_back(sec);
// 		miss->m_objects.push_back(plane);
// 
// 		//add to layer
// 		Layer* layer = PhysicsWorldScene::getLayerSpr();
// 		for (auto elem : miss->m_objects)
// 			layer->addChild(elem);
// 
// 	};
// 
// 	miss->ExecuteMission = [](Mission* miss) {
// 		/////do sth...
// 		float i = 1;
// 		//ͬʱ����
// 		for (auto elem : miss->m_objects)
// 			elem->activateAfter(i);
// 
// 		/////do sth...
// 
// 	};
// 
// 
// 	miss->setExecuteTime(start);
// 	return miss;
// }
// 
// SpaceWar::Mission* SpaceWar::MissionManager::getMission12(float start)
// {
// 	Mission* miss = Mission::create();
// 
// 	miss->ExecuteMissionPrepare = [](Mission* miss) {
// 
// 		//////////////////do sth..
// 		EnemyPlaneFive* plane = EnemyPlaneFive::create(GameTexture::getInstance()->getTextureRelativePath("EnemyPlaneFive"));
// 
// 		//set some important traits..
// 		auto pos = Region::UpperLeft::GetPoint(4, 4);
// 		plane->setPosition(pos);
// 		plane->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI / 4);
// 
// 		//set shooting pattern..
// 		plane->setShootBulletPattern(nullptr);
// 
// 		//set move pattern..
// 		plane->setMovePattern(MovePatternManager::getInstance()->getMovePatternThree(plane, 30000));
// 
// 
// 		//////////////////do sth..
// 
// 		//save the objects...
// 		miss->m_objects.push_back(plane->clone());
// 		miss->m_objects.push_back(plane->clone());
// 		miss->m_objects.push_back(plane);
// 
// 		//add to layer
// 		Layer* layer = PhysicsWorldScene::getLayerSpr();
// 		for (auto elem : miss->m_objects)
// 			layer->addChild(elem);
// 
// 	};
// 
// 	miss->ExecuteMission = [](Mission* miss) {
// 		/////do sth...
// 		float i = 1;
// 		//ͬʱ����
// 		for (auto elem : miss->m_objects)
// 		{
// 			elem->activateAfter(i++);
// 
// 		}
// 
// 		/////do sth...
// 
// 	};
// 
// 
// 	miss->setExecuteTime(start);
// 	return miss;
// }
// 
// SpaceWar::Mission* SpaceWar::MissionManager::getMission13(float start)
// {
// 	Mission* miss = Mission::create();
// 
// 	miss->ExecuteMissionPrepare = [](Mission* miss) {
// 
// 		//////////////////do sth..
// 		EnemyPlaneFive* plane = EnemyPlaneFive::create(GameTexture::getInstance()->getTextureRelativePath("EnemyPlaneFive"));
// 
// 		//set some important traits..
// 		auto pos = Region::UpperRight::GetPoint(4, 4);
// 		plane->setPosition(pos);
// 		plane->GetBody()->SetTransform(Unit::Tob2Vec2(pos), -Unit::PI / 4);
// 
// 		//set shooting pattern..
// 		plane->setShootBulletPattern(nullptr);
// 
// 		//set move pattern..
// 		plane->setMovePattern(MovePatternManager::getInstance()->getMovePatternThree(plane, 30000));
// 
// 
// 		//////////////////do sth..
// 
// 		//save the objects...
// 		miss->m_objects.push_back(plane->clone());
// 		miss->m_objects.push_back(plane->clone());
// 		miss->m_objects.push_back(plane);
// 
// 		//add to layer
// 		Layer* layer = PhysicsWorldScene::getLayerSpr();
// 		for (auto elem : miss->m_objects)
// 			layer->addChild(elem);
// 
// 	};
// 
// 	miss->ExecuteMission = [](Mission* miss) {
// 		/////do sth...
// 		float i = 1;
// 		//ͬʱ����
// 		for (auto elem : miss->m_objects)
// 		{
// 
// 			elem->activateAfter(i++);
// 
// 		}
// 
// 		/////do sth...
// 
// 	};
// 
// 
// 	miss->setExecuteTime(start);
// 	return miss;
// 
// }
// 
// SpaceWar::Mission* SpaceWar::MissionManager::getMission111(float start)
// {
// 	Mission* miss = Mission::create();
// 
// 	miss->ExecuteMissionPrepare = [](Mission* miss) {
// 
// 		//////////////do sth..
// 		EnemyPlaneFive* plane = EnemyPlaneFive::create("EnemyPlaneFive");
// 
// 		//set some important traits..
// 		auto pos = Region::Left::GetPoint(4, 4);
// 		plane->GetBody()->SetTransform(Unit::Tob2Vec2(pos), -Unit::PI / 2);
// 		plane->synchronize();
// 		//set shooting pattern..
// 		plane->setShootBulletPattern(ShootPattenManager::getInstance()->getShootPatternFive(plane));
// 
// 		//set move pattern..����ֱ��
// 		plane->setMovePattern(MovePatternManager::getInstance()->getMovePatternSix(plane));
// 
// 
// 
// 
// 		// save it
// 		miss->m_objects.push_back(plane);
// 
// 
// 
// 
// 		//�������
// 		Layer* layer = PhysicsWorldScene::getLayerSpr();
// 		for (auto elem : miss->m_objects)
// 			layer->addChild(elem);
// 
// 
// 		//////do sth..
// 
// 	};
// 
// 	miss->ExecuteMission = [](Mission* miss) {
// 		/////do sth...
// 		float i = 0;
// 		//ͬʱ����
// 		for (auto elem : miss->m_objects)
// 			elem->activateAfter(i);
// 
// 		/////do sth...
// 
// 	};
// 
// 
// 	miss->setExecuteTime(start);
// 
// 	return miss;
// }
// 
// /*
// 5�����ŷɻ���Left��˳���������
// 
// */
// SpaceWar::Mission* SpaceWar::MissionManager::getMission7(float start)
// {
// 	Mission* miss = Mission::create();
// 
// 	miss->ExecuteMissionPrepare = [](Mission* miss) {
// 
// 		//////////////do sth..
// 		EnemyPlaneFive* plane = EnemyPlaneFive::create("EnemyPlaneFive");
// 
// 		//set some important traits..
// 		auto pos = Region::Left::GetPoint(2, 4);
// 		plane->setPosition(pos);
// 		plane->GetBody()->SetTransform(Unit::Tob2Vec2(pos), -Unit::PI / 2);
// 		plane->synchronize();
// 		//set shooting pattern..
// 		plane->setShootBulletPattern(ShootPattenManager::getInstance()->getShootPattern(plane));
// 
// 		//set move pattern..����ֱ��
// 		plane->setMovePattern(MovePatternManager::getInstance()->getMovePattern(plane, 10, 20));
// 
// 		//add to layer and save it..
// 		miss->m_objects.push_back(plane);
// 
// 		//�ڶ����ɻ�
// 		auto sec = plane->clone();
// 		pos = Vec2(Region::Left::GetPoint(3, 4));
// 		sec->GetBody()->SetTransform(Unit::Tob2Vec2(pos), -Unit::PI / 2);
// 		sec->synchronize();
// 		miss->m_objects.push_back(sec);
// 
// 		//�������ɻ�
// 		auto third = plane->clone();
// 		pos = Vec2(Region::Left::GetPoint(4, 4));
// 		third->GetBody()->SetTransform(Unit::Tob2Vec2(pos), -Unit::PI / 2);
// 		third->synchronize();
// 		miss->m_objects.push_back(third);
// 
// 		//���ĸ��ɻ�
// 		auto fourth = plane->clone();
// 		pos = Vec2(Region::Left::GetPoint(5, 4));
// 		fourth->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI / 2);
// 		fourth->synchronize();
// 		miss->m_objects.push_back(fourth);
// 		// 
// 		// 
// 		//������ɻ�
// 		auto fifth = plane->clone();
// 		pos = Vec2(Region::Left::GetPoint(6, 4));
// 		fifth->GetBody()->SetTransform(Unit::Tob2Vec2(pos), -Unit::PI / 2);
// 		fifth->synchronize();
// 		miss->m_objects.push_back(fifth);
// 
// 
// 		//�������
// 		Layer* layer = PhysicsWorldScene::getLayerSpr();
// 		for (auto elem : miss->m_objects)
// 			layer->addChild(elem);
// 
// 
// 		//////do sth..
// 
// 	};
// 
// 	miss->ExecuteMission = [](Mission* miss) {
// 		/////do sth...
// 		float i = 1;
// 		//ͬʱ����
// 		for (auto elem : miss->m_objects)
// 			elem->activateAfter(i);
// 
// 		/////do sth...
// 
// 	};
// 
// 
// 	miss->setExecuteTime(start);
// 
// 	return miss;
// }
// 
// SpaceWar::Mission* SpaceWar::MissionManager::getMission9(float start)
// {
// 	Mission* miss = Mission::create();
// 
// 	miss->ExecuteMissionPrepare = [](Mission* miss) {
// 
// 		//////////////do sth..
// 		EnemyPlaneFive* plane = EnemyPlaneFive::create("EnemyPlaneFive");
// 
// 		//set some important traits..
// 		auto pos = Region::Right::GetPoint(2, 4);
// 		plane->setPosition(pos);
// 		plane->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI / 2);
// 
// 		//set shooting pattern..
// 		plane->setShootBulletPattern(ShootPattenManager::getInstance()->getShootPattern(plane));
// 
// 		//set move pattern..����ֱ��
// 		plane->setMovePattern(MovePatternManager::getInstance()->getMovePattern(plane, 10, 20));
// 
// 		//add to layer and save it..
// 		miss->m_objects.push_back(plane);
// 
// 		//�ڶ����ɻ�
// 		auto sec = plane->clone();
// 		pos = Vec2(Region::Right::GetPoint(3, 4));
// 		sec->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI / 2);
// 		sec->synchronize();
// 		miss->m_objects.push_back(sec);
// 
// 		//�������ɻ�
// 		auto third = plane->clone();
// 		pos = Vec2(Region::Right::GetPoint(4, 4));
// 		third->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI / 2);
// 		third->synchronize();
// 		miss->m_objects.push_back(third);
// 
// 		//���ĸ��ɻ�
// 		auto fourth = plane->clone();
// 		pos = Vec2(Region::Right::GetPoint(5, 4));
// 		fourth->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI / 2);
// 		fourth->synchronize();
// 		miss->m_objects.push_back(fourth);
// 		// 
// 		// 
// 		//������ɻ�
// 		auto fifth = plane->clone();
// 		pos = Vec2(Region::Right::GetPoint(6, 4));
// 		fifth->GetBody()->SetTransform(Unit::Tob2Vec2(pos), -Unit::PI / 2);
// 		fifth->setPosition(pos);
// 		miss->m_objects.push_back(fifth);
// 
// 
// 		//�������
// 		Layer* layer = PhysicsWorldScene::getLayerSpr();
// 		for (auto elem : miss->m_objects)
// 			layer->addChild(elem);
// 
// 
// 		//////do sth..
// 
// 	};
// 
// 	miss->ExecuteMission = [](Mission* miss) {
// 		/////do sth...
// 		float i = 1;
// 		//ͬʱ����
// 		for (auto elem : miss->m_objects)
// 			elem->activateAfter(i);
// 
// 		/////do sth...
// 
// 	};
// 
// 
// 	miss->setExecuteTime(start);
// 
// 	return miss;
// }
// 
// SpaceWar::Mission* SpaceWar::MissionManager::getMission10(float start)
// {
// 	Mission* miss = Mission::create();
// 
// 	miss->ExecuteMissionPrepare = [](Mission* miss) {
// 
// 		//////////////do sth..
// 		EnemyPlaneFive* plane = EnemyPlaneFive::create(GameTexture::getInstance()->getTextureRelativePath("EnemyPlaneFive"));
// 
// 		//set some important traits..
// 		auto pos = Region::Left::GetPoint(2, 4);
// 		plane->setPosition(pos);
// 		plane->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI / 2);
// 
// 		//set shooting pattern..
// 		plane->setShootBulletPattern(nullptr);
// 
// 		//set move pattern..����ֱ��
// 		plane->setMovePattern(MovePatternManager::getInstance()->getMovePattern(plane, 1500, 200));
// 
// 		//add to layer and save it..
// 		miss->m_objects.push_back(plane);
// 
// 		//�ڶ����ɻ�
// 		auto sec = plane->clone();
// 		pos = Vec2(Region::Left::GetPoint(3, 4));
// 		sec->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI / 2);
// 		sec->setPosition(pos);
// 		miss->m_objects.push_back(sec);
// 
// 		//�������ɻ�
// 		auto third = plane->clone();
// 		pos = Vec2(Region::Left::GetPoint(4, 4));
// 		third->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI / 2);
// 		third->setPosition(pos);
// 		miss->m_objects.push_back(third);
// 
// 		//���ĸ��ɻ�
// 		auto fourth = plane->clone();
// 		pos = Vec2(Region::Left::GetPoint(5, 4));
// 		fourth->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI / 2);
// 		fourth->setPosition(pos);
// 		miss->m_objects.push_back(fourth);
// 		// 
// 		// 
// 		//������ɻ�
// 		auto fifth = plane->clone();
// 		pos = Vec2(Region::Left::GetPoint(6, 4));
// 		fifth->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI / 2);
// 		fifth->setPosition(pos);
// 		miss->m_objects.push_back(fifth);
// 
// 
// 		//�������
// 		Layer* layer = PhysicsWorldScene::getLayerSpr();
// 		for (auto elem : miss->m_objects)
// 			layer->addChild(elem);
// 
// 
// 		//////do sth..
// 
// 	};
// 
// 	miss->ExecuteMission = [](Mission* miss) {
// 		/////do sth...
// 		float i = 1;
// 		//ͬʱ����
// 		for (auto elem : miss->m_objects)
// 			elem->activateAfter(i++);
// 
// 		/////do sth...
// 
// 	};
// 
// 
// 	miss->setExecuteTime(start);
// 
// 	return miss;
// }
// 
// SpaceWar::Mission* SpaceWar::MissionManager::getMission11(float start)
// {
// 	Mission* miss = Mission::create();
// 
// 	miss->ExecuteMissionPrepare = [](Mission* miss) {
// 
// 		//////////////do sth..
// 		EnemyPlaneFive* plane = EnemyPlaneFive::create(GameTexture::getInstance()->getTextureRelativePath("EnemyPlaneFive"));
// 
// 		//set some important traits..
// 		auto pos = Region::Right::GetPoint(2, 4);
// 		plane->setPosition(pos);
// 		plane->GetBody()->SetTransform(Unit::Tob2Vec2(pos), -Unit::PI / 2);
// 
// 		//set shooting pattern..
// 		plane->setShootBulletPattern(ShootPattenManager::getInstance()->getShootPattern(plane));
// 
// 		//set move pattern..����ֱ��
// 		plane->setMovePattern(MovePatternManager::getInstance()->getMovePattern(plane, 1500, 200));
// 
// 		//add to layer and save it..
// 		miss->m_objects.push_back(plane);
// 
// 		//�ڶ����ɻ�
// 		auto sec = plane->clone();
// 		pos = Vec2(Region::Right::GetPoint(3, 4));
// 		sec->GetBody()->SetTransform(Unit::Tob2Vec2(pos), -Unit::PI / 2);
// 		sec->setPosition(pos);
// 		miss->m_objects.push_back(sec);
// 
// 		//�������ɻ�
// 		auto third = plane->clone();
// 		pos = Vec2(Region::Right::GetPoint(4, 4));
// 		third->GetBody()->SetTransform(Unit::Tob2Vec2(pos), -Unit::PI / 2);
// 		third->setPosition(pos);
// 		miss->m_objects.push_back(third);
// 
// 		//���ĸ��ɻ�
// 		auto fourth = plane->clone();
// 		pos = Vec2(Region::Right::GetPoint(5, 4));
// 		fourth->GetBody()->SetTransform(Unit::Tob2Vec2(pos), -Unit::PI / 2);
// 		fourth->setPosition(pos);
// 		miss->m_objects.push_back(fourth);
// 		// 
// 		// 
// 		//������ɻ�
// 		auto fifth = plane->clone();
// 		pos = Vec2(Region::Right::GetPoint(6, 4));
// 		fifth->GetBody()->SetTransform(Unit::Tob2Vec2(pos), -Unit::PI / 2);
// 		fifth->setPosition(pos);
// 		miss->m_objects.push_back(fifth);
// 
// 
// 		//�������
// 		Layer* layer = PhysicsWorldScene::getLayerSpr();
// 		for (auto elem : miss->m_objects)
// 			layer->addChild(elem);
// 
// 
// 		//////do sth..
// 
// 	};
// 
// 	miss->ExecuteMission = [](Mission* miss) {
// 		/////do sth...
// 		float i = 1;
// 		//ͬʱ����
// 		std::vector<SpaceObject*>::reverse_iterator pos;
// 		for (pos = miss->m_objects.rbegin(); pos != miss->m_objects.rend(); pos++)
// 			(*pos)->activateAfter(i++);
// 
// 		/////do sth...
// 
// 	};
// 
// 
// 	miss->setExecuteTime(start);
// 
// 	return miss;
// 
// 
// 
// }
// 
// SpaceWar::Mission* SpaceWar::MissionManager::getMission5(float start)
// {
// 	Mission* miss = Mission::create();
// 
// 	miss->ExecuteMissionPrepare = [](Mission* miss) {
// 
// 		//////////////////do sth..
// 		Vec2 pos;
// 
// 		//��һ���ɻ�
// 		EnemyPlaneFive* plane = EnemyPlaneFive::create(("EnemyPlaneFive"));
// 
// 		//set some important traits..
// 		pos = Region::Left::GetPoint(4, 4);
// 		plane->setPosition(pos);
// 		plane->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI / 2);
// 
// 		//set shooting pattern..
// 		plane->setShootBulletPattern(ShootPattenManager::getInstance()->getShootPattern(plane));
// 
// 		//set move pattern..
// 		plane->setMovePattern(MovePatternManager::getInstance()->getMovePatternEight(plane, Vec2(-1, 0)));
// 
// 
// 
// 
// 		//�ڶ����ɻ�
// 		EnemyPlaneFive* sec = EnemyPlaneFive::create(GameTexture::getInstance()->getTextureRelativePath("EnemyPlaneFive"));
// 
// 		//set some important traits..
// 		pos = Region::Right::GetPoint(4, 4);
// 		sec->setPosition(pos);
// 		sec->GetBody()->SetTransform(Unit::Tob2Vec2(pos), -Unit::PI / 2);
// 
// 		//set shooting pattern..
// 		sec->setShootBulletPattern(ShootPattenManager::getInstance()->getShootPattern(sec));
// 
// 		//set move pattern..
// 		sec->setMovePattern(MovePatternManager::getInstance()->getMovePatternSeven(sec, Vec2(1, 0)));
// 
// 
// 
// 		//////////////////do sth..
// 
// 		//save the objects...
// 		miss->m_objects.push_back(plane);
// 		miss->m_objects.push_back(sec);
// 
// 		//add to layer
// 		Layer* layer = PhysicsWorldScene::getLayerSpr();
// 		for (auto elem : miss->m_objects)
// 			layer->addChild(elem);
// 
// 	};
// 
// 	miss->ExecuteMission = [](Mission* miss) {
// 		/////do sth...
// 		float i = 0;
// 		//ͬʱ����
// 		for (auto elem : miss->m_objects)
// 			elem->activateAfter(i);
// 
// 		/////do sth...
// 
// 	};
// 
// 
// 	miss->setExecuteTime(start);
// 	return miss;
// }
// 
// 
// SpaceWar::Mission* SpaceWar::MissionManager::getMission6(float start)
// {
// 	Mission* miss = Mission::create();
// 
// 	miss->ExecuteMissionPrepare = [](Mission* miss) {
// 
// 		//////////////do sth..
// 		EnemyPlaneFive* plane = EnemyPlaneFive::create("EnemyPlaneFive");
// 
// 		//set some important traits..
// 		auto pos = Region::Up::GetPoint(4, 2);
// 		plane->GetBody()->SetTransform(Unit::Tob2Vec2(pos), Unit::PI);
// 		plane->synchronize();
// 
// 		//set shooting pattern..
// 		plane->setShootBulletPattern(ShootPattenManager::getInstance()->getShootPattern(plane));
// 
// 		//set move pattern..����ֱ��
// 		plane->setMovePattern(MovePatternManager::getInstance()->getMovePattern(plane, 600, 200));
// 
// 
// 
// 		//add to layer and save it..
// 		miss->m_objects.push_back(plane);
// 
// 		//�ڶ����ɻ�
// 		auto sec = plane->clone();
// 		pos = Vec2(Region::Up::GetPoint(4, 3));
// 		sec->GetBody()->SetTransform(Unit::Tob2Vec2(pos), 0);
// 		sec->setPosition(pos);
// 		miss->m_objects.push_back(sec);
// 
// 		//�������ɻ�
// 		auto third = plane->clone();
// 		pos = Vec2(Region::Up::GetPoint(4, 4));
// 		third->GetBody()->SetTransform(Unit::Tob2Vec2(pos), 0);
// 		third->setPosition(pos);
// 		miss->m_objects.push_back(third);
// 
// 		//���ĸ��ɻ�
// 		auto fourth = plane->clone();
// 		pos = Vec2(Region::Up::GetPoint(4, 5));
// 		fourth->GetBody()->SetTransform(Unit::Tob2Vec2(pos), 0);
// 		fourth->setPosition(pos);
// 		miss->m_objects.push_back(fourth);
// 		// 
// 		// 
// 				//������ɻ�
// 		auto fifth = plane->clone();
// 		pos = Vec2(Region::Up::GetPoint(4, 6));
// 		fifth->GetBody()->SetTransform(Unit::Tob2Vec2(pos), 0);
// 		fifth->setPosition(pos);
// 		miss->m_objects.push_back(fifth);
// 
// 
// 		//�������
// 		Layer* layer = PhysicsWorldScene::getLayerSpr();
// 		for (auto elem : miss->m_objects)
// 			layer->addChild(elem);
// 
// 
// 		//////do sth..
// 
// 	};
// 
// 	miss->ExecuteMission = [](Mission* miss) {
// 		/////do sth...
// 		float i = 1;
// 		//ͬʱ����
// 		for (auto elem : miss->m_objects)
// 			elem->activateAfter(i++);
// 
// 		/////do sth...
// 
// 	};
// 
// 
// 	miss->setExecuteTime(start);
// 
// 	return miss;
// }
// 
// SpaceWar::Mission* SpaceWar::MissionManager::getMission8(float start)
// {
// 	Mission* miss = Mission::create();
// 
// 	miss->ExecuteMissionPrepare = [](Mission* miss) {
// 
// 		//////////////do sth..
// 		EnemyPlaneFive* plane = EnemyPlaneFive::create(GameTexture::getInstance()->getTextureRelativePath("EnemyPlaneFive"));
// 
// 		//set some important traits..
// 		auto pos = Region::Up::GetPoint(4, 2);
// 		plane->setPosition(pos);
// 		plane->GetBody()->SetTransform(Unit::Tob2Vec2(pos), 0);
// 
// 		//set shooting pattern..
// 		plane->setShootBulletPattern(ShootPattenManager::getInstance()->getShootPattern(plane));
// 
// 		//set move pattern..����ֱ��
// 		plane->setMovePattern(MovePatternManager::getInstance()->getMovePattern(plane, 1500, 200));
// 
// 		// 
// 		// 		//����λ�úͽǶ��������һ��..
// 		// 		this->setPosition(pos);
// 		// 		this->setRotation(-1 * CC_RADIANS_TO_DEGREES(plane->GetBody()->GetAngle()));
// 
// 				//add to layer and save it..
// 		miss->m_objects.push_back(plane);
// 
// 		//�ڶ����ɻ�
// 		auto sec = plane->clone();
// 		pos = Vec2(Region::Up::GetPoint(4, 3));
// 		sec->GetBody()->SetTransform(Unit::Tob2Vec2(pos), 0);
// 		sec->setPosition(pos);
// 		miss->m_objects.push_back(sec);
// 
// 		//�������ɻ�
// 		auto third = plane->clone();
// 		pos = Vec2(Region::Up::GetPoint(4, 4));
// 		third->GetBody()->SetTransform(Unit::Tob2Vec2(pos), 0);
// 		third->setPosition(pos);
// 		miss->m_objects.push_back(third);
// 
// 		//���ĸ��ɻ�
// 		auto fourth = plane->clone();
// 		pos = Vec2(Region::Up::GetPoint(4, 5));
// 		fourth->GetBody()->SetTransform(Unit::Tob2Vec2(pos), 0);
// 		fourth->setPosition(pos);
// 		miss->m_objects.push_back(fourth);
// 		// 
// 		// 
// 				//������ɻ�
// 		auto fifth = plane->clone();
// 		pos = Vec2(Region::Up::GetPoint(4, 6));
// 		fifth->GetBody()->SetTransform(Unit::Tob2Vec2(pos), 0);
// 		fifth->setPosition(pos);
// 		miss->m_objects.push_back(fifth);
// 
// 
// 		//�������
// 		Layer* layer = PhysicsWorldScene::getLayerSpr();
// 		for (auto elem : miss->m_objects)
// 			layer->addChild(elem);
// 
// 
// 		//////do sth..
// 
// 	};
// 
// 	miss->ExecuteMission = [](Mission* miss) {
// 		/////do sth...
// 		float i = 1;
// 		//ͬʱ����
// 		std::vector<SpaceObject*>::reverse_iterator pos;
// 		for (pos = miss->m_objects.rbegin(); pos != miss->m_objects.rend(); pos++)
// 			(*pos)->activateAfter(i++);
// 
// 		/////do sth...
// 
// 	};
// 
// 
// 	miss->setExecuteTime(start);
// 
// 	return miss;
// }
// 
// SpaceWar::Mission* SpaceWar::MissionManager::getMissionX(float start)
// {
// 	Mission* miss = Mission::create();
// 
// 	miss->ExecuteMissionPrepare = [](Mission* miss) {
// 		auto shoot_point = Region::Center::GetPoint(4, 4);
// 		//��һ���ӵ�
// 		auto bullet1 = TestPlayerBullet::create("EB_1");
// 		//set some important traits..
// 		bullet1->GetBody()->SetTransform(Unit::Tob2Vec2(shoot_point), Unit::PI / 4);
// 		bullet1->setPosition(shoot_point);
// 		bullet1->setRotation(-1 * CC_RADIANS_TO_DEGREES(bullet1->GetBody()->GetAngle()));
// 
// 		bullet1->GetBody()->ApplyForceToCenter(Unit::Tob2Vec2(bullet1->getDirection() * 1000), true);
// 
// 
// 		//�ڶ����ӵ�
// 		auto bullet2 = bullet1->clone();
// 
// 		bullet2->GetBody()->SetTransform(Unit::Tob2Vec2(shoot_point), -Unit::PI / 4);
// 		bullet2->setPosition(shoot_point);
// 		bullet2->setRotation(-1 * CC_RADIANS_TO_DEGREES(bullet2->GetBody()->GetAngle()));
// 
// 		bullet2->GetBody()->ApplyForceToCenter(Unit::Tob2Vec2(bullet2->getDirection() * 1000), true);
// 		///////////////do sth...
// 
// 		bullet1->activate();
// 		bullet2->activate();
// 
// 		miss->m_objects.push_back(bullet1);
// 		miss->m_objects.push_back(bullet2);
// 
// 
// 		//�������
// 		Layer* layer = PhysicsWorldScene::getLayerSpr();
// 		for (auto elem : miss->m_objects)
// 			layer->addChild(elem);
// 
// 	};
// 
// 	miss->ExecuteMission = [](Mission* miss) {
// 		/////do sth...
// 		//ͬʱ����
// 		for (auto elem : miss->m_objects)
// 			elem->activate();
// 
// 		/////do sth...
// 	};
// 
// 
// 	miss->setExecuteTime(start);
// 
// 	return miss;
// }

SpaceWar::MissionManager* SpaceWar::MissionManager::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new MissionManager();
		if (m_instance != nullptr) {
			m_instance->init();
		}
	}
	return m_instance;
}

void SpaceWar::MissionManager::destroy()
{
	if (m_instance != nullptr)
		do { delete (m_instance); (m_instance) = nullptr; } while (0);
}

SpaceWar::MissionManager* SpaceWar::MissionManager::m_instance;

SpaceWar::MissionManager::MissionManager()
{

}

SpaceWar::MissionManager::~MissionManager()
{

}
