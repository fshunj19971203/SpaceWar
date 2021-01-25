#include "SprayForce.h"


using namespace std;
USING_NS_CC;
using namespace SpaceWar;




SpaceWar::SprayForce* SpaceWar::SprayForce::create(float spray_force, float start,
	float end, std::function<void(SprayForce*)> update_call)
{
	SprayForce *ins = new (std::nothrow) SprayForce();
	if (ins && ins->init(spray_force,start,end,update_call))
	{
		return ins;
	}

	else
	{
		CC_SAFE_DELETE(ins);
		return nullptr;
	}
}

SpaceWar::SprayForce* SpaceWar::SprayForce::clone()
{
	SprayForce *ins = new (std::nothrow) SprayForce();
	if (ins && ins->init(this->m_spray_force,this->m_start,this->m_end,this->m_update_force_call))
	{
		return ins;
	}

	else
	{
		CC_SAFE_DELETE(ins);
		return nullptr;
	}
}

bool SpaceWar::SprayForce::init(float spray_force, float start,
	float end, std::function<void(SprayForce*)> update_call)
{
	this->m_spray_force = spray_force;
	this->m_start = start;
	this->m_end = end;
	this->m_update_force_call = update_call;
	return true;
}	

