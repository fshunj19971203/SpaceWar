#include "PhysicsWorldScene.h"
#include "PhysicsManager.h"
#include "Unit.h"
#include "GB2ShapeCache-x.h"
#include "PhysicsObjectLoadManager.h"
#include "PhysicsDebugDrawManager.h"
#include "GameSetting.h"
#include "PlayerPlaneOne.h"
#include "Region.h"
#include "TestPlayerBullet.h"
#include "TestAstroid.h"
#include "AstroidShooter.h"
#include "PlayerPlaneManager.h"
#include "GameLevelManager.h"
#include "EnemyPlaneFive.h"
#include "InfoProcessingManager.h"
#include "BlastEffectManager.h"
#include "ManagerManager.h"
#include "SimpleAudioEngine.h"
#include "GameTexture.h"
#include "MyUtility.h"
#include "GameOverScene.h"
#include "EnemyPlaneShooter.h"
#include "HomeScene.h"




using namespace std;
USING_NS_CC;
using namespace SpaceWar;
using namespace CocosDenshion;
cocos2d::Layer* PhysicsWorldScene::m_layer_spr = nullptr;


cocos2d::Layer* PhysicsWorldScene::m_layer_showing_data = nullptr;

cocos2d::Scene* PhysicsWorldScene::createScene(int current_game_level)
{
	Scene* scene = nullptr;
	do
	{
		// 'scene' is an autorelease object
		scene = Scene::create();
		CC_BREAK_IF(!scene);
		// 'layer' is an autorelease object

		auto layer_data_showing = PhysicsWorldSceneLayerDataShowing::create();
		auto layer = PhysicsWorldSceneLayer::create();
		CC_BREAK_IF(!layer);
		CC_BREAK_IF(!layer_data_showing);

		// add layer as a child to scene
		scene->addChild(layer, 1, "ss");
		scene->addChild(layer_data_showing, 0, "sss");
		//���õ�ǰ�ؿ���
		GameLevelManager::getInstance()->setCurrentGameLevel(current_game_level);
	} while (0);
	// return the scene
	return scene;
}





//
bool PhysicsWorldSceneLayer::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Layer::init());
		Size visibleSize = Director::getInstance()->getVisibleSize();
		//do sth..

		//������Ϣ
		this->subscribe();
		//
		PhysicsWorldScene::setLayerSpr(this);

		//��ʼ������
		this->initWorldBorder();


		//��ʼ����ҷɻ�
		PlayerPlaneManager::getInstance()->CreateAPlayerPlane();
		PlayerPlaneManager::getInstance()->addToLayer(this);
		//������ʾ��Ϣ
		PlayerPlaneManager::getInstance()->updateAllShowingData();
		//
		this->setTouchEnabled(true);
		this->setSwallowsTouches(false);
		//����Ϊ���㴥��
		setTouchMode(Touch::DispatchMode::ONE_BY_ONE);


		//������Ҫschedule�ĺ���
		scheduleFunc();

		//Do Sth..
		bRet = true;
	} while (0);

	return bRet;
}



void PhysicsWorldSceneLayer::onEnter()
{
	Layer::onEnter();
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//��ʼ����ͣ��ť.
	auto pauseSprite = Sprite::createWithSpriteFrameName("gameplay.button.pause.png");
	auto pauseMenuItem = MenuItemSprite::create(pauseSprite, pauseSprite,
		CC_CALLBACK_1(PhysicsWorldSceneLayer::menuPauseCallback, this));
	auto pauseMenu = Menu::create(pauseMenuItem, NULL);
	pauseMenu->setPosition(Vec2(30, visibleSize.height - 28));
	this->addChild(pauseMenu, 20, 999);

}

void PhysicsWorldSceneLayer::onExit()
{
	Layer::onExit();
	this->stopAllActions();

	//�ֶ�����ǽ
	auto world = PhysicsManager::getInstance()->getWorld();
	world->DestroyBody(m_screen_wall);

	////�������о���
	//auto child_vec = this->getChildren();
	//for (auto elem : child_vec) {
	//	elem->removeFromParentAndCleanup(true);
	//}

	//���ٹؿ���������ǰ�ؿ�����
	GameLevelManager::getInstance()->destroyCurrentGameLevel();
	//���ٹؿ�������
	GameLevelManager::getInstance()->destroy();
	//�����ʯ����������͵л����������
	EnemyPlaneShooter::getInstance()->destroy();
	AstroidShooter::getInstance()->destroy();
	//�������������Ϊ������һЩ�д�Ķ�����
	PhysicsManager::getInstance()->clearPhysicsListener();
	//������ĵ���Ϣ
	this->unsubscribe();
	//ֹͣ���ű�������
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();

}

void PhysicsWorldSceneLayer::onEnterTransitionDidFinish()
{
	//������Ϸ����������
	SimpleAudioEngine::getInstance()->playBackgroundMusic(GameTexture::getInstance()->getTextureRelativePath("music_game_background").c_str(), true);
}

void PhysicsWorldSceneLayer::update(float dt)
{
	PhysicsManager::getInstance()->update();
}


void PhysicsWorldSceneLayer::handleGameOver(cocos2d::Ref* sender)
{
	this->scheduleOnce(
		CC_CALLBACK_0(PhysicsWorldSceneLayer::RedirectToGameOverScene, this),
		0,
		Unit::generateGuid());
}

//
bool PhysicsWorldSceneLayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{

	return false;
}




void PhysicsWorldSceneLayer::menuPauseCallback(cocos2d::Ref* sender)
{
	log("menuPauseCallback");
	if (UserDefault::getInstance()->getBoolForKey("sound_key")) {
		SimpleAudioEngine::getInstance()->playEffect(GameTexture::getInstance()->getTextureRelativePath("music_blip").c_str());
	}

	//��ͣ��ǰ���е�node
	this->pause();

	for (const auto& node : this->getChildren())
	{
		node->pause();
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//�������˵�
	auto backNormal = Sprite::createWithSpriteFrameName("gameplay.button.back.png");
	auto backSelected = Sprite::createWithSpriteFrameName("gameplay.button.back-on.png");

	auto backMenuItem = MenuItemSprite::create(backNormal, backSelected,
		CC_CALLBACK_1(PhysicsWorldSceneLayer::menuBackCallback, this));

	//������Ϸ�˵�
	auto resumeNormal = Sprite::createWithSpriteFrameName("gameplay.button.resume.png");
	auto resumeSelected = Sprite::createWithSpriteFrameName("gameplay.button.resume-on.png");

	auto resumeMenuItem = MenuItemSprite::create(
		resumeNormal,
		resumeSelected,
		CC_CALLBACK_1(PhysicsWorldSceneLayer::menuResumeCallback, this));

	menu = Menu::create(backMenuItem, resumeMenuItem, NULL);
	menu->alignItemsVertically();
	menu->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	addChild(menu, 20, 1000);
}

void PhysicsWorldSceneLayer::menuResumeCallback(cocos2d::Ref* sender)
{
	log("menuResumeCallback");
	if (UserDefault::getInstance()->getBoolForKey("sound_key")) {
		SimpleAudioEngine::getInstance()->playEffect(GameTexture::getInstance()->getTextureRelativePath("music_blip").c_str());
	}
	this->resume();

	for (const auto& node : this->getChildren())
	{
		node->resume();
	}
	removeChild(menu);
}

void PhysicsWorldSceneLayer::menuBackCallback(cocos2d::Ref* Sender)
{
	log("menuBackCallback");
	Director::getInstance()->replaceScene(HomeScene::createScene());
	if (UserDefault::getInstance()->getBoolForKey("sound_key")) {
		SimpleAudioEngine::getInstance()->playEffect(GameTexture::getInstance()->getTextureRelativePath("music_blip").c_str());
	}
}


void PhysicsWorldSceneLayer::scheduleFunc()
{
	//��������ͬ������
	scheduleUpdate();
	//ִ�йؿ�,ÿ1s��checkһ��.�ȳ�ʼ���ӳ�1s..
	schedule(CC_CALLBACK_0(PhysicsWorldSceneLayer::ExecuteGameLevel, this), 1.0f, CC_REPEAT_FOREVER, 1.0f, "ExecuteGameLevel");
	//��ʼ���ؿ�����ʱ����.
	scheduleOnce(CC_CALLBACK_0(PhysicsWorldSceneLayer::InitGameLevel, this), 0, "InitGameLevel");
}




void PhysicsWorldSceneLayer::subscribe()
{
	__NotificationCenter::getInstance()->addObserver(
		this,
		CC_CALLFUNCO_SELECTOR(PhysicsWorldSceneLayer::handleGameOver),
		string("GameLevelOver"),
		nullptr);
}

void PhysicsWorldSceneLayer::unsubscribe()
{
	__NotificationCenter::getInstance()->removeObserver(this, "GameLevelOver");
}

void PhysicsWorldSceneLayer::InitGameLevel()
{
	GameLevelManager::getInstance()->initCurrentGameLevel();
}

void PhysicsWorldSceneLayer::ExecuteGameLevel()
{
	GameLevelManager::getInstance()->processingCurrentGameLevel();
}

void PhysicsWorldSceneLayer::draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, uint32_t flags)
{
	Layer::draw(renderer, transform, flags);

	_customCmd.init(_globalZOrder, transform, flags);
	_customCmd.func = CC_CALLBACK_0(PhysicsWorldSceneLayer::onDraw, this, transform, flags);
	renderer->addCommand(&_customCmd);
}


//
bool PhysicsWorldSceneLayer::initWorldBorder()
{
	auto s = Director::getInstance()->getVisibleSize();


	///////////////////////////////��Ļ�߽�(��Ļǽ)//////////////////
	b2BodyDef screen_wall_def;
	screen_wall_def.position.Set(0, 0);

	//��������
	b2Body* screen_wall = PhysicsManager::getInstance()->getWorld()->CreateBody(&screen_wall_def);
	screen_wall->SetUserData(nullptr);

	//��������߽�...
	b2ChainShape screen_wall_shape;

	float x, y;
	b2Vec2 screen_wall_vertices[4];

	//���½�ԭ��..
	screen_wall_vertices[0] = b2Vec2(0, 0);

	//���Ͻ�..
	x = Unit::PTM(Region::Center::GetPoint(1, 1).x);
	y = Unit::PTM(Region::Center::GetPoint(1, 1).y);
	screen_wall_vertices[1] = b2Vec2(x, y);

	//���Ͻ�..
	x = Unit::PTM(Region::Center::GetPoint(1, 7).x);
	y = Unit::PTM(Region::Center::GetPoint(1, 7).y);
	screen_wall_vertices[2] = b2Vec2(x, y);

	//���½�
	x = Unit::PTM(Region::Center::GetPoint(7, 7).x);
	y = Unit::PTM(Region::Center::GetPoint(7, 7).y);
	screen_wall_vertices[3] = b2Vec2(x, y);

	screen_wall_shape.CreateLoop(screen_wall_vertices, 4);

	b2Fixture* fixture = screen_wall->CreateFixture(&screen_wall_shape, 0);
	b2Filter filter;
	filter.groupIndex = 1;
	filter.categoryBits = 1;
	filter.maskBits = 1;
	fixture->SetFilterData(filter);

	fixture->SetSensor(false);
	m_screen_wall = screen_wall;
	return true;
}

void PhysicsWorldSceneLayer::RedirectToGameOverScene()
{
	auto layer_showing_data = static_cast<PhysicsWorldSceneLayerDataShowing*>(PhysicsWorldScene::getLayerShowingData());
	Director::getInstance()->replaceScene(TransitionFade::create(1.0f, GameOverScene::createScene(layer_showing_data->getHitEnemyNumReal())));
}

void PhysicsWorldSceneLayer::onDraw(const cocos2d::Mat4& transform, uint32_t flags)
{
	Director* director = Director::getInstance();
	CCASSERT(nullptr != director, "Director is null when seting matrix stack");
	director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
	director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, transform);

	GL::enableVertexAttribs(cocos2d::GL::VERTEX_ATTRIB_FLAG_POSITION);
	PhysicsManager::getInstance()->getWorld()->DrawDebugData();
	CHECK_GL_ERROR_DEBUG();

	director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool PhysicsWorldSceneLayerDataShowing::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//
	PhysicsWorldScene::setLayerShowingData(this);

	Widget* root = static_cast<Widget*>(CSLoader::createNode(GameTexture::getInstance()->getTextureRelativePath("game_play_scene_csb")));

	this->addChild(root);
	Size frameSize = Director::getInstance()->getVisibleSize();
	root->setContentSize(frameSize);
	ui::Helper::doLayout(root);


	//��ȡ3�������ǩ
	label_hit = static_cast<Text*>(Helper::seekWidgetByName(static_cast<Widget*>(root), "label-hit"));
	label_hp = static_cast<Text*>(Helper::seekWidgetByName(static_cast<Widget*>(root), "label-hp"));
	label_missile = static_cast<Text*>(Helper::seekWidgetByName(static_cast<Widget*>(root), "label-missile"));


	////����л�����ǩ
//m_hit_enemy_label = Label::createWithTTF(MyUtility::getUTF8Char("HitEnemyNum"), GameTexture::getInstance()->getTextureRelativePath("hanyi.ttf"), 20);
//m_hit_enemy_label->setColor(Color3B(225, 225, 0));
//m_hit_enemy_label->setPosition(100, 950);
//m_hit_enemy_label->setAnchorPoint(Vec2(0, 0));
//addChild(m_hit_enemy_label, 1);

////����л�����ǩ����
//m_hit_enemy_num = Label::createWithTTF(string("0"), GameTexture::getInstance()->getTextureRelativePath("hanyi.ttf"), 20);
//m_hit_enemy_num->setColor(Color3B(225, 225, 0));
//m_hit_enemy_num->setPosition(220, 950);
//m_hit_enemy_num->setAnchorPoint(Vec2(0, 0));
//addChild(m_hit_enemy_num, 1);

////��ǰѪ����ǩ
//m_current_player_plane_hp_label = Label::createWithTTF(MyUtility::getUTF8Char("Hp"), GameTexture::getInstance()->getTextureRelativePath("hanyi.ttf"), 20);
//m_current_player_plane_hp_label->setColor(Color3B(225, 225, 0));
//m_current_player_plane_hp_label->setPosition(500, 950);
//m_current_player_plane_hp_label->setAnchorPoint(Vec2(0, 0));
//addChild(m_current_player_plane_hp_label, 1);


////��ǰѪ������

//m_current_player_plane_hp_num = Label::createWithTTF(string(""), GameTexture::getInstance()->getTextureRelativePath("hanyi.ttf"), 20);
//m_current_player_plane_hp_num->setColor(Color3B(225, 225, 0));
//m_current_player_plane_hp_num->setPosition(540, 950);
//m_current_player_plane_hp_num->setAnchorPoint(Vec2(0, 0));
//addChild(m_current_player_plane_hp_num, 1);

////������Ŀ��ǩ
//m_missile_label = Label::createWithTTF(MyUtility::getUTF8Char("MissileNum"), GameTexture::getInstance()->getTextureRelativePath("hanyi.ttf"), 20);
//m_missile_label->setColor(Color3B(225, 225, 0));
//m_missile_label->setPosition(800, 950);
//m_missile_label->setAnchorPoint(Vec2(0, 0));
//addChild(m_missile_label, 1);


////������Ŀ����
//m_missile_num = Label::createWithTTF(string(""), GameTexture::getInstance()->getTextureRelativePath("hanyi.ttf"), 20);
//m_missile_num->setColor(Color3B(225, 225, 0));
//m_missile_num->setPosition(900, 950);
//m_missile_num->setAnchorPoint(Vec2(0, 0));
//addChild(m_missile_num, 1);


	setHitEnemyNumReal(0);
	//������Ϣ
	subscribe();
	return true;
}

void PhysicsWorldSceneLayerDataShowing::updateHpNum(cocos2d::Ref* sender)
{
	if (dynamic_cast<PlayerPlane*>(sender)) {
		auto plane = dynamic_cast<PlayerPlane*>(sender);
		this->label_hp->setString(string("Hp:") + num2str(plane->getHp()));
	}
}

void PhysicsWorldSceneLayerDataShowing::updateHitEnemyNum(cocos2d::Ref* sender)
{
	setHitEnemyNumReal(getHitEnemyNumReal() + 1);
	this->label_hit->setString(string("HitEnemyNum:") + num2str(getHitEnemyNumReal()));
}

void PhysicsWorldSceneLayerDataShowing::updateMissileNum(cocos2d::Ref* sender)
{
	if (dynamic_cast<PlayerPlane*>(sender)) {
		auto plane = dynamic_cast<PlayerPlane*>(sender);
		this->label_missile->setString(string("Missile:") + num2str(plane->getCurrentMissileNum()));
	}
}

void PhysicsWorldSceneLayerDataShowing::subscribe()
{
	__NotificationCenter::getInstance()->addObserver(
		this,
		CC_CALLFUNCO_SELECTOR(PhysicsWorldSceneLayerDataShowing::updateHpNum),
		string("Mess[TimeToUpdateHpNum]"),
		nullptr);

	__NotificationCenter::getInstance()->addObserver(
		this,
		CC_CALLFUNCO_SELECTOR(PhysicsWorldSceneLayerDataShowing::updateHitEnemyNum),
		string("Mess[TimeToUpdateHitEnemyNum]"),
		nullptr);

	__NotificationCenter::getInstance()->addObserver(
		this,
		CC_CALLFUNCO_SELECTOR(PhysicsWorldSceneLayerDataShowing::updateMissileNum),
		string("Mess[TimeToUpdateMissileNum]"),
		nullptr);
}



void PhysicsWorldSceneLayerDataShowing::onExit()
{
	Layer::onExit();
	__NotificationCenter::getInstance()->removeAllObservers(this);


}







