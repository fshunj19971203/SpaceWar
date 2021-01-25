#ifndef ContactEfftectManager_h__
#define ContactEfftectManager_h__
#include "cocos2d.h"
#include "Box2D/Box2D.h"
namespace SpaceWar {
	class CPhysicsSprite;
	class BlastEffectManager :public cocos2d::Ref {
	public:
		//methods
		bool init();
		//�������б�ը��Ϣ
		void handleBlast(Ref* sender);
	private:

	private:
		//var

	//others.
	public:
		static BlastEffectManager* getInstance();
		static void destroy();
	private:
		static BlastEffectManager* m_instance;
	private:
		BlastEffectManager();
		virtual ~BlastEffectManager();
	};



}

#endif // ContactEfftectManager_h__
