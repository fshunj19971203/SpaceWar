#ifndef GameLevelManager_h__
#define GameLevelManager_h__

#include "cocos2d.h"

namespace SpaceWar {
	class GameLevel;
	class GameLevelManager :public cocos2d::Node {
	public:
		//methods
		bool init();
		void initCurrentGameLevel();
		void processingCurrentGameLevel();
		inline int getCurrentGameLevel() const { return m_current_game_level; }
		inline void setCurrentGameLevel(int val) { m_current_game_level = val; }
	public:
		//45s后结束游戏
		void sendGameOverMess();
	private:
		//var,
		GameLevel* m_game_level;
		int m_current_game_level;//当前关卡..
		//others.
	public:
		static GameLevelManager* getInstance();
		void destroy();
		//销毁当前关卡
		void destroyCurrentGameLevel();
	private:
		static GameLevelManager* m_instance;
	private:
		//预初始化也就是把任务放在关卡中。
		void initGameLevelOne();
		void initGameLevelTwo();
		void initGameLevelThree();

	private:
		GameLevelManager();
		virtual ~GameLevelManager();
	};


}

#endif // GameLevelManager_h__







