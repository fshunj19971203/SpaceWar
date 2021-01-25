#include "HelpScene.h"
#include "MyUtility.h"
#include "GameTexture.h"


USING_NS_CC;
using namespace SpaceWar;

cocos2d::Scene* SpaceWar::HelpScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelpSceneLayer::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

cocos2d::Layer* SpaceWar::HelpScene::m_layer_home;

bool SpaceWar::HelpSceneLayer::init()
{
	//////////////////////////////
// 1. super init first
	if (!BaseLayer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto top = Sprite::createWithSpriteFrameName("help-top.png");
	top->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - top->getContentSize().height/2));
	addChild(top);

	//个人信息
	auto txtInfo = Label::createWithTTF(MyUtility::getUTF8Char("info"), GameTexture::getInstance()->getTextureRelativePath("hanyi.ttf"), 30);
	txtInfo->setColor(Color3B(198, 12, 0));
	txtInfo->setPosition(visibleSize.width / 2 - 200, top->getPosition().y - 200);
	txtInfo->setAnchorPoint(Vec2(0, 0));
	addChild(txtInfo, 1);



	//班级
	auto txtClass = Label::createWithTTF(MyUtility::getUTF8Char("class"),GameTexture::getInstance()->getTextureRelativePath("hanyi.ttf"), 30);
	txtClass->setColor(Color3B(198, 12, 0));
	Vec2 p2 = txtInfo->convertToWorldSpace(Vec2(0, -90));
	txtClass->setPosition(p2);
	txtClass->setAnchorPoint(Vec2(0, 0));
	addChild(txtClass, 1);

	//名字
	auto txtName = Label::createWithTTF(MyUtility::getUTF8Char("name"), GameTexture::getInstance()->getTextureRelativePath("hanyi.ttf"), 30);
	txtName->setAnchorPoint(Vec2(0, 0));
	Vec2 p3 = txtClass->convertToWorldSpace(Vec2(0, -90));
	txtName->setColor(Color3B(198, 12, 0));
	txtName->setPosition(p3);
	addChild(txtName, 1);



	return true;
}
