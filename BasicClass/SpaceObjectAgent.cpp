#include "SpaceObjectAgent.h"
#include "SpaceObject.h"
#include "Unit.h"
#include "PhysicsWorldScene.h"
using namespace std;
USING_NS_CC;
using namespace SpaceWar;

SpaceWar::SpaceObjectAgent* SpaceWar::SpaceObjectAgent::create(bool valid, SpaceObject* object)
{
	SpaceObjectAgent *ins = new (std::nothrow) SpaceObjectAgent();
	if (ins && ins->init(valid, object))
	{
		ins->autorelease();
		return ins;
	}
	else
	{
		CC_SAFE_DELETE(ins);
		return nullptr;
	}

}

SpaceWar::SpaceObjectAgent::~SpaceObjectAgent()
{


}

bool SpaceWar::SpaceObjectAgent::init(bool valid, SpaceObject* object)
{

	//
	this->m_valid = valid;
	this->m_object = object;
	this->schedule(CC_CALLBACK_0(SpaceObjectAgent::autoCheck, this),
		3.0f,
		CC_REPEAT_FOREVER,
		0,
		Unit::generateGuid()
	);

	return true;
}

void SpaceWar::SpaceObjectAgent::destroy()
{
	this->stopAllActions();
	this->removeFromParent();
}

void SpaceWar::SpaceObjectAgent::autoCheck()
{

	if (!this->isValid()) {
		//无效了，3s后自动毁灭
		this->scheduleOnce(CC_CALLBACK_0(SpaceObjectAgent::destroy, this), 3.0f, Unit::generateGuid());
	}
}


