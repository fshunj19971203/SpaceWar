#include "OutForce.h"

using namespace std;
USING_NS_CC;
using namespace SpaceWar;

SpaceWar::OutForce* SpaceWar::OutForce::create(float out_force, float start,float end, std::function<void(OutForce*)> call)
{
	OutForce *ins = new (std::nothrow) OutForce();
	if (ins && ins->init(out_force, start,end,call))
		return ins;
	else
	{
		CC_SAFE_DELETE(ins);
		return nullptr;
	}
}

SpaceWar::OutForce* SpaceWar::OutForce::clone()
{
	OutForce *ins = new (std::nothrow) OutForce();
	if (ins && ins->init(m_out_force, m_start_time,m_end_time,m_update_force_call))
		return ins;
	else
	{
		CC_SAFE_DELETE(ins);
		return nullptr;
	}
}

void SpaceWar::OutForce::destroy()
{
	delete this;
}

SpaceWar::OutForce::~OutForce()
{

}

bool SpaceWar::OutForce::init(float out_force,float start,float end,std::function<void(OutForce*)> call)
{
	this->m_out_force = out_force;
	this->m_start_time = start;
	this->m_end_time = end;
	this->m_update_force_call = call;
	return true;
}
