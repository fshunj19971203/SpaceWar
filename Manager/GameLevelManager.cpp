#include "GameLevelManager.h"
#include "GameLevel.h"
#include "MissionManager.h"
#include "Mission.h"
#include "Unit.h"
#include "PhysicsWorldScene.h"


using namespace std;
USING_NS_CC;
using namespace SpaceWar;


bool SpaceWar::GameLevelManager::init()
{
	auto layer = PhysicsWorldScene::getLayerSpr();
	layer->addChild(this);
	//�ȴ���һ�չؿ���
	m_game_level = GameLevel::create();
	return true;
}

void SpaceWar::GameLevelManager::initCurrentGameLevel()
{
	//45s�������Ϸ
	scheduleOnce(CC_CALLBACK_0(GameLevelManager::sendGameOverMess, this), 45.0f, Unit::generateGuid());

	if (this->getCurrentGameLevel() == 1) {
		initGameLevelOne();
	}
	else if (this->getCurrentGameLevel() == 2) {
		initGameLevelTwo();
	}
	else if (this->getCurrentGameLevel() == 3) {
		initGameLevelThree();

	}
}

void SpaceWar::GameLevelManager::processingCurrentGameLevel()
{
	//ÿִ֡��
	this->m_game_level->execute();
}


void SpaceWar::GameLevelManager::sendGameOverMess()
{
	__NotificationCenter::getInstance()->postNotification("GameLevelOver");
}

//#�ؿ�1
void SpaceWar::GameLevelManager::initGameLevelOne()
{
	this->m_game_level->addMission(MissionManager::getInstance()->getMissionMakePlane1(1.0f,0.8f,40));

}

//#�ؿ�2
void SpaceWar::GameLevelManager::initGameLevelTwo()
{
	this->m_game_level->addMission(MissionManager::getInstance()->getMissionMakePlane2(1.0f,0.8f,40));
}

//#�ؿ�3
void SpaceWar::GameLevelManager::initGameLevelThree()
{
	//����
	this->m_game_level->addMission(MissionManager::getInstance()->getMissionMakePlane1(1.0f, 4, 10));
	this->m_game_level->addMission(MissionManager::getInstance()->getMissionMakePlane2(1.0f, 4, 10));
	this->m_game_level->addMission(MissionManager::getInstance()->getMissionMakeAsdroid(1.0f,0.8,50));
}



void SpaceWar::GameLevelManager::destroyCurrentGameLevel()
{
	if (m_game_level != nullptr) {
		m_game_level->destroy();
		m_game_level = nullptr;
	}

}

SpaceWar::GameLevelManager* SpaceWar::GameLevelManager::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new GameLevelManager();
		if (m_instance != nullptr) {
			m_instance->init();
		}
	}
	return m_instance;
}

void SpaceWar::GameLevelManager::destroy()
{
	this->stopAllActions();
	this->removeFromParent();
	if (m_instance != nullptr)
		do { delete (m_instance); (m_instance) = nullptr; } while (0);
}

SpaceWar::GameLevelManager* SpaceWar::GameLevelManager::m_instance;

SpaceWar::GameLevelManager::GameLevelManager()
{

}

SpaceWar::GameLevelManager::~GameLevelManager()
{
	this->destroyCurrentGameLevel();
}

