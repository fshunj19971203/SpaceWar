#ifndef DataShared_h__
#define DataShared_h__
#include "cocos2d.h"

namespace SpaceWar {
	struct DataShared {
		//关于导弹发射的
		 struct PlayerPlaneMissileFiringInfoProcess {
			static void* spaceObject;
			static float distance;
			static void clear();
		};
	};

}

#endif // DataShared_h__
