#ifndef OutForce_h__
#define OutForce_h__
#include "cocos2d.h"
#include "CPhysicsSprite.h"
#include "Box2D/Box2D.h"

namespace SpaceWar {
	class OutForce
	{
	public:
		static OutForce* create(float out_force, float start, float end,std::function<void(OutForce*)> call);
		OutForce*clone();
		virtual void destroy();
	public:
		OutForce() {};
		virtual ~OutForce();
		virtual bool init(float out_force, float start,float end,std::function<void(OutForce*)> call);
	public:
		float m_start_time;
		float m_end_time;
		float m_out_force;//外力大小.
		std::function<void(OutForce*)> m_update_force_call;//自更新..
	};

}

#endif // OutForce_h__
