#ifndef TwistForce_h__
#define TwistForce_h__
#include "cocos2d.h"
#include "CPhysicsSprite.h"
#include "Box2D/Box2D.h"
#include <functional>


namespace SpaceWar {
	class TwistForce
	{
	public:
		static TwistForce* create(float twist_force,float start,float end,std::function<void(TwistForce*)> call);
		TwistForce*clone();
		virtual void destroy();
	public:
		TwistForce() {};
		virtual ~TwistForce();
		virtual bool init(float twist_force,float start,float end,std::function<void(TwistForce*)> call);
	public:
		float m_start;
		float m_end;
		float m_twist_force;//扭力大小.
		std::function<void(TwistForce*)> m_update_force_call;//自更新..
	};


}

#endif // TwistForce_h__


