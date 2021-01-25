#include "GameOverScene.h"
#include "GameTexture.h"
#include "MyUtility.h"
#include "SimpleAudioEngine.h"
#include "HomeScene.h"


using namespace std;
USING_NS_CC;
using namespace SpaceWar;
using namespace CocosDenshion;

cocos2d::Scene* SpaceWar::GameOverScene::createScene(int hit_enemy_num)
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameOverSceneLayer::create(hit_enemy_num);

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

cocos2d::Layer* SpaceWar::GameOverScene::m_layer_game_over;

SpaceWar::GameOverSceneLayer::GameOverSceneLayer(int hit_enemy_num)
{
	this->m_hit_enemy_num = hit_enemy_num;

}



bool GameOverSceneLayer::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	//添加背景地图.


	//放置发光粒子背景
	ParticleSystem *ps = ParticleSystemQuad::create(GameTexture::getInstance()->getTextureRelativePath("light.plist"));
	ps->setPosition(Vec2(visibleSize.width, visibleSize.height - 200) / 2);
	this->addChild(ps);

	auto top = Sprite::createWithSpriteFrameName("gameover.top.png");
	//锚点在左下角
	top->setAnchorPoint(Vec2(0, 0));
	top->setPosition(Vec2(0, visibleSize.height - top->getContentSize().height));
	this->addChild(top);

	//
	__String *text = __String::createWithFormat("%i", m_hit_enemy_num);
	auto lblHighScore = Label::createWithTTF(MyUtility::getUTF8Char("HitEnemyNum"), GameTexture::getInstance()->getTextureRelativePath("hanyi.ttf"), 25);
	lblHighScore->setAnchorPoint(Vec2(0, 0));
	lblHighScore->setPosition(Vec2(60, top->getPosition().y - 30));
	addChild(lblHighScore);

	auto lblScore = Label::createWithTTF(text->getCString(), GameTexture::getInstance()->getTextureRelativePath("hanyi.ttf"), 24);
	lblScore->setColor(Color3B(75, 255, 255));
	lblScore->setAnchorPoint(Vec2(0, 0));
	lblScore->setPosition(lblHighScore->getPosition() - Vec2(0, 40));
	addChild(lblScore);

	auto text2 = Label::createWithTTF(string("Tap the Screen to Play"), GameTexture::getInstance()->getTextureRelativePath("hanyi.ttf"), 24);
	text2->setAnchorPoint(Vec2(0, 0));
	text2->setPosition(lblScore->getPosition() - Vec2(10, 45));
	addChild(text2);

	//注册 触摸事件监听器
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = [](Touch* touch, Event* event) {
		if (UserDefault::getInstance()->getBoolForKey("sound_key")) {
			SimpleAudioEngine::getInstance()->playEffect(GameTexture::getInstance()->getTextureRelativePath("music_blip").c_str());
		}
		Director::getInstance()->replaceScene(HomeScene::createScene());

		return false;
	};

	// 添加 触摸事件监听器
	EventDispatcher* eventDispatcher = Director::getInstance()->getEventDispatcher();
	eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void SpaceWar::GameOverSceneLayer::onExit()
{
	Layer::onExit();
	Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
}

void SpaceWar::GameOverSceneLayer::onEnterTransitionDidFinish()
{
	//播放GameOverScene主题曲.
	SimpleAudioEngine::getInstance()->playBackgroundMusic(GameTexture::getInstance()->getTextureRelativePath("music_gameover_background").c_str());
}

SpaceWar::GameOverSceneLayer* SpaceWar::GameOverSceneLayer::create(int hit_enemy_num)
{
	GameOverSceneLayer *gover = new GameOverSceneLayer(hit_enemy_num);

	if (gover && gover->init()) {
		gover->autorelease();
		return gover;
	}
	CC_SAFE_DELETE(gover);
	return nullptr;
}




