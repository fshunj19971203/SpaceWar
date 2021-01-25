#ifndef HomeScene_h__
#define HomeScene_h__
#include "cocos2d.h"

class HomeScene {
private:
	static cocos2d::Layer* layer1;
	static cocos2d::Layer* layer2;
public:
	static cocos2d::Scene* createScene();
	bool init();
	static cocos2d::Layer* getLayer1();
	static cocos2d::Layer* getLayer2();
};


class HomeSceneLayer1 :public cocos2d::Layer {
public:
	CREATE_FUNC(HomeSceneLayer1);
	bool init();
};





class HomeSceneLayer2 :public cocos2d::Layer {
public:
	CREATE_FUNC(HomeSceneLayer2);
	bool init();
};










#endif // HomeScene_h__

