#ifndef AstroidShooter_h__
#define AstroidShooter_h__
#include "cocos2d.h"
#include "Box2D/Box2D.h"

namespace SpaceWar {
	class AstroidShooter :public cocos2d::Node{
	public:
		//methods
		bool init();
		void shootAstroid();
		inline int getAstroidsPerCall() const { return m_astroids_per_call; }
		inline void setAstroidsPerCall(int val) { m_astroids_per_call = val; }
	private:
		
		//var
		//shooting frequence..
		int m_astroids_per_call;
	//others.
	public:
		static AstroidShooter* getInstance();
		void destroy();
	private:
		static AstroidShooter* m_instance;
	private:
		AstroidShooter();
		virtual ~AstroidShooter();
	};
	

}

#endif // AstroidShooter_h__
