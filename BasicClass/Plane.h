#ifndef Plane_h__
#define Plane_h__
#include "SpaceObject.h"



namespace SpaceWar {
	class ShootPattern;


	class Plane :public SpaceObject
	{
	protected:
		virtual bool init();
		Plane() {};
		virtual ~Plane();
		virtual void onEnter();
		virtual void onExit();
	public:
		//getter,setter
		ShootPattern* getShootBulletPattern()const;
		void setShootBulletPattern(ShootPattern* shoot_bullet_pattern);
		virtual void manualDestroy(float time);
	protected:

		//子弹发弹模式
		ShootPattern* m_shoot_bullet_pattern;
		//int m_state;
	};

}


#endif // Plane_h__







