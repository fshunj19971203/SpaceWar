#ifndef EnemyPlane_h__
#define EnemyPlane_h__
#include "cocos2d.h"
#include "Plane.h"
#include <string>


namespace SpaceWar {
	class MovePattern;
	class EnemyPlane :public Plane
	{
	public:
		virtual bool init();
		virtual void activate();
		virtual void shoot() = 0;
	public:
		virtual void onExit();//离开层的时候
		virtual void manualDestroy(float time);
	public:
		//处理订阅的消息
		void processPlayerPlaneMissileFiring(cocos2d::Ref* sender);
	public:

		inline void setMovePattern(MovePattern* move) { this->m_move_pattern = move; };

	protected:
		EnemyPlane() {};
		virtual ~EnemyPlane();
	public:
		//getter..setter..
		//
		cocos2d::Vec2 getSprayUnitVector();
		//
		inline cocos2d::Vec2 getMiddlePoint() const { return m_middle_point; }
		inline void setMiddlePoint(cocos2d::Vec2 val) { m_middle_point = val; }
		//
		inline cocos2d::Vec2 getSprayingLeftPoint() const { return m_spraying_left_point; }
		inline void setSprayingLeftPoint(cocos2d::Vec2 val) { m_spraying_left_point = val; }
		//
		inline cocos2d::Vec2 getSprayingRightPoint() const { return m_spraying_right_point; }
		inline void setSprayingRightPoint(cocos2d::Vec2 val) { m_spraying_right_point = val; }
		//
		inline cocos2d::Vec2 getShootingPoint() const { return m_shooting_point; }
		inline void setShootingPoint(cocos2d::Vec2 val) { m_shooting_point = val; }
		//
		inline float getShootingRate() const { return m_shooting_rate; }
		inline void setShootingRate(float val) { m_shooting_rate = val; }

		//
		inline cocos2d::Vec2 getShootingLeftPoint() const { return m_shooting_left_point; }
		inline void setShootingLeftPoint(cocos2d::Vec2 val) { m_shooting_left_point = val; }

		//
		inline cocos2d::Vec2 getShootingRightPoint() const { return m_shooting_right_point; }
		inline void setShootingRightPoint(cocos2d::Vec2 val) { m_shooting_right_point = val; }
		//

	protected:
		///////////////////////所有敌机的公共属性
		//重心点.
		cocos2d::Vec2 m_middle_point;
		//两个尾炮喷射点..
		cocos2d::Vec2 m_spraying_left_point;
		cocos2d::Vec2 m_spraying_right_point;
		//两个头炮发射点
		cocos2d::Vec2 m_shooting_left_point;
		cocos2d::Vec2 m_shooting_right_point;
		//头发射点..
		cocos2d::Vec2 m_shooting_point;
		//发射频率..
		float m_shooting_rate;

		//尾炮发射点处的喷射效果
		cocos2d::ParticleSystemQuad* m_spraying_left_point_effect;
		cocos2d::ParticleSystemQuad* m_spraying_right_point_effect;
		//对应的纹理文件名
		std::string m_filename;


	};

}

#endif // EnemyPlane_h__




