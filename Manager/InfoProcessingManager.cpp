#include "InfoProcessingManager.h"

using namespace std;
USING_NS_CC;
using namespace SpaceWar;

bool SpaceWar::InfoProcessingManager::init()
{
	//管理器订阅各种消息
	this->distance = 10000.0f;
	this->tracedObject = nullptr;
	return true;
}



SpaceWar::InfoProcessingManager* SpaceWar::InfoProcessingManager::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new InfoProcessingManager();
		if (m_instance != nullptr) {
			m_instance->init();
		}
	}
	return m_instance;
}

void SpaceWar::InfoProcessingManager::destroy()
{
	if (m_instance != nullptr)
		do { delete (m_instance); (m_instance) = nullptr; } while (0);
}

SpaceWar::InfoProcessingManager* SpaceWar::InfoProcessingManager::m_instance;

SpaceWar::InfoProcessingManager::InfoProcessingManager()
{

}

SpaceWar::InfoProcessingManager::~InfoProcessingManager()
{

}


