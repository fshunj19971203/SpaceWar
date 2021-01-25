#ifndef ParticleManager_h__
#define ParticleManager_h__
#include "cocos2d.h"

namespace SpaceWar {
	class ParticleManager:public cocos2d::Node{
	public:
		//methods
		bool init();


		//�л���ը��Ч..�����ģ�4s������
		cocos2d::ParticleSystemQuad* setEnemyPlaneExplosionToLayer(cocos2d::Vec2 world_point);
		//������ը��Ч,������У�4s������
		cocos2d::ParticleSystemQuad* setMissileExplosionToLayer(cocos2d::Vec2 world_point);
		//��ʯ��ըЧ����������У�4s����ʧ
		cocos2d::ParticleSystemQuad* setAstroidExplosionToLayer(cocos2d::Vec2 world_point);
		//��ҷɻ���ը������У�4s����ʧ
		cocos2d::ParticleSystemQuad* setPlayerPlaneExplosionToLayer(cocos2d::Vec2 world_point);







		//��������
		void destroyEnemyPlaneExplosion();
		void destroyMissileExplosion();
		void destroyAstroidExplosion();
		void destroyPlayerPlanedExplosion();


	private:
		//var
	//others.
	public:
		static ParticleManager* getInstance();
		static void destroy();
	private:
		static ParticleManager* m_instance;
	private:
		ParticleManager();
		virtual ~ParticleManager();
	};


}

#endif // ParticleManager_h__

