#include "PhysicsManager.h"
#include "PhysicsListener.h"
#include "GameSetting.h"
#include "Unit.h"

using namespace std;
USING_NS_CC;
using namespace SpaceWar;



SpaceWar::PhysicsManager::PhysicsManager()
{

}
// @@info@@num:7
SpaceWar::PhysicsManager::~PhysicsManager()
{
	CC_SAFE_DELETE(m_instance);
	CC_SAFE_DELETE(m_ContactListener);
	if (m_world != nullptr)
		CC_SAFE_DELETE(m_world);
}

PhysicsManager* SpaceWar::PhysicsManager::getInstance()
{

	if (m_instance == nullptr)
	{
		m_instance = new PhysicsManager();
		if (m_instance != nullptr) {
			m_instance->init();
		}
	}
	return m_instance;
}

bool SpaceWar::PhysicsManager::init()
{
	//������ײ������
	m_ContactListener = new PhysicsListener();
	//��ʼ����������
	b2Vec2 gravity;
	gravity.Set(0.0f, 0.0f);
	m_world = new b2World(gravity);

	//������ײ������
	m_world->SetContactListener(m_ContactListener);

	//�����������
	m_world->SetAllowSleeping(true);

	//����������ײ
	m_world->SetContinuousPhysics(true);

	return true;
}



void SpaceWar::PhysicsManager::destroy()
{
	//�ݻ���������ȫ������
	if (m_world != nullptr)
		do { delete (m_world); (m_world) = nullptr; } while (0);
	//�ݻټ�����
	if (m_ContactListener != nullptr)
		do { delete (m_ContactListener); (m_ContactListener) = nullptr; } while (0);

	//�ݻ�PhysicsManager����
	if (m_instance != nullptr)
		do { delete (m_instance); (m_instance) = nullptr; } while (0);
}

//
void SpaceWar::PhysicsManager::update()
{

	//the listener dispatches it to the contacted object to process over..
	m_ContactListener->Execute();
	//physical emulation..
	m_world->Step(timeStep, velocityIterations, positionIterations);
	//synchronize the sprite.. 
	for (b2Body* body = m_world->GetBodyList(); body; body = body->GetNext())
	{
		if (body->IsActive() && body->IsAwake()) {
			Sprite* sprite = static_cast<Sprite*>(body->GetUserData());
			if (sprite) {
				sprite->setPosition(Unit::ToVec2(body->GetPosition()));
				sprite->setRotation(-1 * CC_RADIANS_TO_DEGREES(body->GetAngle()));
			}
		}


	}
}


void SpaceWar::PhysicsManager::clearPhysicsListener()
{
	m_ContactListener->clearVec();
}

b2World* SpaceWar::PhysicsManager::m_world = nullptr;

PhysicsManager* SpaceWar::PhysicsManager::m_instance = nullptr;


PhysicsListener* SpaceWar::PhysicsManager::m_ContactListener = nullptr;


float SpaceWar::PhysicsManager::timeStep = 0.03f;

int SpaceWar::PhysicsManager::velocityIterations = 8;

int SpaceWar::PhysicsManager::positionIterations = 3;



