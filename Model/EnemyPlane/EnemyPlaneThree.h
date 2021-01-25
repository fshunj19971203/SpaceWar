#ifndef EnemyPlaneThree_h__
#define EnemyPlaneThree_h__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "EnemyPlane.h"

namespace SpaceWar {
	//ǰ������
	class CPhysicsSprite;
	class EnemyPlaneThree :public EnemyPlane
	{
	public:
		static EnemyPlaneThree* create(const std::string& filename);
		EnemyPlaneThree* clone();
	public:
		//scheduel����

	public:
		virtual void update(float dt);
		virtual void onEnter();
		virtual void onExit();
		virtual void cleanup();
		//��������Ч����
		virtual void activate();
		virtual void shoot();
		virtual void move();
		virtual void manualDestroy(float time);

	public:
		//contact process
		virtual void BeginContact(cocos2d::Vec2 contact, CPhysicsSprite* other);
		virtual void EndContact(cocos2d::Vec2 contact, CPhysicsSprite* other);
	public:
		//�����ĵ���Ϣ

	private:
		virtual bool init();
		virtual void speak();
		EnemyPlaneThree() {};
		~EnemyPlaneThree();
	private:
		//�䵯��ʱ����
		float m_shoot_interval;
		int call_timer;
	};

}
#endif // EnemyPlaneThree_h__
