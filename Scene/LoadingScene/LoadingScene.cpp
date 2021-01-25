#include "LoadingScene.h"
#include "HomeScene.h"
#include "GameTexture.h"
#include "SimpleAudioEngine.h"
#include "MissionManager.h"
#include "ManagerManager.h"

using namespace std;
USING_NS_CC;
using namespace SpaceWar;
using namespace CocosDenshion;
cocos2d::Scene* SpaceWar::LoadingScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = LoadingSceneLayer::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

cocos2d::Layer* SpaceWar::LoadingScene::m_layer_home;

void SpaceWar::LoadingSceneLayer::loadingAudio()
{
	log("loadAudio");
	//预加载几个声效
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(GameTexture::getInstance()->getTextureRelativePath("music_home_backgroud").c_str());
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(GameTexture::getInstance()->getTextureRelativePath("music_game_background").c_str());
}

void SpaceWar::LoadingSceneLayer::delayCall(float dt)
{
	Director::getInstance()->replaceScene(HomeScene::createScene());
}

void SpaceWar::LoadingSceneLayer::loadingTextureCallBack(cocos2d::Texture2D* texture)
{

	switch (m_nNumberOfLoaded++)
	{
	case 0:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile(GameTexture::getInstance()->getTextureRelativePath("home_texture.plist"), texture);
		log("home textrue ok.");
		break;
	case 1:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile(GameTexture::getInstance()->getTextureRelativePath("setting_texture.plist"), texture);
		log("setting textrue ok.");
		break;
	case 2:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile(GameTexture::getInstance()->getTextureRelativePath("gameplay_texture.plist"), texture);
		log("gameplay textrue ok.");
		this->schedule(schedule_selector(LoadingSceneLayer::delayCall), 1, 1, 3);
		//float interval, unsigned int repeat, float delay
		break;
	}
}


bool SpaceWar::LoadingSceneLayer::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//////////////////////////动画开始/////////////////////
	GameTexture::getInstance();

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(GameTexture::getInstance()->getTextureRelativePath("loading_texture.plist"));


	auto logo = Sprite::createWithSpriteFrameName("logo.png");
	this->addChild(logo);
	logo->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	auto sprite = Sprite::createWithSpriteFrameName("loding4.png");
	this->addChild(sprite);
	sprite->setPosition(logo->getPosition() - Vec2(0, logo->getContentSize().height / 2 + 30));

	///////////////动画开始//////////////////////
	Animation* animation = Animation::create();
	for (int i = 1; i <= 4; i++)
	{
		__String *frameName = __String::createWithFormat("loding%d.png", i);
		log("frameName = %s", frameName->getCString());
		SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
		animation->addSpriteFrame(spriteFrame);
	}

	animation->setDelayPerUnit(0.5f);           //设置两个帧播放时间
	animation->setRestoreOriginalFrame(true);    //动画执行后还原初始状态

	Animate* action = Animate::create(animation);
	sprite->runAction(RepeatForever::create(action));

	//在Loading动画运动中运行时候执行的
	m_nNumberOfLoaded = 0;

	Director::getInstance()->getTextureCache()->addImageAsync(GameTexture::getInstance()->getTextureRelativePath("home_texture.png"),
		CC_CALLBACK_1(LoadingSceneLayer::loadingTextureCallBack, this));

	Director::getInstance()->getTextureCache()->addImageAsync(GameTexture::getInstance()->getTextureRelativePath("setting_texture.png"),
		CC_CALLBACK_1(LoadingSceneLayer::loadingTextureCallBack, this));

	Director::getInstance()->getTextureCache()->addImageAsync(GameTexture::getInstance()->getTextureRelativePath("gameplay_texture.png"),
		CC_CALLBACK_1(LoadingSceneLayer::loadingTextureCallBack, this));




	_loadingAudioThread = new std::thread(&LoadingSceneLayer::loadingAudio, this);

	//加载各种管理器
	ManagerManager::getInstance();
	//////////////////////////////////////

	return true;
}

void SpaceWar::LoadingSceneLayer::onExit()
{
	Layer::onExit();
	this->_loadingAudioThread->join();
	CC_SAFE_DELETE(this->_loadingAudioThread);

	SpriteFrameCache::getInstance()->removeSpriteFramesFromFile(GameTexture::getInstance()->getTextureRelativePath("loading_texture.plist"));
	Director::getInstance()->getTextureCache()->removeTextureForKey(GameTexture::getInstance()->getTextureRelativePath("loading_texture.png"));
	this->unschedule(schedule_selector(LoadingSceneLayer::delayCall));
}




