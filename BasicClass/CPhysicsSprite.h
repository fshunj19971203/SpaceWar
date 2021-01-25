#ifndef CPhysicsSprite_h__
#define CPhysicsSprite_h__
#include "cocos2d.h"
#include "Box2D/Box2D.h"

//abstrct class
namespace SpaceWar
{
	class CPhysicsSprite :public cocos2d::Sprite
	{
	public:
		virtual void cleanup();
	public:
		virtual void activate();//set the body is alive.. 
		void activateAfter(float dt);
		void detachBody();//datach and distroy the body...
		void synchronize();
		//��ײ���,r
		virtual void BeginContact(cocos2d::Vec2 contact, CPhysicsSprite* other) = 0;
		virtual void EndContact(cocos2d::Vec2 contact, CPhysicsSprite* other) = 0;
		virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold, CPhysicsSprite* other) = 0;
		virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse, CPhysicsSprite* other) = 0;

		//״̬getter
		inline bool IsActivated() { return m_state == Activated; };

	public:
		inline b2Body* GetBody() { return m_body; };
		std::string getGuid();
	protected:
		inline void SetBody(b2Body* body) { m_body = body; };
		virtual bool init();//�ڲ�ͬ������������д,��ʼ����body,��shedule������!
	protected:
		CPhysicsSprite() {};
		~CPhysicsSprite();
	protected:
		static const int NotActivated = 3;
		static const int Activated = 4;
	private:
		//ÿһ��CPhysicsSprite������һ��GUID
		std::string m_guid;
		int m_state;
		b2Body* m_body;
	};
}







#endif // CPhysicsSprite_h__











