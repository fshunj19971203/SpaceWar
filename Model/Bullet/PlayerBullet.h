
#ifndef PlayerBullet_h__
#define PlayerBullet_h__
#include "Box2D/Box2D.h"
#include "Bullet.h"

namespace SpaceWar {
	class CPhysicsSprite;



	class PlayerBullet :public Bullet
	{
	protected:
		virtual bool init();
		PlayerBullet() {};
		~PlayerBullet();
	public:
		//contact process..
		virtual void BeginContact(cocos2d::Vec2 contact, CPhysicsSprite* other);
		virtual void EndContact(cocos2d::Vec2 contact, CPhysicsSprite* other);
	private:

	};

}

#endif // PlayerBullet_h__
