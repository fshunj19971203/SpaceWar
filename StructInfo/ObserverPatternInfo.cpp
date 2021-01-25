#include "ObserverPatternInfo.h"

using namespace std;
USING_NS_CC;
using namespace SpaceWar;

SpaceWar::ExplosionInfo* SpaceWar::ExplosionInfo::create(cocos2d::Vec2 explode_point, float affected_radius)
{
	ExplosionInfo *ins = new (std::nothrow) ExplosionInfo();
	if (ins && ins->init(explode_point,affected_radius))
	{
		ins->autorelease();
		return ins;
	}
	CC_SAFE_DELETE(ins);
	return nullptr;
}

bool SpaceWar::ExplosionInfo::init(cocos2d::Vec2 explode_point, float affected_radius)
{
	m_affected_radius = affected_radius;
	m_explode_point = explode_point;
	return true;
}
