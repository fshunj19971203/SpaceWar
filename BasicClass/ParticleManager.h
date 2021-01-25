#ifndef ParticleManager_h__
#define ParticleManager_h__
#include "cocos2d.h"

namespace SpaceWar {
	class ParticleManager:public cocos2d::Node{
	public:
		//methods
		bool init();


		//敌机爆炸特效..加入层的，4s后消除
		cocos2d::ParticleSystemQuad* setEnemyPlaneExplosionToLayer(cocos2d::Vec2 world_point);
		//导弹爆炸特效,加入层中，4s后消除
		cocos2d::ParticleSystemQuad* setMissileExplosionToLayer(cocos2d::Vec2 world_point);
		//陨石爆炸效果，加入层中，4s后消失
		cocos2d::ParticleSystemQuad* setAstroidExplosionToLayer(cocos2d::Vec2 world_point);
		//玩家飞机爆炸加入层中，4s后消失
		cocos2d::ParticleSystemQuad* setPlayerPlaneExplosionToLayer(cocos2d::Vec2 world_point);







		//消除函数
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

