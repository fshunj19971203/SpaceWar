#ifndef ObserverPatternInfo_h__
#define ObserverPatternInfo_h__
#include "cocos2d.h"
namespace SpaceWar {

	//斥力炸弹
	class ExplosionInfo :public cocos2d::Ref {
	public:
		static ExplosionInfo* create(cocos2d::Vec2 m_explode_point, float m_affected_radius);
	public:
		//爆炸点;
		cocos2d::Vec2 m_explode_point;
		//波及半径；
		float m_affected_radius;
	private:
		bool init(cocos2d::Vec2 m_explode_point, float m_affected_radius);
	};



	//引力炸弹





	//导弹发射（导向离PlayerPlane最近的敌机）-需要一个信息共享中心保存数据，因为要信息沟通。




// 	导弹发射

	//菜单层和游戏层传递的数据
	class GameData {

	};



	//爆炸点。
	struct BlastPoint :public cocos2d::Ref {
		cocos2d::Vec2 blast_point;
	};



}

#endif // ObserverPatternInfo_h__







