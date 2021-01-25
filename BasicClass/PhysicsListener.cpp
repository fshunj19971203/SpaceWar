#include "PhysicsListener.h"
#include "SpaceObject.h"
#include "ContactInfo.h"
#include "CPhysicsSprite.h"
#include "BlastEffectManager.h"
#include "Unit.h"

using namespace std;
USING_NS_CC;
using namespace SpaceWar;

SpaceWar::PhysicsListener::PhysicsListener(void)
{
	m_BeginContactVec.clear();
	m_EndContactVec.clear();
}

SpaceWar::PhysicsListener::~PhysicsListener(void)
{

}

void SpaceWar::PhysicsListener::BeginContact(b2Contact* contact)
{
	log("BeginContact");
	//��һ��CPhysicsSprite����
	CPhysicsSprite* ObjA = reinterpret_cast<CPhysicsSprite*>(contact->GetFixtureA()->GetBody()->GetUserData());
	//�ڶ���CPhysicsSprite����
	CPhysicsSprite* ObjB = reinterpret_cast<CPhysicsSprite*>(contact->GetFixtureB()->GetBody()->GetUserData());

	//��ײ��
	b2WorldManifold contact_point_info;
	contact->GetWorldManifold(&contact_point_info);
	Vec2 contact_point = Unit::ToVec2(contact_point_info.points[0]);


	//��������.
	m_BeginContactVec.push_back(BeginContactInfo(ObjA, ObjB, contact_point));
}

void SpaceWar::PhysicsListener::EndContact(b2Contact* contact)
{
	//log("EndContact");
	//��һ��CPhysicsSprite����
	CPhysicsSprite* ObjA = reinterpret_cast<CPhysicsSprite*>(contact->GetFixtureA()->GetBody()->GetUserData());
	//�ڶ���CPhysicsSprite����
	CPhysicsSprite* ObjB = reinterpret_cast<CPhysicsSprite*>(contact->GetFixtureB()->GetBody()->GetUserData());


	//��ײ��
	b2WorldManifold contact_point_info;
	contact->GetWorldManifold(&contact_point_info);
	Vec2 contact_point = Unit::ToVec2(contact_point_info.points[0]);


	//��������.
	m_EndContactVec.push_back(EndContactInfo(ObjA, ObjB, contact_point));

}

void SpaceWar::PhysicsListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
	//log("PreSolve");


}

void SpaceWar::PhysicsListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{
	//log("PostSolve");
}


//
void SpaceWar::PhysicsListener::Execute()
{
	if (!m_BeginContactVec.empty())
	{
		for (const auto & elem : m_BeginContactVec) {

			//��ObjA����
			if (elem.m_ObjA)
				elem.m_ObjA->BeginContact(elem.m_contact_point, elem.m_ObjB);

			//��ObjB����
			if (elem.m_ObjB)
				elem.m_ObjB->BeginContact(elem.m_contact_point, elem.m_ObjA);



		}
	}
	if (!m_EndContactVec.empty())
	{
		for (const auto& elem : m_EndContactVec) {
			if (elem.m_ObjA)
				elem.m_ObjA->EndContact(elem.m_contact_point, elem.m_ObjB);
			if (elem.m_ObjB)
				elem.m_ObjB->EndContact(elem.m_contact_point, elem.m_ObjA);
		}
	}

	//�������vec
	m_BeginContactVec.clear();
	m_EndContactVec.clear();

}

void SpaceWar::PhysicsListener::clearVec()
{
	m_BeginContactVec.clear();
	m_EndContactVec.clear();
}
