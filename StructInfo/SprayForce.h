#ifndef Forces_h__
#define Forces_h__
#include "cocos2d.h"
#include "CPhysicsSprite.h"
#include "Box2D/Box2D.h"
#include <functional>


namespace SpaceWar {
	class SprayForce
	{
	public:
		static SprayForce* create(float spray_force, float start,
			float end, std::function<void(SprayForce*)> update_call);
		SprayForce* clone();
		virtual bool init(float spray_force, float start,
			float end, std::function<void(SprayForce*)> update_call);
	public:
		float m_start;//开始秒
		float m_end;//结束秒
		float m_spray_force;//喷力大小
		std::function<void(SprayForce*)> m_update_force_call;//自更新..
	};

}

#endif // Force_h__

