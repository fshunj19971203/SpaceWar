#ifndef TestAsdroid_h__
#define TestAsdroid_h__
#include "cocos2d.h"
#include "CPhysicsSprite.h"
#include "Box2D/Box2D.h"
#include "Astroid.h"
#include <string>

namespace SpaceWar {
	class TestAstroid :public Astroid
	{
	public:
		static TestAstroid* create();
		static TestAstroid* create(const std::string& filename);
	public:
		virtual void update(float dt);
		virtual void onEnter();
		virtual void onExit();
		virtual void cleanup();
		//激活刚体和粒子效果等..
		virtual void activate();
		virtual void manualDestroy(float time);
	public:
		//contact process..
		virtual void BeginContact(cocos2d::Vec2 contact, CPhysicsSprite* other);
		virtual void EndContact(cocos2d::Vec2 contact, CPhysicsSprite* other);

	private:
		virtual bool init();
		TestAstroid() {};
		~TestAstroid();

	private:
		std::string m_filename;
		int call_timer;
	};

}

#endif // TestAsdroid_h__

