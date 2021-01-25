#include "CurveMoveSchedule.h"
#include "Unit.h"

using namespace std;
USING_NS_CC;
using namespace SpaceWar;

//#CurveMoveSchedule_ApplyForce
void SpaceWar::CurveMoveSchedule::ApplyForce(float dt)
{
	log("CurveMoveSchedule::ApplyForce");
	Sprite* spr = this->getSprite();
	b2Body* body = this->getSprite()->GetBody();
	float x, y;
	spr->getPosition(&x, &y);

	if (m_state == LEFT) {
		body->ApplyForce(b2Vec2(-300, -100), body->GetPosition(), true);
		m_state = NORMAL;
		m_pre_state = LEFT;
	}
	else if(m_state == NORMAL) {
		if (m_pre_state == LEFT)
		{
			
			body->ApplyForce(b2Vec2(300, 100), body->GetPosition(), true);
			m_state = RIGHT;
			m_pre_state = NORMAL;
		}
		else if(m_pre_state == RIGHT)
		{
			body->ApplyForce(b2Vec2(-300, -100), body->GetPosition(), true);
			m_state = LEFT;
			m_pre_state = NORMAL;
		}
	}
	else if (m_state == RIGHT) {
		body->ApplyForce(b2Vec2(300, 100), body->GetPosition(), true);
		m_state = NORMAL;
		m_pre_state = RIGHT;
	}
	return;
}

SpaceWar::CurveMoveSchedule* SpaceWar::CurveMoveSchedule::create(CPhysicsSprite* sprite)
{

	CurveMoveSchedule* sch = new CurveMoveSchedule();
	if (sch && sch->init(sprite)) {
		return sch;
	}
	CC_SAFE_DELETE(sch);
	return nullptr;
}

bool SpaceWar::CurveMoveSchedule::init(CPhysicsSprite* sprite)
{
	m_state = LEFT;
	return MoveSchedule::init(sprite);
}


