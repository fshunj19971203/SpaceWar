#ifndef Bullet_h__
#define Bullet_h__
#include "SpaceObject.h"
#include "cocos2d.h"


namespace SpaceWar {
	class Bullet :public SpaceObject
	{

	protected:
		virtual bool init();
		Bullet() {};
		~Bullet();
	public:
		//玩家子弹和敌机子弹初始化时候，玩家子弹向上的，
		virtual cocos2d::Vec2 getDirection();
		//inline int getState() const { return state; };
		//getter,setter..
	private:
		//int state;

	};

}





#endif // Bullet_h__






