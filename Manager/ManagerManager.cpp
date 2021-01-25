#include "ManagerManager.h"
#include "PhysicsManager.h"
#include "PhysicsObjectLoadManager.h"
#include "PlayerPlaneManager.h"
#include "InfoProcessingManager.h"
#include "BlastEffectManager.h"
#include "PhysicsDebugDrawManager.h"
#include "ParticleManager.h"
#include "ShootPattenManager.h"
#include "MissionManager.h"
#include "GameLevelManager.h"
#include "Configure.h"



bool SpaceWar::ManagerManager::init()
{
	this->initManagersOnProgramStart();
	return true;
}

void SpaceWar::ManagerManager::initManagersOnProgramStart()
{
	// init the Physical World
	PhysicsManager::getInstance();

	//init the Physical Debug Draw
 	//PhysicsDebugDrawManager::getInstance();


	//load the physical object in cache
	PhysicsObjectLoadManager::getInstance();


	//初始化信息交流管理器
	InfoProcessingManager::getInstance();

	//初始化爆炸效果管理器
	BlastEffectManager::getInstance();
	//初始化配置管理器
	ConfigureManager::getInstance();
}

SpaceWar::ManagerManager* SpaceWar::ManagerManager::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new ManagerManager();
		if (m_instance != nullptr) {
			m_instance->init();
		}
	}
	return m_instance;
}

void SpaceWar::ManagerManager::destroy()
{
	//删除所有的管理器
	PhysicsManager::getInstance()->destroy();
	PhysicsObjectLoadManager::getInstance()->destroy();
	PlayerPlaneManager::getInstance()->destroy();
	InfoProcessingManager::getInstance()->destroy();
	BlastEffectManager::getInstance()->destroy();
	//
	GameLevelManager::getInstance()->destroy();
	MissionManager::getInstance()->destroy();
	ParticleManager::getInstance()->destroy();
	ShootPattenManager::getInstance()->destroy();
	ConfigureManager::getInstance()->destroy();
	if (m_instance != nullptr)
		do { delete (m_instance); (m_instance) = nullptr; } while (0);
}

SpaceWar::ManagerManager* SpaceWar::ManagerManager::m_instance;

SpaceWar::ManagerManager::ManagerManager()
{

}

SpaceWar::ManagerManager::~ManagerManager()
{

}
