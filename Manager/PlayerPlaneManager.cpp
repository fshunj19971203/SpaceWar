#include "PlayerPlaneManager.h"
#include "Unit.h"
#include "TestPlayerPlane.h"
#include "PhysicsWorldScene.h"
#include "GameTexture.h"
#include "PhysicsManager.h"
#include "ShootPattenManager.h"
#include "Region.h"
#include "SpaceObject.h"


using namespace std;
USING_NS_CC;
using namespace SpaceWar;

bool SpaceWar::PlayerPlaneManager::init()
{

	return true;
}




void SpaceWar::PlayerPlaneManager::CreateAPlayerPlane()
{

	TestPlayerPlane* plane = TestPlayerPlane::create("TestPlayerPlane");

	//set some important traits..
	auto pos = Region::Center::GetPoint(4, 4);
	plane->GetBody()->SetTransform(Unit::Tob2Vec2(pos), 0);
	plane->synchronize();
	//set shooting pattern..
	plane->setShootBulletPattern(ShootPattenManager::getInstance()->getShootPatternTwo(plane));

	m_player_plane = plane;
	m_player_plane_agent = plane->getAgent();
}

void SpaceWar::PlayerPlaneManager::addToLayer(cocos2d::Layer* layer)
{

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [=](Touch* touch, Event* ev)->bool {
		if (this->getPlayerPlaneAgent()->isValid())
		{
			Size s = m_player_plane->getContentSize();
			Rect rect = Rect{ 0,0,s.width,s.height };
			Vec2 pt = m_player_plane->convertToNodeSpace(touch->getLocation());
			if (rect.containsPoint(pt))
			{
				m_player_plane->shootAMissile();
			}
		}

		if (this->getPlayerPlaneAgent()->isValid())
		{
			auto cur_pos = touch->getLocation();
			auto plane_pos = m_player_plane->getPosition();
			CCLOG("***********************************HHH");
			auto direct = cur_pos - plane_pos;
			b2Body* body = m_player_plane->GetBody();
			body->ApplyLinearImpulse(b2Vec2(Unit::PTM(direct.x * 30), Unit::PTM(direct.y * 30)), body->GetWorldCenter(), true);
		}

		return true;
	};
	listener->onTouchMoved = [=](Touch* touch, Event* ev)->void {

	};
	listener->onTouchEnded = [=](Touch* touch, Event* ev)->void {
		if (this->getPlayerPlaneAgent()->isValid())
		{
			b2Body* body = m_player_plane->GetBody();
			body->SetLinearVelocity(b2Vec2(0, 0));
		}

		CCLOG("End");
	};

	//listener->setSwallowTouches(false);


	//auto listener1 = EventListenerTouchOneByOne::create();
	//listener1->onTouchBegan = [=](Touch* touch, Event* ev)->bool {
	//	auto cur_pos = touch->getLocation();
	//	auto prev_pos = touch->getLocation();
	//	auto direct = cur_pos - prev_pos;
	//	direct.normalize();
	//	if (this->getPlayerPlaneAgent()->isValid())
	//	{
	//		CCLOG("APPly 1!!");
	//		b2Body* body = m_player_plane->GetBody();
	//		body->ApplyForceToCenter(Unit::Tob2Vec2(direct * 100000), true);
	//	}
	//	return true;
	//};
	//listener1->onTouchMoved = [=](Touch* touch, Event* ev)->void {

	//};
	//listener1->onTouchEnded = [=](Touch* touch, Event* ev)->void {
	//};


	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, -10);
	//Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener1, -1);
	////添加监听器
	//EventDispatcher* eventDispatcher = Director::getInstance()->getEventDispatcher();
	//auto listener = EventListenerKeyboard::create();
	////第二个参数一定是TestPlayerPlane的指针
	//listener->onKeyPressed = CC_CALLBACK_2(TestPlayerPlane::keyPressed, m_player_plane);
	//listener->onKeyReleased = CC_CALLBACK_2(TestPlayerPlane::keyReleased, m_player_plane);
	//加入层中
	layer->addChild(m_player_plane);
	//激活
	m_player_plane->activate();
}





SpaceObjectAgent* SpaceWar::PlayerPlaneManager::getPlayerPlaneAgent()
{
	return m_player_plane_agent;
}

void SpaceWar::PlayerPlaneManager::updateAllShowingData()
{
	TestPlayerPlane* player_plane;
	if (this->getPlayerPlaneAgent()->isValid()) {
		player_plane = static_cast<TestPlayerPlane*>(this->getPlayerPlaneAgent()->getSpaceObject());
		NotificationCenter::getInstance()->postNotification("Mess[TimeToUpdateHpNum]", player_plane);
		NotificationCenter::getInstance()->postNotification("Mess[TimeToUpdateMissileNum]", player_plane);

	}
}

SpaceWar::PlayerPlaneManager* SpaceWar::PlayerPlaneManager::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new PlayerPlaneManager();
		if (m_instance != nullptr) {
			m_instance->init();
		}
	}
	return m_instance;
}



void SpaceWar::PlayerPlaneManager::destroy()
{
	//销毁注意，PlayerPlaneManager只是产生玩家飞机，不会销毁
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	if (m_instance != nullptr)
		do { delete (m_instance); (m_instance) = nullptr; } while (0);
}



SpaceWar::PlayerPlaneManager* SpaceWar::PlayerPlaneManager::m_instance;

SpaceWar::PlayerPlaneManager::PlayerPlaneManager()
{

}

SpaceWar::PlayerPlaneManager::~PlayerPlaneManager()
{

}
