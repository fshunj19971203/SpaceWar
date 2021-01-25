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
		//45s�������Ϸ
		void sendGameOverMess();
	private:
		//var,
		GameLevel* m_game_level;
		int m_current_game_level;//��ǰ�ؿ�..
		//others.
	public:
		static GameLevelManager* getInstance();
		void destroy();
		//���ٵ�ǰ�ؿ�
		void destroyCurrentGameLevel();
	private:
		static GameLevelManager* m_instance;
	private:
		//Ԥ��ʼ��Ҳ���ǰ�������ڹؿ��С�
		void initGameLevelOne();
		void initGameLevelTwo();
		void initGameLevelThree();

	private:
		GameLevelManager();
		virtual ~GameLevelManager();
	};


}

#endif // GameLevelManager_h__







