#include "MoveSchedule.h"

using namespace std;
USING_NS_CC;
using namespace SpaceWar;

bool SpaceWar::MoveSchedule::init(CPhysicsSprite* sprite)
{
	m_p_sprite = sprite;
	return  true;
}	
