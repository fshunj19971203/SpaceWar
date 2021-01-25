#include "GameSettingScene.h"
#include "MyUtility.h"
#include "SimpleAudioEngine.h"
#include "GameTexture.h"

using namespace std;
USING_NS_CC;
using namespace SpaceWar;
using namespace CocosDenshion;
cocos2d::Scene* SpaceWar::GameSettingScene::createScene()
{
	// 'scene' is an autorelease Ref
	auto scene = Scene::create();

	// 'layer' is an autorelease Ref
	auto layer = GameSettingSceneLayer::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

cocos2d::Layer* SpaceWar::GameSettingScene::m_layer_home;

bool SpaceWar::GameSettingSceneLayer::init()
{
	//////////////////////////////
// 1. super init first
	if (!BaseLayer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto top = Sprite::createWithSpriteFrameName("setting-top.png");
	top->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - top->getContentSize().height / 2));
	addChild(top);


	//音效.
	auto soundOnSprite = Sprite::createWithSpriteFrameName("setting.check-on.png");
	auto soundOffSprite = Sprite::createWithSpriteFrameName("setting.check-off.png");
	auto soundOnMenuItem = MenuItemSprite::create(soundOnSprite, NULL);
	auto soundOffMenuItem = MenuItemSprite::create(soundOffSprite, NULL);
	auto soundToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(GameSettingSceneLayer::menuSoundToggleCallback, this), soundOnMenuItem, soundOffMenuItem, NULL);

	//音乐.
	auto musicOnSprite = Sprite::createWithSpriteFrameName("setting.check-on.png");
	auto musicOffSprite = Sprite::createWithSpriteFrameName("setting.check-off.png");
	auto musicOnMenuItem = MenuItemSprite::create(musicOnSprite, NULL);
	auto musicOffMenuItem = MenuItemSprite::create(musicOffSprite, NULL);
	auto musicToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(GameSettingSceneLayer::menuMusicToggleCallback, this), musicOnMenuItem, musicOffMenuItem, NULL);



	auto  menu = Menu::create(
		soundToggleMenuItem,
		musicToggleMenuItem,
		NULL
	);

	menu->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2) + Vec2(70, 50));
	menu->alignItemsVerticallyWithPadding(20.0f);
	addChild(menu, 1);

	auto lblSound = Label::createWithTTF(MyUtility::getUTF8Char("lblSound"), GameTexture::getInstance()->getTextureRelativePath("hanyi.ttf"), 36);
	lblSound->setColor(Color3B(224, 83, 4));
	lblSound->setPosition(menu->getPosition() - Vec2(100, -60));
	addChild(lblSound, 1);

	auto lblMusic = Label::createWithTTF(MyUtility::getUTF8Char("lblMusic"), GameTexture::getInstance()->getTextureRelativePath("hanyi.ttf"), 36);
	lblMusic->setColor(Color3B(224, 83, 4));
	lblMusic->setPosition(lblSound->getPosition() - Vec2(0, 110));
	addChild(lblMusic, 1);




	//设置音效和音乐选中状态
	UserDefault *defaults = UserDefault::getInstance();
	if (defaults->getBoolForKey("music_key")) {
		musicToggleMenuItem->setSelectedIndex(0);
	}
	else {
		musicToggleMenuItem->setSelectedIndex(1);
	}
	if (defaults->getBoolForKey("sound_key")) {
		soundToggleMenuItem->setSelectedIndex(0);
	}
	else {
		soundToggleMenuItem->setSelectedIndex(1);
	}


	return true;
}

void SpaceWar::GameSettingSceneLayer::menuSoundToggleCallback(cocos2d::Ref* pSender)
{
	UserDefault *defaults = UserDefault::getInstance();
	if (defaults->getBoolForKey("sound_key")) {
		defaults->setBoolForKey("sound_key", false);
	}
	else {
		defaults->setBoolForKey("sound_key", true);
		SimpleAudioEngine::getInstance()->playEffect(GameTexture::getInstance()->getTextureRelativePath("music_blip").c_str());
	}
}

void SpaceWar::GameSettingSceneLayer::menuMusicToggleCallback(cocos2d::Ref* pSender)
{
	UserDefault *defaults = UserDefault::getInstance();
	if (defaults->getBoolForKey("music_key")) {
		defaults->setBoolForKey("music_key", false);
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	}
	else {
		defaults->setBoolForKey("music_key", true);
		SimpleAudioEngine::getInstance()->playBackgroundMusic(GameTexture::getInstance()->getTextureRelativePath("music_home_backgroud").c_str(), true);
	}
}



