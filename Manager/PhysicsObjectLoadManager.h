#ifndef PhysicsObjectLoadManager_h__
#define PhysicsObjectLoadManager_h__

#include "cocos2d.h"
#include "GB2ShapeCache-x.h"

namespace SpaceWar {
	class PhysicsObjectLoadManager {
	public:
		//methods
		bool init();

		inline cocos2d::GB2ShapeCache* getSc() const { return m_sc; }
	private:
		//var
		cocos2d::GB2ShapeCache* m_sc;
	//others.
	public:
		static PhysicsObjectLoadManager* getInstance();
		static void destroy();
	private:
		static PhysicsObjectLoadManager* m_instance;
	private:
		PhysicsObjectLoadManager();
		virtual ~PhysicsObjectLoadManager();
	};
	

}

#endif // PhysicsObjectLoadManager_h__
