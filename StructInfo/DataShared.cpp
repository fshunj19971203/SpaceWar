#include "DataShared.h"

USING_NS_CC;

void* SpaceWar::DataShared::PlayerPlaneMissileFiringInfoProcess::spaceObject = nullptr;

float SpaceWar::DataShared::PlayerPlaneMissileFiringInfoProcess::distance = 10000.0f;//假设为很大.

void SpaceWar::DataShared::PlayerPlaneMissileFiringInfoProcess::clear()
{
	spaceObject = nullptr;
	distance = 10000.0f;
}

