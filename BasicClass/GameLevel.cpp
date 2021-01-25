#include "GameLevel.h"
#include "Mission.h"
#include "PhysicsWorldScene.h"
#include "Unit.h"


using namespace std;
USING_NS_CC;
using namespace SpaceWar;

SpaceWar::GameLevel* SpaceWar::GameLevel::create()
{
	GameLevel *ins = new (std::nothrow) GameLevel();
	if (ins && ins->init())
		return ins;
	else
	{
		CC_SAFE_DELETE(ins);
		return nullptr;
	}
}

bool SpaceWar::GameLevel::init()
{
	m_time = 0;
	m_mission_set.clear();
	return true;
}

bool SpaceWar::GameLevel::addMission(Mission* mission)
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!mission);
		//Do Sth..
		m_mission_set.insert(mission);
		//Do Sth..
		bRet = true;
	} while (0);

	return bRet;


}




void SpaceWar::GameLevel::destroy()
{
	if (!m_mission_set.empty()) {
		for (auto i : m_mission_set) {
			delete i;
		}
		m_mission_set.clear();
	}

}

int SpaceWar::GameLevel::missionCount()
{
	return m_mission_set.size();
}

void SpaceWar::GameLevel::execute()
{
	if (m_mission_set.empty())
	{
		auto layer = PhysicsWorldScene::getLayerSpr();
		layer->unschedule("ExecuteGameLevel");
		return;
	}

	//找出那些达到时间的任务,并且在原集合删除他们
	vector<Mission*> ready_to_start_miss_set;
	for (auto iter = m_mission_set.begin(); iter != m_mission_set.end(); ) {
		auto tmpIter = iter;
		iter++;
		if (Unit::floatCmpEqual((*tmpIter)->getExecuteTime(),this->m_time))
		{
			ready_to_start_miss_set.push_back(*tmpIter);
			//删除.
			m_mission_set.erase(tmpIter);
		}
	}

	//执行任务
	for (auto elem : ready_to_start_miss_set) {
		elem->ExecuteMission(elem);
	}

	m_time += 0.5f;

}



