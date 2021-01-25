#ifndef GameSettingScene_h__
#define GameSettingScene_h__
#include "cocos2d.h"
#include "BaseLayer.h"


namespace SpaceWar {
	class GameSettingScene
	{
	public:
		static cocos2d::Layer* getLayerSpr() { return m_layer_home; }
		static void setLayerSpr(cocos2d::Layer* val) { m_layer_home = val; }
	public:
		static cocos2d::Scene* createScene();
	private:
		static cocos2d::Layer* m_layer_home;
	};



	class GameSettingSceneLayer : public BaseLayer
	{
	public:
		virtual bool init();
		void menuSoundToggleCallback(cocos2d::Ref* pSender);
		void menuMusicToggleCallback(cocos2d::Ref* pSender);
		CREATE_FUNC(GameSettingSceneLayer);
	};

}

#endif // GameSettingScene_h__
