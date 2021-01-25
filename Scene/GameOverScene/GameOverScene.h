#ifndef GameOverScene_h__
#define GameOverScene_h__
#include "cocos2d.h"


namespace SpaceWar {


	class GameOverScene
	{
	public:
		static cocos2d::Layer* getLayer() { return m_layer_game_over; }
		static void setLayer(cocos2d::Layer* val) { m_layer_game_over = val; }
	public:
		static cocos2d::Scene* createScene(int hit_enemy_num);
	private:
		static cocos2d::Layer* m_layer_game_over;
	};



	class GameOverSceneLayer : public cocos2d::Layer
	{
		//当前玩家击敌机数
		int m_hit_enemy_num;
	public:
		GameOverSceneLayer(int hit_enemy_num);

		virtual bool init();
		virtual void onExit();
		virtual void onEnterTransitionDidFinish();
		static GameOverSceneLayer* create(int hit_enemy_num);
	};

}

#endif // GameOverScene_h__
