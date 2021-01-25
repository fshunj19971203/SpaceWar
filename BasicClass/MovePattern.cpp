#include "MovePattern.h"
#include "SpaceObject.h"
#include "SprayForce.h"
#include "TwistForce.h"
#include "OutForce.h"
#include <functional>
#include "Unit.h"

using namespace std;
USING_NS_CC;
using namespace SpaceWar;



SpaceWar::MovePattern::~MovePattern()
{
	for (auto elem : m_spray_force_arr)
		delete elem;
	for (auto elem : m_twist_force_arr)
		delete elem;
	for (auto elem : m_out_force_arr)
		delete elem;
}

SpaceWar::MovePattern* SpaceWar::MovePattern::create(SpaceObject* object)
{
	MovePattern *ins = new (std::nothrow) MovePattern();
	if (ins && ins->init(object))
		return ins;
	else
	{
		CC_SAFE_DELETE(ins);
		return nullptr;
	}
}



MovePattern* SpaceWar::MovePattern::clone(SpaceObject* object)
{
	MovePattern *ins = new (std::nothrow) MovePattern();
	if (ins && ins->init(object))
	{
		for (auto elem : this->m_spray_force_arr) {
			ins->addASprayForce(elem->clone());
		}
		for (auto elem : this->m_twist_force_arr) {
			ins->addATwistForce(elem->clone());

		}
		for (auto elem : this->m_out_force_arr) {
			ins->addAOuterForce(elem->clone());

		}
		ins->setMoveFunc(this->m_move);
		return ins;
	}

	else
	{
		CC_SAFE_DELETE(ins);
		return nullptr;
	}
}



void SpaceWar::MovePattern::destroy()
{
	// 	~MovePattern();
	delete this;
}

SpaceWar::MovePattern::MovePattern()
{

}



bool SpaceWar::MovePattern::init(SpaceObject* object)
{
	m_object = object;
	setTimePassed(0.0f);
	return true;
}

void SpaceWar::MovePattern::addASprayForce(SprayForce* spray)
{
	m_spray_force_arr.push_back(spray);
}

void SpaceWar::MovePattern::addATwistForce(TwistForce* twist)
{
	m_twist_force_arr.push_back(twist);
}

void SpaceWar::MovePattern::addAOuterForce(OutForce* out_force)
{
	m_out_force_arr.push_back(out_force);

}

void SpaceWar::MovePattern::setMoveFunc(std::function<void(MovePattern* move)> move)
{
	m_move = move;
}

SpaceWar::PlaneForce SpaceWar::MovePattern::getForce()
{
	this->setTimePassed(this->getTimePassed() + 0.1f);
// 	log("m_time_passed:%f", this->getTimePassed());
	PlaneForce force = PlaneForce(false, 0, 0, 0);

	//
	if (m_spray_force_arr.empty() && m_twist_force_arr.empty() && m_out_force_arr.empty()) {
		return force;
	}



	//±éÀúspray_forces
	for (auto elem : m_spray_force_arr) {
		if (Unit::floatCmpGreaterEqual(m_time_passed, elem->m_start)
			&& Unit::floatCmpLessEqual(m_time_passed, elem->m_end))
		{
			elem->m_update_force_call(elem);
			force.spray = elem->m_spray_force;
			force.valid = true;
			break;
		}
	};
	//±éÀútwist_forces
	for (auto elem : m_twist_force_arr) {
		if (Unit::floatCmpGreaterEqual(m_time_passed, elem->m_start)
			&& Unit::floatCmpLessEqual(m_time_passed, elem->m_end))
		{
			elem->m_update_force_call(elem);
			force.twist = elem->m_twist_force;
			force.valid = true;
			break;
		}
	};

	//±éÀúout_force..
	for (auto elem : m_out_force_arr) {
		if (Unit::floatCmpGreaterEqual(m_time_passed, elem->m_start_time)
			&& Unit::floatCmpLessEqual(m_time_passed, elem->m_end_time))
		{
			elem->m_update_force_call(elem);
			force.out = elem->m_out_force;
			force.valid = true;
			break;
		}
	};
	return force;

}

