#include "MovePatternManager.h"
#include "MovePattern.h"
#include "SprayForce.h"
#include "Unit.h"
#include "Box2D/Box2D.h"
#include "cocos2d.h"
#include "EnemyPlane.h"
#include "TwistForce.h"
#include "PlayerPlaneManager.h"
#include "SpaceObjectAgent.h"
using namespace std;
USING_NS_CC;
using namespace SpaceWar;

bool SpaceWar::MovePatternManager::init()
{
	return true;
}

SpaceWar::MovePattern* SpaceWar::MovePatternManager::getMovePatternOne(EnemyPlane* plane, int apply_force, int incr)
{
	MovePattern* move = MovePattern::create(plane);

	move->addASprayForce(SprayForce::create(
		apply_force,
		1,
		100,
		[incr](SprayForce* spray) {
		spray->m_spray_force += incr;
	}));

	//�����˶��Ĵ���
	auto move_func = [](MovePattern* move) {
		//update time..
		move->setTimePassed(move->getTimePassed() + 0.1f);
		//get sth..
		auto plane = static_cast<EnemyPlane*>(move->getSpaceObject());
		b2Body* body = plane->GetBody();
		PlaneForce force = move->getForce();

		if (force.valid == false) {
			return;
		}
		if (force.spray != 0) {
			auto one = plane->getShootingPoint();
			auto two = plane->getMiddlePoint();
			one = plane->convertToWorldSpace(one);
			two = plane->convertToWorldSpace(two);
			auto spraying_force = Unit::Tob2Vec2((one - two).getNormalized());
			spraying_force *= force.spray;

			body->ApplyForceToCenter(spraying_force, true);

		}
		if (force.twist != 0) {
			body->ApplyTorque(force.twist, true);
		}

		if (force.out != 0) {

		}

	};

	move->setMoveFunc(move_func);
	return move;
}

SpaceWar::MovePattern* SpaceWar::MovePatternManager::getMovePatternThree(EnemyPlane* plane, int apply_force)
{
	MovePattern* move = MovePattern::create(plane);


	///////////////do sth..
	move->addASprayForce(SprayForce::create(
		apply_force,
		0.1,
		0.1,
		[](SprayForce* spray) {

	}));



	////////////do sth..

	//control move..
	auto move_func = [](MovePattern* move) {
		//update time..
		//get sth..
		auto plane = static_cast<EnemyPlane*>(move->getSpaceObject());
		b2Body* body = plane->GetBody();
		PlaneForce force = move->getForce();

		if (force.valid == false) {
			return;
		}
		if (force.spray != 0) {
			auto one = plane->getShootingPoint();
			auto two = plane->getMiddlePoint();
			one = plane->convertToWorldSpace(one);
			two = plane->convertToWorldSpace(two);
			auto spraying_force = Unit::Tob2Vec2((one - two).getNormalized());
			spraying_force *= force.spray;

			body->ApplyForceToCenter(spraying_force, true);

		}
		if (force.twist != 0) {
			body->ApplyTorque(force.twist, true);
		}

		if (force.out != 0) {

		}

	};

	move->setMoveFunc(move_func);
	return move;
}

SpaceWar::MovePattern* SpaceWar::MovePatternManager::getMovePatternTwo(EnemyPlane* plane)
{
	MovePattern* move = MovePattern::create(plane);

	move->addASprayForce(SprayForce::create(
		5000,
		0.1,
		0.8,
		[](SprayForce* spray) {

	}));

	//�����˶��Ĵ���
	auto move_func = [](MovePattern* move) {
		//update time..
		move->setTimePassed(move->getTimePassed() + 0.1f);
		//get sth..
		auto plane = static_cast<EnemyPlane*>(move->getSpaceObject());
		b2Body* body = plane->GetBody();
		PlaneForce force = move->getForce();

		if (force.valid == false) {
			return;
		}
		if (force.spray != 0) {
			auto one = plane->getShootingPoint();
			auto two = plane->getMiddlePoint();
			one = plane->convertToWorldSpace(one);
			two = plane->convertToWorldSpace(two);
			auto spraying_force = Unit::Tob2Vec2((one - two).getNormalized());
			spraying_force *= force.spray;
			body->SetLinearDamping(0.3);
			body->ApplyForceToCenter(spraying_force, true);

		}
		if (force.twist != 0) {
			body->ApplyTorque(force.twist, true);
		}

		if (force.out != 0) {

		}

	};

	move->setMoveFunc(move_func);
	return move;
}

SpaceWar::MovePattern* SpaceWar::MovePatternManager::getMovePatternFour(EnemyPlane* plane)
{
	MovePattern* move = MovePattern::create(plane);

	move->addASprayForce(SprayForce::create(
		500,
		0,
		1,
		[](SprayForce* spray) {

	}));

	move->addASprayForce(SprayForce::create(
		1000,
		3,
		8,
		[](SprayForce* spray) {

	}));

	move->addATwistForce(TwistForce::create(
		-50,
		3,
		5,
		[](TwistForce* spray) {

	}));



	//�����˶��Ĵ���
	auto move_func = [](MovePattern* move) {
		//update time..
		//get sth..
		auto plane = static_cast<EnemyPlane*>(move->getSpaceObject());
		b2Body* body = plane->GetBody();
		PlaneForce force = move->getForce();

		if (force.valid == false) {
			return;
		}
		if (force.spray != 0) {
			auto one = plane->getShootingPoint();
			auto two = plane->getMiddlePoint();
			one = plane->convertToWorldSpace(one);
			two = plane->convertToWorldSpace(two);
			auto spraying_force = Unit::Tob2Vec2((one - two).getNormalized());
			spraying_force *= force.spray;

			body->ApplyForceToCenter(spraying_force, true);

		}
		if (force.twist != 0) {
			body->ApplyTorque(force.twist, true);
		}

		if (force.out != 0) {

		}

	};

	move->setMoveFunc(move_func);
	return move;
}


SpaceWar::MovePattern* SpaceWar::MovePatternManager::getMovePatternFive(EnemyPlane* plane)
{
	MovePattern* move = MovePattern::create(plane);


	///////////////do sth..
	move->addASprayForce(SprayForce::create(
		300,
		0,
		1000,
		[](SprayForce* spray) {

	}));

	move->addATwistForce(TwistForce::create(
		30,
		3,
		5,
		[](TwistForce* twist) {
		twist->m_twist_force -= 3;
	}));


	////////////do sth..

	//control move..
	auto move_func = [](MovePattern* move) {
		//update time..
		//get sth..
		auto plane = static_cast<EnemyPlane*>(move->getSpaceObject());
		b2Body* body = plane->GetBody();
		PlaneForce force = move->getForce();

		if (force.valid == false) {
			return;
		}
		if (force.spray != 0) {
			auto one = plane->getShootingPoint();
			auto two = plane->getMiddlePoint();
			one = plane->convertToWorldSpace(one);
			two = plane->convertToWorldSpace(two);
			auto spraying_force = Unit::Tob2Vec2((one - two).getNormalized());
			spraying_force *= force.spray;

			body->ApplyForceToCenter(spraying_force, true);

		}
		if (force.twist != 0) {
			body->ApplyTorque(force.twist, true);
		}

		if (force.out != 0) {

		}

	};

	move->setMoveFunc(move_func);
	return move;
}


SpaceWar::MovePattern* SpaceWar::MovePatternManager::getMovePatternSpecialOne(EnemyPlane* plane)
{
	MovePattern* move = MovePattern::create(plane);

	///////////////do sth..
	move->addASprayForce(SprayForce::create(
		20000,
		0.1,
		0.1,
		[](SprayForce* spray) {

	}));

	move->addATwistForce(TwistForce::create(
		60,
		3,
		1000,
		[](TwistForce* twist) {

	}));

	////////////do sth..

	//control move..
	auto move_func = [](MovePattern* move) {
		//update time..
		//get sth..
		auto plane = static_cast<EnemyPlane*>(move->getSpaceObject());
		b2Body* body = plane->GetBody();
		PlaneForce force = move->getForce();

		if (force.valid == false) {
			return;
		}
		if (force.spray != 0) {
			auto one = plane->getShootingPoint();
			auto two = plane->getMiddlePoint();
			one = plane->convertToWorldSpace(one);
			two = plane->convertToWorldSpace(two);
			auto spraying_force = Unit::Tob2Vec2((one - two).getNormalized());
			spraying_force *= force.spray;

			body->ApplyForceToCenter(spraying_force, true);

		}
		if (force.twist != 0) {
			//ԭ����
			auto origin_vec2 = plane->getSprayUnitVector();
			Vec3 origin_vec3 = Vec3(origin_vec2.x, origin_vec2.y, 0);

			//Ŀ������
			//�����ҷɻ���Ч������ֹͣ
			if (!PlayerPlaneManager::getInstance()->getPlayerPlaneAgent()->isValid()) {
				return;
			}

			auto dest_playerplane_vec2 = PlayerPlaneManager::getInstance()
				->getPlayerPlaneAgent()->getSpaceObject()->getPosition();
			auto dest_enemyplane_middle_point_vec2 = plane->convertToWorldSpace(plane->getMiddlePoint());
			auto dest_vec2 = dest_playerplane_vec2 - dest_enemyplane_middle_point_vec2;
			Vec3 dest_vec3 = Vec3(dest_vec2.x, dest_vec2.y, 0);

			//angle
			auto angle = Vec3::angle(origin_vec3, dest_vec3);
			//����twist..
			force.twist = (angle / Unit::PI) * force.twist;
			//�������ٶ�����,���Խ����������Խ��
			body->SetAngularDamping((Unit::PI - angle) / Unit::PI);
			//���
			Vec3 result;
			Vec3::cross(origin_vec3, dest_vec3, &result);
			if (result.z > 0) {
				//��ʱ��ת��twist����Ϊ��.
				body->ApplyTorque(force.twist, true);

			}
			else if (result.z < 0) {
				//˳ʱ��ת��twist����Ϊ��.
				body->ApplyTorque(-force.twist, true);


			}

		}

		if (force.out != 0) {

		}

	};

	move->setMoveFunc(move_func);
	return move;
}



//ֱ�ߺ�
SpaceWar::MovePattern* SpaceWar::MovePatternManager::getMovePatternSeven(EnemyPlane* plane, cocos2d::Vec2 direction)
{
	MovePattern* move = MovePattern::create(plane);


	///////////////do sth..
	move->addASprayForce(SprayForce::create(
		10000,
		0.1,
		0.1,
		[](SprayForce* spray) {

	}));

	move->addASprayForce(SprayForce::create(
		100,
		3,
		100,
		[](SprayForce* spray) {
		spray->m_spray_force += 200;
	}));

	move->addATwistForce(TwistForce::create(
		10,
		3,
		100,
		[](TwistForce* twist) {
	}));

	////////////do sth..

	//control move..
	auto move_func = [direction](MovePattern* move) {
		//update time..
		//get sth..
		auto plane = static_cast<EnemyPlane*>(move->getSpaceObject());
		b2Body* body = plane->GetBody();
		PlaneForce force = move->getForce();

		if (force.valid == false) {
			return;
		}
		if (force.spray != 0) {
			auto one = plane->getShootingPoint();
			auto two = plane->getMiddlePoint();
			one = plane->convertToWorldSpace(one);
			two = plane->convertToWorldSpace(two);
			auto spraying_force = Unit::Tob2Vec2((one - two).getNormalized());
			spraying_force *= force.spray;

			body->ApplyForceToCenter(spraying_force, true);

		}
		if (force.twist != 0) {
			//���spray_vector��-spray_vector�ĽǶ�..���ӽ���Ⱦ�return,,

			//��ͷ��������,
			auto origin_vec2 = plane->getSprayUnitVector();

			//�Ƕ�
			auto angle = Vec2::angle(origin_vec2, direction);

			//����1�Ȳ�ʩ��Ť��.
			if (angle > Unit::degToRad(10)) {
				//�Ƕ�ԽС��Ť��ԽС��ͬʱ���ٶ�����Խ��
				force.twist = (angle / Unit::PI) * force.twist;
				body->SetAngularDamping((Unit::PI - angle) / Unit::PI);

				body->ApplyTorque(force.twist, true);
			}


		}

		if (force.out != 0) {

		}

	};

	move->setMoveFunc(move_func);
	return move;
}

SpaceWar::MovePattern* SpaceWar::MovePatternManager::getMovePatternEight(EnemyPlane* plane, cocos2d::Vec2 direction)
{
	MovePattern* move = MovePattern::create(plane);


	///////////////do sth..
	move->addASprayForce(SprayForce::create(
		10000,
		0.1,
		0.1,
		[](SprayForce* spray) {

	}));

	move->addASprayForce(SprayForce::create(
		100,
		3,
		100,
		[](SprayForce* spray) {
		spray->m_spray_force += 100;
	}));

	move->addATwistForce(TwistForce::create(
		10,
		3,
		100,
		[](TwistForce* twist) {
	}));

	////////////do sth..

	//control move..
	auto move_func = [direction](MovePattern* move) {
		//update time..
		//get sth..
		auto plane = static_cast<EnemyPlane*>(move->getSpaceObject());
		b2Body* body = plane->GetBody();
		PlaneForce force = move->getForce();

		if (force.valid == false) {
			return;
		}
		if (force.spray != 0) {
			auto one = plane->getShootingPoint();
			auto two = plane->getMiddlePoint();
			one = plane->convertToWorldSpace(one);
			two = plane->convertToWorldSpace(two);
			auto spraying_force = Unit::Tob2Vec2((one - two).getNormalized());
			spraying_force *= force.spray;

			body->ApplyForceToCenter(spraying_force, true);

		}
		if (force.twist != 0) {
			//���spray_vector��-spray_vector�ĽǶ�..���ӽ���Ⱦ�return,,

			//��ͷ��������,
			auto origin_vec2 = plane->getSprayUnitVector();

			//�Ƕ�
			auto angle = Vec2::angle(origin_vec2, direction);

			//����1�Ȳ�ʩ��Ť��.
			if (angle > Unit::degToRad(20)) {
				//�Ƕ�ԽС��Ť��ԽС��ͬʱ���ٶ�����Խ��
				force.twist = (angle / Unit::PI) * force.twist;
				body->SetAngularDamping((Unit::PI - angle) / Unit::PI);

				body->ApplyTorque(-force.twist, true);
			}


		}

		if (force.out != 0) {

		}

	};

	move->setMoveFunc(move_func);
	return move;
}

SpaceWar::MovePattern* SpaceWar::MovePatternManager::getMovePatternMissileOne(Missile* missile)
{
	MovePattern* move = MovePattern::create(missile);


	///////////////do sth..
	move->addASprayForce(SprayForce::create(
		2000,
		0,
		1000,
		[](SprayForce* spray) {
		spray->m_spray_force += 100;
	}));



	move->addATwistForce(TwistForce::create(
		3,
		0,
		1000,
		[](TwistForce* twist) {
		twist->m_twist_force += 0.5;
	}));

	////////////do sth..

	//control move..
	auto move_func = [](MovePattern* move) {
		//update time..
		//get sth..
		auto missile = static_cast<Missile*>(move->getSpaceObject());
		b2Body* body = missile->GetBody();
		PlaneForce force = move->getForce();
		Vec2 force_vec;
		SpaceObject* traced_object;
		//
		auto traced_object_agent = missile->getTracedObjectAgent();
		if (!traced_object_agent->isValid()) {
			//��׷�ٵ�����ʧЧ��,,�����˶�..
			missile->setMoveValid(false);
			return;
		}
		else {
			traced_object = traced_object_agent->getSpaceObject();
		}


		if (force.valid == false) {
			return;
		}
		if (force.spray != 0) {
			force_vec = (missile->convertToWorldSpace(Vec2(1, 2)) - missile->convertToWorldSpace(Vec2(1, 1))).getNormalized();
			force_vec *= force.spray;
			//
			missile->getParticle()->setEmissionRate(force.spray * 3);
			body->ApplyForceToCenter(Unit::Tob2Vec2(force_vec), true);
		}
		if (force.twist != 0) {
			//ԭ����
			Vec2 origin_vec2 = (missile->convertToWorldSpace(Vec2(1, 2)) - missile->convertToWorldSpace(Vec2(1, 1))).getNormalized();
			Vec3 origin_vec3 = Vec3(origin_vec2.x, origin_vec2.y, 0);

			//Ŀ������(��Ҫת���Ŀ��)
			auto traced_object_rect = traced_object->getBoundingBox();
			auto traced_object_vec2 = traced_object->convertToWorldSpace(Vec2(traced_object_rect.size.width / 2, traced_object_rect.size.height / 2));
			//
			auto missile_vec2 = missile->convertToWorldSpace(missile->getMiddlePoint());
			auto dest_vec2 = traced_object_vec2 - missile_vec2;
			Vec3 dest_vec3 = Vec3(dest_vec2.x, dest_vec2.y, 0);

			//angle
			auto angle = Vec3::angle(origin_vec3, dest_vec3);
			log("angle:%f", angle);

			if (Unit::radToDeg(angle) < 2.0f) {
				if (!body->IsBullet()) {
					body->SetAngularDamping(1);
					body->SetBullet(true);//�����ӵ�..
					body->ApplyForceToCenter(Unit::Tob2Vec2(force_vec * 100), true);
				}
				return;
			}

			//����twist..
			force.twist = (angle / Unit::PI) * force.twist;
			//�������ٶ�����,���Խ����������Խ��
			body->SetAngularDamping((Unit::PI - angle) / Unit::PI);
			//���
			Vec3 result;
			Vec3::cross(origin_vec3, dest_vec3, &result);
			if (result.z > 0) {
				//��ʱ��ת��twist����Ϊ��.
				body->ApplyTorque(force.twist, true);

			}
			else if (result.z < 0) {
				//˳ʱ��ת��twist����Ϊ��.
				body->ApplyTorque(-force.twist, true);


			}

		}
		if (force.out != 0) {

		}

	};

	move->setMoveFunc(move_func);
	return move;
}

SpaceWar::MovePattern* SpaceWar::MovePatternManager::getMovePatternMissileTwo(Missile* missile)
{
	MovePattern* move = MovePattern::create(missile);


	///////////////do sth..
	move->addASprayForce(SprayForce::create(
		100,
		0,
		1000,
		[](SprayForce* spray) {
	}));


	//control move..
	auto move_func = [](MovePattern* move) {
		//get sth..
		auto missile = static_cast<Missile*>(move->getSpaceObject());
		PlaneForce force = move->getForce();

		//��������
		auto force_vec = (missile->convertToWorldSpace(Vec2(1, 2)) - missile->convertToWorldSpace(Vec2(1, 1))).getNormalized();
		force_vec *= force.spray;
		b2Body* body = missile->GetBody();

		body->ApplyForceToCenter(b2Vec2(force_vec.x, force_vec.y), true);
	};


	move->setMoveFunc(move_func);




	return move;
}
SpaceWar::MovePatternManager* SpaceWar::MovePatternManager::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new MovePatternManager();
		if (m_instance != nullptr) {
			m_instance->init();
		}
	}
	return m_instance;
}

void SpaceWar::MovePatternManager::destroy()
{
	if (m_instance != nullptr)
		do { delete (m_instance); (m_instance) = nullptr; } while (0);
}

SpaceWar::MovePatternManager* SpaceWar::MovePatternManager::m_instance;

SpaceWar::MovePatternManager::MovePatternManager()
{

}

SpaceWar::MovePatternManager::~MovePatternManager()
{

}
