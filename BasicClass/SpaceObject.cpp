#include "SpaceObject.h"
#include "PhysicsWorldScene.h"
#include <math.h>
#include "GameSetting.h"
#include "Region.h"
#include "PhysicsObjectLoadManager.h"
#include "PhysicsManager.h"
#include "Unit.h"
#include "Plane.h"
#include "Bullet.h"
#include "PlayerBullet.h"
#include "SpaceObjectAgent.h"
#include "Astroid.h"




using namespace std;
USING_NS_CC;
using namespace SpaceWar;

bool SpaceWar::SpaceObject::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!CPhysicsSprite::init());
		//Do Sth..

		m_state = NotEntered;
		setBlastRadius(0);
		//���½�ê��..
		this->setAnchorPoint(Vec2(0, 0));

		//Ĭ��������ǽ��:SpaceObject���εĶԸ����㳤�ȵ�һ��+��Ļ�Ը����㳤�ȵ�һ�룻
		Size size = GameSetting::getInstance()->GetDesignResolutionSize();
		double screen_half_max_long = sqrt((size.width * size.width) + (size.height * size.height)) * 0.5;

		size = this->getBoundingBox().size;
		double object_max_long =
			sqrt((size.width * size.width) + (size.height * size.height));
		//this->setDestroyRadius(300);
		this->setDestroyRadius(screen_half_max_long + object_max_long);

		//��ʼ������schedule
		this->initScheduleFunc();


		//������Ϣ
		this->subscribe();
		//Do Sth..
		bRet = true;
	} while (0);

	return bRet;
}





//
void SpaceWar::SpaceObject::BeginContact(cocos2d::Vec2 contact, CPhysicsSprite* other)
{

}

void SpaceWar::SpaceObject::EndContact(cocos2d::Vec2 contact, CPhysicsSprite* other)
{

}


//??
void SpaceWar::SpaceObject::autoSetEntered()
{
	if (this->IsEntered())
	{
		//��һ�ν���
		unschedule(string("SpaceObject::autoSetEntered"));
		//���ö̾����Ի�
		this->schedule(CC_CALLBACK_0(SpaceObject::autoShortDistanceDistroy, this),
			1.0f,
			CC_REPEAT_FOREVER,
			0,
			string("SpaceObject::autoShortDistanceDistroy"));
		return;
	}

	Vec2 pos = this->getPosition();

	Vec2 screen_center = Region::Center::GetPoint(4, 4);

	if ((pos.distance(screen_center) - m_destroy_radius) < 0)
	{
		log("it is going to enter..");
		this->SetEntered();
	}

}

void SpaceWar::SpaceObject::autoShortDistanceDistroy()
{
	if (!this->IsEntered()) {
		return;
	}

	Vec2 pos = this->getPosition();

	Vec2 screen_center = Region::Center::GetPoint(4, 4);

	if (pos.distance(screen_center) > (m_destroy_radius + 30))
	{
		// 		log("it is going to remove because it reaches the Destroyed Radius!!..........");
		this->manualDestroy(0);
	}
}

void SpaceWar::SpaceObject::autoLongDistanceDestroy()
{
	Vec2 pos = this->getPosition();

	Vec2 screen_center = Region::Center::GetPoint(4, 4);

	if (pos.distance(screen_center) > (m_destroy_radius * 6))
	{
		// 		log("it is going to remove because it is too long!!........................");
		this->manualDestroy(0);
	}
}





void SpaceWar::SpaceObject::initScheduleFunc()
{
	this->schedule(CC_CALLBACK_0(SpaceObject::autoLongDistanceDestroy, this),
		1.0f,
		CC_REPEAT_FOREVER,
		0,
		string("SpaceObject::autoUnactiveIfTooLong"));

	this->schedule(CC_CALLBACK_0(SpaceObject::autoSetEntered, this),
		0.1f,
		CC_REPEAT_FOREVER,
		0,
		string("SpaceObject::autoSetEntered"));
}

void SpaceWar::SpaceObject::subscribe()
{
	__NotificationCenter::getInstance()->addObserver(
		this,
		CC_CALLFUNCO_SELECTOR(SpaceObject::handleBlastForce),
		string("Mess[Blast]"),
		nullptr);
}

void SpaceWar::SpaceObject::handleBlastForce(cocos2d::Ref* sender)
{
	auto space_object = dynamic_cast<SpaceObject*>(sender);
	Rect rect;

	if (!space_object || space_object->getBlastRadius() == 0)
		return;

	//////
	rect = space_object->getBoundingBox();

	auto space_object_middle_pos = space_object->convertToWorldSpace(Vec2(rect.size.width / 2, rect.size.height / 2));

	rect = this->getBoundingBox();
	auto this_object_middle_pos = this->convertToWorldSpace(Vec2(rect.size.width / 2, rect.size.height / 2));

	auto dist = this_object_middle_pos - space_object_middle_pos;
	auto force = dist.getNormalized();
	float blast_radius = space_object->getBlastRadius();
	if (dist.length() > blast_radius)
		return;

	// 	percentageԽС��Ҫ�ܵ�Խ�����
	auto percentage = (blast_radius - dist.length()) / blast_radius;
	if (dynamic_cast<Plane*>(this)) {
		//
		force *= 500 * percentage;
		this->GetBody()->ApplyForceToCenter(b2Vec2(force.x, force.y), true);
	}
	else if (dynamic_cast<Bullet*>(this)) {
		//
		force *= 0.04*percentage;
		this->GetBody()->ApplyForceToCenter(b2Vec2(force.x, force.y), true);
	}
	else if (dynamic_cast<Astroid*>(this)) {
		force *= 1000 * percentage;
		this->GetBody()->ApplyForceToCenter(b2Vec2(force.x, force.y), true);
	}
}

void SpaceWar::SpaceObject::unsubscribe()
{
	__NotificationCenter::getInstance()->removeObserver(this, string("Mess[Blast]"));
}

void SpaceWar::SpaceObject::onEnter()
{
	CPhysicsSprite::onEnter();
	//�Զ�����NotEnter״̬����Enter״̬..���Ҫ���ò㣬�����onEnter�У�
	auto pos = this->getPosition();
	auto layer = static_cast<const Layer*>(this->getParent());
	Rect rect = layer->getBoundingBox();
	if (rect.containsPoint(pos)) {
		this->SetEntered();
	}
}

void SpaceWar::SpaceObject::onExit()
{
	CPhysicsSprite::onExit();
	//��ȡ������
	unsubscribe();


}

void SpaceWar::SpaceObject::destroyContent()
{
	this->detachBody();
	this->removeFromParentAndCleanup(true);
}

void SpaceWar::SpaceObject::destroy()
{
	//Sprite ʧ��
	this->setVisible(false);
	this->stopAllActions();
	//bodyʧ��
	b2Body* body = this->GetBody();
	body->SetActive(false);
	//��һ֡����ɾ������
	scheduleOnce(CC_CALLBACK_0(SpaceObject::destroyContent, this), 0, Unit::generateGuid());
}

void SpaceWar::SpaceObject::manualDestroy(float time)
{
	//��ȡ������
	unsubscribe();
	//
	scheduleOnce(CC_CALLBACK_0(SpaceObject::destroy, this), time, Unit::generateGuid());
}


void SpaceWar::SpaceObject::initBody(b2BodyDef body_def, const string& fixtures_name)
{
	body_def.active = false;
	this->m_body_def = body_def;

	//create the body..
	this->SetBody(PhysicsManager::getInstance()->getWorld()->CreateBody(&this->m_body_def));

	//add fixtures to body..
	PhysicsObjectLoadManager::getInstance()->getSc()->addFixturesToBody(GetBody(), fixtures_name);

}

SpaceWar::SpaceObject::~SpaceObject()
{

}
























