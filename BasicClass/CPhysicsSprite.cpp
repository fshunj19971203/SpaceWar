#include "CPhysicsSprite.h"
#include "PhysicsManager.h"
#include "Unit.h"
#include "Box2D/Box2D.h"

USING_NS_CC;
using std::string;
using namespace SpaceWar;





void SpaceWar::CPhysicsSprite::cleanup()
{
	Sprite::cleanup();
	if (m_body != nullptr) {
		this->detachBody();
	}
}

void SpaceWar::CPhysicsSprite::activate()
{
	m_state = Activated;
	this->setVisible(true);
	if (!m_body->IsActive()) {
		m_body->SetActive(true);
	}
}





void SpaceWar::CPhysicsSprite::activateAfter(float dt)
{
	this->scheduleOnce(
		CC_CALLBACK_0(CPhysicsSprite::activate, this),
		dt,
		Unit::generateGuid());
}

bool SpaceWar::CPhysicsSprite::init()
{
	bool bRet = false;
	do
	{
		//Do Sth..
		m_body = nullptr;
		m_state = NotActivated;
		//³õÊ¼»¯guid;
		m_guid = Unit::generateGuid();
		//Do Sth..
		bRet = true;
	} while (0);

	return bRet;

}


SpaceWar::CPhysicsSprite::~CPhysicsSprite()
{

}

void SpaceWar::CPhysicsSprite::detachBody()
{
	if (m_body != nullptr) {
		m_body->SetUserData(nullptr);
		PhysicsManager::getInstance()->getWorld()->DestroyBody(m_body);
		m_body = nullptr;
	}
}




void SpaceWar::CPhysicsSprite::synchronize()
{
	if (m_body) {
		this->setPosition(Unit::ToVec2(m_body->GetPosition()));
		this->setRotation(-1 * CC_RADIANS_TO_DEGREES(m_body->GetAngle()));
	}
}

std::string SpaceWar::CPhysicsSprite::getGuid()
{
	return m_guid;
}

