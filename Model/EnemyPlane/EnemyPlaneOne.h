#ifndef EnemyPlaneOne_h__
#define EnemyPlaneOne_h__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "EnemyPlane.h"

namespace SpaceWar {
	//前置声明
	class CPhysicsSprite;
	class EnemyPlaneOne :public EnemyPlane
	{
	public:
		static EnemyPlaneOne* create(const std::string& filename);
		EnemyPlaneOne* clone();
	public:

	public:
		virtual void update(float dt);
		virtual void onEnter();
		virtual void onExit();
		virtual void cleanup();
		//激活粒子效果等
		virtual void activate();
		virtual void shoot();
		virtual void move();
		virtual void manualDestroy(float time);

	public:
		//contact process
		virtual void BeginContact(cocos2d::Vec2 contact, CPhysicsSprite* other);
		virtual void EndContact(cocos2d::Vec2 contact, CPhysicsSprite* other);
	public:

	private:
		virtual bool init();
		virtual void speak();
		EnemyPlaneOne() {};
		~EnemyPlaneOne();
	private:
		//射弹的时间间隔
		float m_shoot_interval;
		int call_timer;
	};

}


#endif // EnemyPlaneOne_h__
