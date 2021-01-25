#ifndef LoadingScene_h__
#define LoadingScene_h__
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include <thread>

namespace SpaceWar {
	class LoadingScene
	{
	public:
		static cocos2d::Layer* getLayerSpr() { return m_layer_home; }
		static void setLayerSpr(cocos2d::Layer* val) { m_layer_home = val; }
	public:
		static cocos2d::Scene* createScene();
	private:
		static cocos2d::Layer* m_layer_home;
	};




	class LoadingSceneLayer :public cocos2d::Layer
	{
	private:
		std::thread* _loadingAudioThread;
		void loadingAudio();
		void delayCall(float dt);
		void loadingTextureCallBack(cocos2d::Texture2D* texture);
		int m_nNumberOfLoaded;
	public:
		virtual bool init();
		virtual void onExit();

		CREATE_FUNC(LoadingSceneLayer);



	};
}
#endif // LoadingScene_h__





