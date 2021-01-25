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
		void execute();//ִ�йؿ�.
	protected:
	private:
		//����ʱ��˳�������.
		std::multiset<Mission*,Mission::MissionCmp> m_mission_set;
		//�ؿ���ʱ��,��λ���롣
		float m_time;
	};

}

#endif // GameLevel_h__
