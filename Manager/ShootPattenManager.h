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


		//�л��䵯ģʽ
		//���ڿ��䵯,
		ShootPattern* getShootPatternOne(Plane* plane);
		//˫�ڿ��䵯��������ҷɻ������ġ�
		ShootPattern* getShootPatternThree(Plane* plane);
		//���ڿ��䵯��������ҷɻ������ġ�
		ShootPattern* getShootPatternFive(Plane* plane);





		//��ҷɻ��䵯ģʽ(ֻ��һ����ҷɻ�ʹ�ã�)

		//ֱ��˫��,���Ե���������
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
