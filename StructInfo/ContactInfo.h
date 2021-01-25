
#ifndef ContactInfo_h__
#define ContactInfo_h__


#include "Box2D/Box2D.h"
#include "cocos2d.h"
namespace SpaceWar {

	class CPhysicsSprite;
	struct BeginContactInfo
	{
		CPhysicsSprite* m_ObjA;
		CPhysicsSprite* m_ObjB;
		cocos2d::Vec2 m_contact_point;
		BeginContactInfo() {};
		BeginContactInfo(CPhysicsSprite* ObjA, CPhysicsSprite* ObjB, cocos2d::Vec2 point) :m_ObjA(ObjA), m_ObjB(ObjB), m_contact_point(point) {};
	};

	struct EndContactInfo
	{
		CPhysicsSprite* m_ObjA;
		CPhysicsSprite* m_ObjB;
		cocos2d::Vec2 m_contact_point;
		EndContactInfo() {};
		EndContactInfo(CPhysicsSprite* ObjA, CPhysicsSprite* ObjB, cocos2d::Vec2 point) :m_ObjA(ObjA), m_ObjB(ObjB), m_contact_point(point) {};

	};
	

}

#endif // BeginContactInfo_h__
