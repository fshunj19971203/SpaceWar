#ifndef TestBullet_h__
#define TestBullet_h__
#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "PlayerBullet.h"


//#TestPlayerBullet
namespace SpaceWar {
	class CPhysicsSprite;
	class TestPlayerBullet :public PlayerBullet
	{
	public:
		static TestPlayerBullet* create(const std::string& filename);
		TestPlayerBullet* clone();
		inline std::string getFilename() const { return m_filename; }
		inline void setFilename(std::string val) { m_filename = val; }
	public:
		virtual void update(float dt);
		virtual void onEnter();
		virtual void onExit();
		virtual void cleanup();
		//激活刚体和粒子效果等..
		virtual void activate();
	public:
		//contact process
		virtual void BeginContact(cocos2d::Vec2 contact, CPhysicsSprite* other);
		virtual void EndContact(cocos2d::Vec2 contact, CPhysicsSprite* other);

	private:
		virtual bool init();
		TestPlayerBullet() {};
		~TestPlayerBullet();
	private:
		std::string m_filename;
	};

}

#endif // TestBullet_h__


