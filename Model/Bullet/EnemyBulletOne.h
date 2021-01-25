#ifndef EnemyBulletOne_h__
#define EnemyBulletOne_h__
#include "cocos2d.h"
#include "SpaceObject.h"
#include "Box2D/Box2D.h"
#include "EnemyBullet.h"
#include <string>

namespace SpaceWar {
		class EnemyBulletOne :public EnemyBullet
			{
			public:
				static EnemyBulletOne* create();
				static EnemyBulletOne* create(const std::string& filename);
			public:
				virtual void destroy();
			public:
				//contact process
				virtual void BeginContact(b2Contact* contact, CPhysicsSprite* other);
				virtual void EndContact(b2Contact* contact, CPhysicsSprite* other);
				virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold, CPhysicsSprite* other);
				virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse, CPhysicsSprite* other);
			protected:
				EnemyBulletOne() {};
				~EnemyBulletOne();
			private:
				virtual bool init();

			};

}

#endif // EnemyBulletOne_h__
