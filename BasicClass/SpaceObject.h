#ifndef SpaceObject_h__
#define SpaceObject_h__

#include <string>
#include "CPhysicsSprite.h"
#include "Box2D/Box2D.h"




namespace SpaceWar {
	class MovePattern;
	class SpaceObjectAgent;
	class SpaceObject :public CPhysicsSprite
	{
		//碰撞处理
	public:
		virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold, CPhysicsSprite* other) {};
		virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse, CPhysicsSprite* other) {};
		virtual void BeginContact(cocos2d::Vec2 contact, CPhysicsSprite* other);
		virtual void EndContact(cocos2d::Vec2 contact, CPhysicsSprite* other);

	private:
		//需要shedule的函数
		void initScheduleFunc();
	private:
		//订阅的消息
		virtual void subscribe();
		//消息处理函数
		void handleBlastForce(cocos2d::Ref* sender);
		//退订的消息
		virtual void unsubscribe();
	public:
		virtual void onEnter();
		virtual void onExit();
	protected:
		virtual bool init();
	public:
		//初始化刚体，fixtures_name是所有fixture的名字.
		void initBody(b2BodyDef body_def, const std::string& fixtures_name);
	public:
		//time s 后自毁
		virtual void manualDestroy(float time);
		void destroy();
		void destroyContent();
	public:
		//getter,setter.
		inline int getDestroyRadius() const { return m_destroy_radius; }
		inline void setDestroyRadius(int val) { m_destroy_radius = val; }
		inline bool IsEntered() { return m_state == Entered; };
		inline void SetEntered() { m_state = Entered; };
		//
		inline float getBlastRadius() const { return m_blast_radius; }
		inline void setBlastRadius(float val) { m_blast_radius = val; }

		//agent
		inline SpaceWar::SpaceObjectAgent* getAgent() const { return m_agent; }
		inline void setAgent(SpaceWar::SpaceObjectAgent* val) { m_agent = val; }

		//
		inline int getHp() const { return m_hp; }
		inline void setHp(int val) { m_hp = val; }
	protected:
		SpaceObject() {};
		virtual ~SpaceObject();
	public:
		//debug用
		virtual void speak() {};
	private:
		//Schedule函数
		void autoSetEntered();//0.5s执行一次.
		void autoShortDistanceDistroy();//1s执行一次
		void autoLongDistanceDestroy();//3.0s执行一次
		//unschedule函数
// 		void unscheduleAfter();
// 		void unscheduleAutoSetEntered();
	protected:
		//data..
		static const int NotEntered = 0;
		static const int Entered = 1;
		int m_state;
		float m_destroy_radius;//自毁半径
		b2BodyDef m_body_def;
		float m_blast_radius;//爆炸影响半径

		//运动模式，需要特别是敌机采用
		MovePattern* m_move_pattern;

		//代理人
		SpaceObjectAgent* m_agent;
		//生命值
		int m_hp;
	};

}

#endif // SpaceObject_h__






