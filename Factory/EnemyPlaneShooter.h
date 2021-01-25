#ifndef EnemyPlaneShooter_h__
#define EnemyPlaneShooter_h__
#include "cocos2d.h"


namespace SpaceWar {
	class EnemyPlaneShooter:public cocos2d::Node {
	public:
		//methods
		virtual bool init();
		void ShootANotShootingEnmeyPlane();
		void ShootAShootingEnemyPlane();
		inline int getEnemPerCall() const { return m_enemy_per_call; }
		inline void setEnemyPerCall(int val) { m_enemy_per_call = val; }
	private:
		//var
				//shooting frequence..
		int m_enemy_per_call;
		//others.
	public:
		static EnemyPlaneShooter* getInstance();
		void destroy();
	private:
		static EnemyPlaneShooter* m_instance;
	private:
		EnemyPlaneShooter();
		virtual ~EnemyPlaneShooter();
	};


}

#endif // EnemyPlaneShooter_h__
