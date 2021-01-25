#ifndef MoveSchedule_h__
#define MoveSchedule_h__
#include "cocos2d.h"
#include "CPhysicsSprite.h"
#include "Box2D/Box2D.h"
namespace SpaceWar {
	class MoveSchedule {
	protected:
		inline CPhysicsSprite* getSprite() const { return m_p_sprite; }
		bool init(CPhysicsSprite* sprite);
	private:
		CPhysicsSprite* m_p_sprite;
		
		};

}

#endif // MoveSchudule_h__
