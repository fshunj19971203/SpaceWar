#ifndef MovePatternManager_h__
#define MovePatternManager_h__
#include "cocos2d.h"
#include "Missile.h"


namespace SpaceWar {
	class MovePattern;
	class EnemyPlane;
	/*
	一般放置的放置的位置在靠近边界处。
	*/
	class MovePatternManager {
	public:
		//methods
		bool init();
		//得到各种运动..
	public:
		/*******************控制敌机的********************************/
		/******************直线运动*/
		//加速直线
		MovePattern* getMovePatternOne(EnemyPlane* plane,int apply_force,int incr);
		//匀速直线
		MovePattern* getMovePatternThree(EnemyPlane* plane, int apply_force);



		/******************其他运动*/

		//抛物线


		//慢慢停下运动，适合和瞄准运动一起.
		MovePattern* getMovePatternTwo(EnemyPlane* plane);

		//
		MovePattern* getMovePatternFour(EnemyPlane* plane);

		//螺旋线运动！
		MovePattern* getMovePatternFive(EnemyPlane* plane);

		//带有瞄准射击的运动!--?专门为关卡2和3服务。
		MovePattern* getMovePatternSpecialOne(EnemyPlane* plane);


		//直线后向左转弯,一直转到某个角度后继续直线
		MovePattern* getMovePatternSeven(EnemyPlane* plane,cocos2d::Vec2 direction);


		//直线后向右转弯,一直转到某个角度后继续直线
		MovePattern* getMovePatternEight(EnemyPlane* plane,cocos2d::Vec2 direction);


		//
		MovePattern* getMovePatternNine(EnemyPlane* plane);

		//
		MovePattern* getMovePatternTen(EnemyPlane* plane);

		//
		MovePattern* getMovePatternEleven(EnemyPlane* plane);

		//
		MovePattern* getMovePatternTwelve(EnemyPlane* plane);

		//
		MovePattern* getMovePatternThirteen(EnemyPlane* plane);

		//
		MovePattern* getMovePatternFourteen(EnemyPlane* plane);

		//
		MovePattern* getMovePatternFifteen(EnemyPlane* plane);

		//
		MovePattern* getMovePatterSixteen(EnemyPlane* plane);


		//
		MovePattern* getMovePatterSeventeen(EnemyPlane* plane);

		//
		MovePattern* getMovePatterEighteen(EnemyPlane* plane);


		//
		MovePattern* getMovePatterNineteen(EnemyPlane* plane);


		//
		MovePattern* getMovePatterTwenty(EnemyPlane* plane);






		/***********************控制导弹的*****************************/
		MovePattern* getMovePatternMissileOne(Missile* missile);

		//直线加速
		MovePattern* getMovePatternMissileTwo(Missile* missile);

	private:
		//var

	//others.
	public:
		static MovePatternManager* getInstance();
		static void destroy();
	private:
		static MovePatternManager* m_instance;
	private:
		MovePatternManager();
		virtual ~MovePatternManager();
	};


}

#endif // MovePatternManager_h__
