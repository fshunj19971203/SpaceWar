#ifndef __PHYSICS_LISTENER_H__
#define __PHYSICS_LISTENER_H__
#include <vector>
#include "Box2D/Box2D.h"
#include "ContactInfo.h"

//��Ȼ,�������Ҫ�����һ�׼�����������b2_World����ײ���,Ҫ�Լ�дһ������Ϳ�����;


namespace SpaceWar
{
	class PhysicsListener :public b2ContactListener
	{
	public:
		PhysicsListener(void);
		virtual ~PhysicsListener(void);

		//������ײ
		virtual void BeginContact(b2Contact* contact);

		//������ײ����
		virtual void EndContact(b2Contact* contact);

		//����ģ��ǰ����
		virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);

		//����ģ������
		virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);

		//����ÿһ֡��������ײ�¼�
		void Execute();

		//
		void clearVec();
	private:
		std::vector<BeginContactInfo> m_BeginContactVec;		//��¼ÿһ֡����ײ��ʼ�Ӵ�
		std::vector<EndContactInfo> m_EndContactVec;		//��¼ÿһ֡����ײ�����Ӵ�
	};
}


#endif




