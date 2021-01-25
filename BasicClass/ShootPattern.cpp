#include "ShootPattern.h"
#include "Plane.h"

using namespace std;
USING_NS_CC;
using namespace SpaceWar;


SpaceWar::ShootPattern* SpaceWar::ShootPattern::create(Plane* plane)
{
	ShootPattern *ins = new (std::nothrow) ShootPattern();
	if (ins && ins->init(plane))
		return ins;
	else
	{
		CC_SAFE_DELETE(ins);
		return nullptr;
	}
}

SpaceWar::ShootPattern* SpaceWar::ShootPattern::clone(Plane* plane)
{
	ShootPattern *ins = new (std::nothrow) ShootPattern();
	if (ins && ins->init(plane))
	{
		ins->m_shoot = this->m_shoot;
		return ins;
	}

	else
	{
		CC_SAFE_DELETE(ins);
		return nullptr;
	}
}

bool SpaceWar::ShootPattern::init(Plane* plane)
{
	this->setPlane(plane);
	return true;
}

