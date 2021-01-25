#ifndef MovePatternManager_h__
#define MovePatternManager_h__
#include "cocos2d.h"
#include "Missile.h"


namespace SpaceWar {
	class MovePattern;
	class EnemyPlane;
	/*
	һ����õķ��õ�λ���ڿ����߽紦��
	*/
	class MovePatternManager {
	public:
		//methods
		bool init();
		//�õ������˶�..
	public:
		/*******************���Ƶл���********************************/
		/******************ֱ���˶�*/
		//����ֱ��
		MovePattern* getMovePatternOne(EnemyPlane* plane,int apply_force,int incr);
		//����ֱ��
		MovePattern* getMovePatternThree(EnemyPlane* plane, int apply_force);



		/******************�����˶�*/

		//������


		//����ͣ���˶����ʺϺ���׼�˶�һ��.
		MovePattern* getMovePatternTwo(EnemyPlane* plane);

		//
		MovePattern* getMovePatternFour(EnemyPlane* plane);

		//�������˶���
		MovePattern* getMovePatternFive(EnemyPlane* plane);

		//������׼������˶�!--?ר��Ϊ�ؿ�2��3����
		MovePattern* getMovePatternSpecialOne(EnemyPlane* plane);


		//ֱ�ߺ�����ת��,һֱת��ĳ���ǶȺ����ֱ��
		MovePattern* getMovePatternSeven(EnemyPlane* plane,cocos2d::Vec2 direction);


		//ֱ�ߺ�����ת��,һֱת��ĳ���ǶȺ����ֱ��
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






		/***********************���Ƶ�����*****************************/
		MovePattern* getMovePatternMissileOne(Missile* missile);

		//ֱ�߼���
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
