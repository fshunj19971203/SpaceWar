#ifndef ShootPattenManager_h__
#define ShootPattenManager_h__

#include "cocos2d.h"

namespace SpaceWar {
	class ShootPattern;
	class Plane;
	class ShootPattenManager {
	public:
		//methods
		bool init();
		//All Shooting Patterns...


		//敌机射弹模式
		//单炮孔射弹,
		ShootPattern* getShootPatternOne(Plane* plane);
		//双炮孔射弹。射向玩家飞机的中心。
		ShootPattern* getShootPatternThree(Plane* plane);
		//三炮孔射弹。射向玩家飞机的中心。
		ShootPattern* getShootPatternFive(Plane* plane);





		//玩家飞机射弹模式(只供一个玩家飞机使用！)

		//直线双弹,可以调整参数。
		ShootPattern* getShootPatternTwo(Plane* plane);



		inline float getSpTwoShootAngle() const { return spTwo_shoot_angle; }
		inline void setSpTwoShootAngle(float val);
	private:
		//var
		float spTwo_shoot_angle;
	//others.
	public:
		static ShootPattenManager* getInstance();
		static void destroy();
	private:
		static ShootPattenManager* m_instance;
	private:
		ShootPattenManager();
		virtual ~ShootPattenManager();
	};


}

#endif // ShootPattenManager_h__
