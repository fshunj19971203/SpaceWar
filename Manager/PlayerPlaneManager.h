#ifndef PlayerPlaneManager_h__
#define PlayerPlaneManager_h__
#include "cocos2d.h"
#include "SpaceObjectAgent.h"

namespace SpaceWar {
	class TestPlayerPlane;
	class PlayerPlaneManager {
	public:
		//methods
		bool init();//创建飞机,进入层创建，出层销毁！
	public:
		void CreateAPlayerPlane();
		void addToLayer(cocos2d::Layer* layer);//加入到某个层里面
		SpaceObjectAgent* getPlayerPlaneAgent();
		void updateAllShowingData();//更新数值
	private:
		//var1
		TestPlayerPlane* m_player_plane;
		//others.
	public:
		static PlayerPlaneManager* getInstance();
		static void destroy();
	private:
		static PlayerPlaneManager* m_instance;
	private:
		//玩家飞机代理人
		SpaceObjectAgent* m_player_plane_agent;
	private:
		PlayerPlaneManager();
		virtual ~PlayerPlaneManager();
	};


}

#endif // PlayerPlaneManager_h__
