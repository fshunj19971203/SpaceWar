#ifndef Astroid_h__
#define Astroid_h__

#include "SpaceObject.h"
#include "Box2D/Box2D.h"


namespace SpaceWar {
	class CPhysicsSprite;
	class Astroid :public SpaceObject
		{
		protected:
			virtual bool init();
			Astroid() {};
			~Astroid();


		public:
			virtual void onExit();
		public:
			 cocos2d::Vec2 getMiddlePoint();
		public:
			//contact process..
			virtual void BeginContact(cocos2d::Vec2 contact, CPhysicsSprite* other);
			virtual void EndContact(cocos2d::Vec2 contact, CPhysicsSprite* other);
		private:
	
		};
}


#endif // Stone_h__




