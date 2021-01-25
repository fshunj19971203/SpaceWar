#include "GameSetting.h"



USING_NS_CC;
using namespace SpaceWar;
void SpaceWar::GameSetting::init()
{
	m_designResolutionSize = Size(640, 960);
	m_smallResolutionSize = Size(320, 480);
	m_mediumResolutionSize = Size(768, 1024);
	m_largeResolutionSize = Size(1536, 2048);
}

cocos2d::Size SpaceWar::GameSetting::GetDesignResolutionSize()
{
	return m_designResolutionSize;
}

cocos2d::Size SpaceWar::GameSetting::GetSmallResolutionSize()
{
	return m_smallResolutionSize;
}

cocos2d::Size SpaceWar::GameSetting::GetMediumResolutionSize()
{
	return m_mediumResolutionSize;
}

cocos2d::Size SpaceWar::GameSetting::GetLargeResolutionSize()
{
	return m_largeResolutionSize;
}

GameSetting* SpaceWar::GameSetting::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new GameSetting();
		if (m_instance != nullptr) {
			m_instance->init();
		}
		else
			log("bad malloc error!");
	}
	return m_instance;
}

void SpaceWar::GameSetting::Destroy()
{
	if (m_instance != nullptr)
		do { delete (m_instance); (m_instance) = nullptr; } while (0);
}

SpaceWar::GameSetting::GameSetting()
{
	m_instance = nullptr;
}

SpaceWar::GameSetting::~GameSetting()
{
	
}

GameSetting* SpaceWar::GameSetting::m_instance = nullptr;



