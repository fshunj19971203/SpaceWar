#ifndef ObserverPatternInfo_h__
#define ObserverPatternInfo_h__
#include "cocos2d.h"
namespace SpaceWar {

	//����ը��
	class ExplosionInfo :public cocos2d::Ref {
	public:
		static ExplosionInfo* create(cocos2d::Vec2 m_explode_point, float m_affected_radius);
	public:
		//��ը��;
		cocos2d::Vec2 m_explode_point;
		//�����뾶��
		float m_affected_radius;
	private:
		bool init(cocos2d::Vec2 m_explode_point, float m_affected_radius);
	};



	//����ը��





	//�������䣨������PlayerPlane����ĵл���-��Ҫһ����Ϣ�������ı������ݣ���ΪҪ��Ϣ��ͨ��




// 	��������

	//�˵������Ϸ�㴫�ݵ�����
	class GameData {

	};



	//��ը�㡣
	struct BlastPoint :public cocos2d::Ref {
		cocos2d::Vec2 blast_point;
	};



}

#endif // ObserverPatternInfo_h__







