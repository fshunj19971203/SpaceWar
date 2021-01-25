


#ifndef PhysicsManager_h__
#define PhysicsManager_h__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "PhysicsListener.h"


namespace SpaceWar
{
	class PhysicsManager
	{
	private:
		PhysicsManager();
		virtual ~PhysicsManager();
	public:
		static PhysicsManager* getInstance();
		bool init();
		static void destroy();//游戏结束时候调用;
		void update();//更新物理世界
		void clearPhysicsListener();
		inline bool isLocked() {
			if (m_world == nullptr) {
				return false;
			}
			return m_world->IsLocked();

		}
		inline b2World* getWorld() {
			return m_world;
		}
		inline PhysicsListener* getPhysicsListener() {
			return m_ContactListener;
		}
	public:
		static float timeStep;//一般保证<0.03
		static int velocityIterations;
		static int positionIterations;
	private:
		static b2World* m_world;
		static PhysicsManager* m_instance;
		static PhysicsListener* m_ContactListener;

	};
}


#endif // CPhysicsManager_h__
