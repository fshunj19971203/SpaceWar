#include "PhysicsDebugDrawManager.h"
#include "GLES-Render.h"
#include "PhysicsManager.h"
#include "Unit.h"


bool SpaceWar::PhysicsDebugDrawManager::init()
{
	//init the debug draw
	uint32 flags = 0;
	GLESDebugDraw *m_debugdraw = new GLESDebugDraw(Unit::PixelToMeter);
	flags += b2Draw::e_shapeBit;
	flags += b2Draw::e_aabbBit;
	flags += b2Draw::e_jointBit;
	flags += b2Draw::e_pairBit;
	flags += b2Draw::e_centerOfMassBit;
	m_debugdraw->SetFlags(flags);
	PhysicsManager::getInstance()->getWorld()->SetDebugDraw(m_debugdraw);

	return true;
}



SpaceWar::PhysicsDebugDrawManager* SpaceWar::PhysicsDebugDrawManager::getInstance()
{
		if (m_instance == nullptr)
		{
			m_instance = new PhysicsDebugDrawManager();
			if (m_instance != nullptr) {
				m_instance->init();
			}
		}
		return m_instance;
}

void SpaceWar::PhysicsDebugDrawManager::destroy()
{

}

SpaceWar::PhysicsDebugDrawManager* SpaceWar::PhysicsDebugDrawManager::m_instance;

SpaceWar::PhysicsDebugDrawManager::PhysicsDebugDrawManager()
{

}

SpaceWar::PhysicsDebugDrawManager::~PhysicsDebugDrawManager()
{

}
