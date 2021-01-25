#ifndef MovePattern_h__
#define MovePattern_h__
#include "cocos2d.h"
#include <vector>



namespace SpaceWar {
	//前置声明
	class SprayForce;
	class TwistForce;
	class SpaceObject;
	class OutForce;

	//返回值
	struct PlaneForce {
		PlaneForce(bool a, float b, float c, float d) :valid(a), spray(b), twist(c), out(d) {};
		bool valid;//是否有效......
		float spray;//...
		float twist;
		float out;
	};


	class MovePattern {
	public:
		//
		static MovePattern* create(SpaceObject* object);
		MovePattern* clone(SpaceObject* object);
		void destroy();
	public:
		void addASprayForce(SprayForce* spray);
		void addATwistForce(TwistForce* twist);
		void addAOuterForce(OutForce* out_force);
		void setMoveFunc(std::function<void(MovePattern* move)> move);
		PlaneForce getForce();
	public:
		//construct..
		MovePattern();
		virtual ~MovePattern();
		virtual bool init(SpaceObject* object);

	public:
		//getter..setter..
		inline SpaceObject* getSpaceObject() const { return m_object; }

		inline float getTimePassed() const { return m_time_passed; }
		inline void setTimePassed(float val) { m_time_passed = val; }

	public:
		//相当于运动代码变量..具体到某个object物体都不同.
		std::function<void(MovePattern* move)> m_move;
	private:
		SpaceObject* m_object;
		float m_time_passed;
		std::vector<SprayForce*> m_spray_force_arr;
		std::vector<TwistForce*> m_twist_force_arr;
		std::vector<OutForce*> m_out_force_arr;

	};


}

#endif // MovePattern_h__










