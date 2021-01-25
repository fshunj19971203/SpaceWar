#include "HomeScene.h"
#include "ui/CocosGUI.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "GameTexture.h"
#include "PhysicsWorldScene.h"
#include "GameSettingScene.h"
#include "HelpScene.h"
USING_NS_CC;

using namespace ui;
using namespace cocostudio;
using namespace cocostudio::timeline;
using namespace SpaceWar;
using namespace std;

cocos2d::Layer* HomeScene::layer1;

cocos2d::Layer* HomeScene::layer2;

cocos2d::Scene* HomeScene::createScene()
{
	Scene* scene = Scene::create();
	//layer1 = HomeSceneLayer1::create();
	layer2 = HomeSceneLayer2::create();
	//scene->addChild(layer1);
	scene->addChild(layer2);
	//create a scene,all layers ,and init them..
	return scene;
}

bool HomeScene::init()
{
	// no use
	return true;
}
cocos2d::Layer* HomeScene::getLayer1()
{
	return layer1;
}

cocos2d::Layer* HomeScene::getLayer2()
{
	return layer2;
}




bool HomeSceneLayer1::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Layer::init());
		//Do Sth..

		bRet = true;
	} while (0);

	return bRet;

}

bool HomeSceneLayer2::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Layer::init());
		//Do Sth..
		Widget* root = static_cast<Widget*>(CSLoader::createNode(GameTexture::getInstance()->getTextureRelativePath("home_scene_csb")));

		this->addChild(root);
		Size frameSize = Director::getInstance()->getVisibleSize();
		root->setContentSize(frameSize);
		ui::Helper::doLayout(root);


		//获得3个cb
		auto cb_1 = static_cast<CheckBox*>(Helper::seekWidgetByName(static_cast<Widget*>(root), "cb-1"));
		auto cb_2 = static_cast<CheckBox*>(Helper::seekWidgetByName(static_cast<Widget*>(root), "cb-2"));
		auto cb_3 = static_cast<CheckBox*>(Helper::seekWidgetByName(static_cast<Widget*>(root), "cb-3"));

		//搞一个监听器,专门监听checkbox
		cb_1->addEventListener([=](Ref* pSender, CheckBox::EventType type) {
			switch (type) {
			case CheckBox::EventType::SELECTED:
				cb_1->setSelected(true);
				cb_2->setSelected(false);
				cb_3->setSelected(false);
				break;
			case CheckBox::EventType::UNSELECTED:
				cb_1->setSelected(false);
				break;
			}
		});

		cb_2->addEventListener([=](Ref* pSender, CheckBox::EventType type) {
			switch (type) {
			case CheckBox::EventType::SELECTED:
				cb_1->setSelected(false);
				cb_3->setSelected(false);
				cb_2->setSelected(true);
				break;
			case CheckBox::EventType::UNSELECTED:
				cb_2->setSelected(false);
				break;
			}
		});

		cb_3->addEventListener([=](Ref* pSender, CheckBox::EventType type) {
			switch (type) {
			case CheckBox::EventType::SELECTED:
				cb_1->setSelected(false);
				cb_2->setSelected(false);
				cb_3->setSelected(true);
				break;
			case CheckBox::EventType::UNSELECTED:
				cb_3->setSelected(false);
				break;
			}
		});

		//获得3个按钮
		auto bt_start = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Widget*>(root), "bt-start"));
		auto bt_setting = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Widget*>(root), "bt-setting"));
		auto bt_help = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Widget*>(root), "bt-help"));

		bt_start->addClickEventListener([=](Ref* pSender)
		{
			if (cb_1->isSelected())
			{
				Director::getInstance()->replaceScene(PhysicsWorldScene::createScene(1));
			}
			else if (cb_2->isSelected())
			{
				Director::getInstance()->replaceScene(PhysicsWorldScene::createScene(2));
			}
			else if (cb_3->isSelected())
			{
				Director::getInstance()->replaceScene(PhysicsWorldScene::createScene(3));
			}
		});

		bt_setting->addClickEventListener([=](Ref* pSender)
		{

			Director::getInstance()->replaceScene(GameSettingScene::createScene());
		});

		bt_help->addClickEventListener([=](Ref* pSender)
		{

			Director::getInstance()->replaceScene(HelpScene::createScene());
		});

		bRet = true;
	} while (0);

	return bRet;

}
