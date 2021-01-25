#include "WorldBoder.h"
#include "Region.h"

USING_NS_CC;
using namespace SpaceWar;

bool SpaceWar::WorldBoder::init()
{
	this->end = SpaceWar::Region::Center::GetPoint(7, 7);
	return true;
}

SpaceWar::WorldBoder* SpaceWar::WorldBoder::getInstance()
{
		if (m_instance == nullptr)
		{
			m_instance = new WorldBoder();
			if (m_instance != nullptr) {
				m_instance->init();
			}
		}
		return m_instance;
}

void SpaceWar::WorldBoder::destroy()
{
		if (m_instance != nullptr)
			do { delete (m_instance); (m_instance) = nullptr; } while (0);
}

SpaceWar::WorldBoder* SpaceWar::WorldBoder::m_instance;

SpaceWar::WorldBoder::WorldBoder()
{

}

SpaceWar::WorldBoder::~WorldBoder()
{

}
