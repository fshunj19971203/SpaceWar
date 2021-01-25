#ifndef HelpScene_h__
#define HelpScene_h__
#include "cocos2d.h"
#include "CPhysicsSprite.h"
#include "Box2D/Box2D.h"
#include "BaseLayer.h"

namespace SpaceWar {
	class HelpScene
	{
	public:
		static cocos2d::Layer* getLayerSpr() { return m_layer_home; }
		static void setLayerSpr(cocos2d::Layer* val) { m_layer_home = val; }
	public:
		static cocos2d::Scene* createScene();
	private:
		static cocos2d::Layer* m_layer_home;
	};




	class HelpSceneLayer :public BaseLayer
	{
	public:
		virtual bool init();
		CREATE_FUNC(HelpSceneLayer);



	};

}

#endif // HelpScene_h__
