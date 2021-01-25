#ifndef ManagerManager_h__
#define ManagerManager_h__
#include "cocos2d.h"
#include "CPhysicsSprite.h"
#include "Box2D/Box2D.h"

namespace SpaceWar {
	/*
	大部分管理器都在程序开始时候建立，结束时候销毁
	*/
	class ManagerManager {
	public:
		//methods
		bool init();

		void initManagersOnProgramStart();
	private:
		//var

	//others.
	public:
		static ManagerManager* getInstance();
		void destroy();
	private:
		static ManagerManager* m_instance;
	private:
		ManagerManager();
		virtual ~ManagerManager();
	};


}

#endif // ManagerManager_h__
