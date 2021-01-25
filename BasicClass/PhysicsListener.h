#ifndef __PHYSICS_LISTENER_H__
#define __PHYSICS_LISTENER_H__
#include <vector>
#include "Box2D/Box2D.h"
#include "ContactInfo.h"

//当然,如果你想要另外的一套监听器来监听b2_World的碰撞检测,要自己写一个子类就可以了;


namespace SpaceWar
{
	class PhysicsListener :public b2ContactListener
	{
	public:
		PhysicsListener(void);
		virtual ~PhysicsListener(void);

		//常规碰撞
		virtual void BeginContact(b2Contact* contact);

		//常规碰撞结束
		virtual void EndContact(b2Contact* contact);

		//物理模拟前调用
		virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);

		//物理模拟后调用
		virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);

		//处理每一帧的物理碰撞事件
		void Execute();

		//
		void clearVec();
	private:
		std::vector<BeginContactInfo> m_BeginContactVec;		//记录每一帧的碰撞开始接触
		std::vector<EndContactInfo> m_EndContactVec;		//记录每一帧的碰撞结束接触
	};
}


#endif




