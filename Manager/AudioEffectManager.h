#ifndef AudioEffectManager_h__
#define AudioEffectManager_h__
#include "cocos2d.h"
#include "CPhysicsSprite.h"
#include "Box2D/Box2D.h"

namespace SpaceWar {
	class AudioEffectManager {
	public:
		//methods
		bool init();

	private:
		//var

	//others.
	public:
		static AudioEffectManager* getInstance();
		static void destroy();
	private:
		static AudioEffectManager* m_instance;
	private:
		AudioEffectManager();
		virtual ~AudioEffectManager();
	};


}

#endif // AudioEffectManager_h__
