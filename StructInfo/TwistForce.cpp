#include "TwistForce.h"


using namespace std;
USING_NS_CC;
using namespace SpaceWar;


SpaceWar::TwistForce* SpaceWar::TwistForce::create(float twist_force,float start,float end,std::function<void(TwistForce*)> call)
{
	TwistForce *ins = new (std::nothrow) TwistForce();
	if (ins && ins->init(twist_force,start,end,call))
		return ins;
	else
	{
		CC_SAFE_DELETE(ins);
		return nullptr;
	}
}

SpaceWar::TwistForce* SpaceWar::TwistForce::clone()
{
	TwistForce *ins = new (std::nothrow) TwistForce();
	if (ins && ins->init(this->m_twist_force,this->m_start,this->m_end,this->m_update_force_call))
		return ins;
	else
	{
		CC_SAFE_DELETE(ins);
		return nullptr;
	}
}

void SpaceWar::TwistForce::destroy()
{
// 	~TwistForce();
}

SpaceWar::TwistForce::~TwistForce()
{
	
}

bool SpaceWar::TwistForce::init(float twist_force,float start,float end,std::function<void(TwistForce*)> call)
{
	this->m_twist_force = twist_force;
	this->m_start = start;
	this->m_end = end;
	this->m_update_force_call = call;
	return true;
}
