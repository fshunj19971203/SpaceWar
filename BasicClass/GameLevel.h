#ifndef GameLevel_h__
#define GameLevel_h__
#include <set>
#include "Mission.h"


namespace SpaceWar {
	class GameLevel
	{
	public:
		static GameLevel* create();
	public:
		bool init();
		bool addMission(Mission* mission);
		void destroy();
		int missionCount();
		void execute();//执行关卡.
	protected:
	private:
		//按照时间顺序排序的.
		std::multiset<Mission*,Mission::MissionCmp> m_mission_set;
		//关卡计时器,单位是秒。
		float m_time;
	};

}

#endif // GameLevel_h__
