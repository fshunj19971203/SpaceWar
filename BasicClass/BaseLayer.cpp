#include "BaseLayer.h"
#include "GameTexture.h"
#include "SimpleAudioEngine.h"
#include "HomeScene.h"


using namespace std;
USING_NS_CC;
using namespace SpaceWar;
using namespace CocosDenshion;
// on "init" you need to initialize your instance
bool BaseLayer::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();



	//眼镜精灵.
	auto glassesSprite = Sprite::createWithSpriteFrameName("setting.glasses.png");
	glassesSprite->setPosition(Vec2(visibleSize.width - glassesSprite->getContentSize().width / 2, 160));
	addChild(glassesSprite);

	//手套精灵.
	auto handSprite = Sprite::createWithSpriteFrameName("setting.hand.png");
	handSprite->setPosition(Vec2(handSprite->getContentSize().width / 2, 60));
	addChild(handSprite);

	//Ok菜单.
	auto okNormal = Sprite::createWithSpriteFrameName("setting.button.ok.png");
	auto okSelected = Sprite::createWithSpriteFrameName("setting.button.ok-on.png");

	auto okMenuItem = MenuItemSprite::create(okNormal, okSelected, CC_CALLBACK_1(BaseLayer::menuBackCallback, this));
	auto mu = Menu::create(okMenuItem, NULL);
	mu->setPosition(Vec2(visibleSize.width - mu->getContentSize().width / 2 + 60, 60));
	addChild(mu);


	return true;
}


void BaseLayer::menuBackCallback(Ref* pSender)
{
	Director::getInstance()->replaceScene(HomeScene::createScene());
	if (UserDefault::getInstance()->getBoolForKey("sound_key")) {
		SimpleAudioEngine::getInstance()->playEffect(GameTexture::getInstance()->getTextureRelativePath("music_blip").c_str());
	}
}


void BaseLayer::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	log("BaseLayer onEnterTransitionDidFinish");
	UserDefault *defaults = UserDefault::getInstance();
	if (defaults->getBoolForKey("music_key")) {
		SimpleAudioEngine::getInstance()->playBackgroundMusic(GameTexture::getInstance()->getTextureRelativePath("music_home_backgroud").c_str(), true);
	}
}
