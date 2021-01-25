#ifndef EnemyBulletTwo_h__
#define EnemyBulletTwo_h__
#include "cocos2d.h"
#include "SpaceObject.h"
#include "Box2D/Box2D.h"
#include "EnemyBullet.h"
#include <string>

namespace SpaceWar {
	class EnemyBulletTwo :public EnemyBullet
	{
	public:
		static EnemyBulletTwo* create();
		static EnemyBulletTwo* create(const std::string& filename);
	public:
		virtual void destroy();
	public:
		//contact process
		virtual void BeginContact(b2Contact* contact, CPhysicsSprite* other);
		virtual void EndContact(b2Contact* contact, CPhysicsSprite* other);
		virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold, CPhysicsSprite* other);
		virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse, CPhysicsSprite* other);
	protected:
		EnemyBulletTwo() {};
		~EnemyBulletTwo();
	private:
		virtual bool init();
	};

}

#endif // EnemyBulletTwo_h__
