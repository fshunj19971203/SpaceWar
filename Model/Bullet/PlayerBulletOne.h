#ifndef PlayerBulletOne_h__
#define PlayerBulletOne_h__
#include "cocos2d.h"
#include "SpaceObject.h"
#include "Box2D/Box2D.h"
#include "PlayerBullet.h"
#include <string>

namespace SpaceWar {
		class PlayerBulletOne :public PlayerBullet
			{
			public:
				static PlayerBulletOne* create();
				static PlayerBulletOne* create(const std::string& filename);
			public:
				virtual void destroy();
			public:
				//contact process
				virtual void BeginContact(b2Contact* contact, CPhysicsSprite* other);
				virtual void EndContact(b2Contact* contact, CPhysicsSprite* other);
				virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold, CPhysicsSprite* other);
				virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse, CPhysicsSprite* other);
			private:
				virtual bool init();
				PlayerBulletOne() {};
				~PlayerBulletOne();
			};

}

#endif // PlayerBulletOne_h__
