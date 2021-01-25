
#ifndef EnemyBullet_h__
#define EnemyBullet_h__
#include "Bullet.h"
#include "Box2D/Box2D.h"

namespace SpaceWar {
	class CPhysicsSprite;

	class EnemyBullet :public Bullet
	{
	protected:
		virtual bool init();
		EnemyBullet() {};
		~EnemyBullet();
	public:
		
		//Åö×²¼ì²â
		virtual void BeginContact(cocos2d::Vec2 contact, CPhysicsSprite* other);
		virtual void EndContact(cocos2d::Vec2 contact, CPhysicsSprite* other);
		virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold, CPhysicsSprite* other);
		virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse, CPhysicsSprite* other);

	private:

	};

}

#endif // EnemyBullet_h__
