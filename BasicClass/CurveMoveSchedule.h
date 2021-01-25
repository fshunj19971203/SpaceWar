#ifndef CurveMoveSchedule_h__
#define CurveMoveSchedule_h__
#include "cocos2d.h"
#include "CPhysicsSprite.h"
#include "Box2D/Box2D.h"
#include "MoveSchedule.h"

using namespace std;
USING_NS_CC;
using namespace SpaceWar;


namespace SpaceWar {
	class CurveMoveSchedule:public MoveSchedule{
	public:
		//ÿ��2sִ��һ��
		void ApplyForce(float dt);
	public:
		static CurveMoveSchedule* create(CPhysicsSprite* sprite);
	protected:
		bool init(CPhysicsSprite* sprite);
	private:
		//Normal��ʾû��ˮƽ���ٶ�,right��left��ʾ��
		enum {LEFT,NORMAL,RIGHT};
		int m_pre_state;
		int m_state;
	};

}

#endif // CurveMoveSchedule_h__
