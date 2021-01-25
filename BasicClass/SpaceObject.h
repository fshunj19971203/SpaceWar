#ifndef SpaceObject_h__
#define SpaceObject_h__

#include <string>
#include "CPhysicsSprite.h"
#include "Box2D/Box2D.h"




namespace SpaceWar {
	class MovePattern;
	class SpaceObjectAgent;
	class SpaceObject :public CPhysicsSprite
	{
		//��ײ����
	public:
		virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold, CPhysicsSprite* other) {};
		virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse, CPhysicsSprite* other) {};
		virtual void BeginContact(cocos2d::Vec2 contact, CPhysicsSprite* other);
		virtual void EndContact(cocos2d::Vec2 contact, CPhysicsSprite* other);

	private:
		//��Ҫshedule�ĺ���
		void initScheduleFunc();
	private:
		//���ĵ���Ϣ
		virtual void subscribe();
		//��Ϣ������
		void handleBlastForce(cocos2d::Ref* sender);
		//�˶�����Ϣ
		virtual void unsubscribe();
	public:
		virtual void onEnter();
		virtual void onExit();
	protected:
		virtual bool init();
	public:
		//��ʼ�����壬fixtures_name������fixture������.
		void initBody(b2BodyDef body_def, const std::string& fixtures_name);
	public:
		//time s ���Ի�
		virtual void manualDestroy(float time);
		void destroy();
		void destroyContent();
	public:
		//getter,setter.
		inline int getDestroyRadius() const { return m_destroy_radius; }
		inline void setDestroyRadius(int val) { m_destroy_radius = val; }
		inline bool IsEntered() { return m_state == Entered; };
		inline void SetEntered() { m_state = Entered; };
		//
		inline float getBlastRadius() const { return m_blast_radius; }
		inline void setBlastRadius(float val) { m_blast_radius = val; }

		//agent
		inline SpaceWar::SpaceObjectAgent* getAgent() const { return m_agent; }
		inline void setAgent(SpaceWar::SpaceObjectAgent* val) { m_agent = val; }

		//
		inline int getHp() const { return m_hp; }
		inline void setHp(int val) { m_hp = val; }
	protected:
		SpaceObject() {};
		virtual ~SpaceObject();
	public:
		//debug��
		virtual void speak() {};
	private:
		//Schedule����
		void autoSetEntered();//0.5sִ��һ��.
		void autoShortDistanceDistroy();//1sִ��һ��
		void autoLongDistanceDestroy();//3.0sִ��һ��
		//unschedule����
// 		void unscheduleAfter();
// 		void unscheduleAutoSetEntered();
	protected:
		//data..
		static const int NotEntered = 0;
		static const int Entered = 1;
		int m_state;
		float m_destroy_radius;//�Իٰ뾶
		b2BodyDef m_body_def;
		float m_blast_radius;//��ըӰ��뾶

		//�˶�ģʽ����Ҫ�ر��ǵл�����
		MovePattern* m_move_pattern;

		//������
		SpaceObjectAgent* m_agent;
		//����ֵ
		int m_hp;
	};

}

#endif // SpaceObject_h__






