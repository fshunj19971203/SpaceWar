#include "PhysicsObjectLoadManager.h"
#include "GB2ShapeCache-x.h"

//
USING_NS_CC;
bool SpaceWar::PhysicsObjectLoadManager::init()
{
	/*init all the physical objects!*/

	//load the EnemyPlanes Fixtures and the 
	GB2ShapeCache::sharedGB2ShapeCache()->addShapesWithFile(
		"space_war_material/Plane.plist",CC_CONTENT_SCALE_FACTOR());

	//GB2ShapeCache::sharedGB2ShapeCache()->reLoad("space_war_material/Plane.plist", CC_CONTENT_SCALE_FACTOR());
	//load the PlayerBullets Fixtures
	//注意,子弹就不要缩小了!
	GB2ShapeCache::sharedGB2ShapeCache()->addShapesWithFile(
		"space_war_material/PlayerBullet/PlayerBullet.plist");


	//load the EnemyBullets Fixtures.
	//敌机子弹也不要搞!
	GB2ShapeCache::sharedGB2ShapeCache()->addShapesWithFile(
		"space_war_material/EnemyBullet/EnemyBullet.plist");

	//load the Astroid..
	GB2ShapeCache::sharedGB2ShapeCache()->addShapesWithFile(
		"space_war_material/Astroid/Astroid.plist",CC_CONTENT_SCALE_FACTOR());


	//load the MissileAndBomb
	GB2ShapeCache::sharedGB2ShapeCache()->addShapesWithFile(
		"space_war_material/MissileAndBomb/MissileAndBomb.plist",CC_CONTENT_SCALE_FACTOR());


	//store fixture shape cache..
	m_sc = GB2ShapeCache::sharedGB2ShapeCache();
	return true;
}

SpaceWar::PhysicsObjectLoadManager* SpaceWar::PhysicsObjectLoadManager::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new PhysicsObjectLoadManager();
		if (m_instance != nullptr) {
			m_instance->init();
		}
	}
	return m_instance;
}

void SpaceWar::PhysicsObjectLoadManager::destroy()
{
	if (m_instance != nullptr)
		do { delete (m_instance); (m_instance) = nullptr; } while (0);
}

SpaceWar::PhysicsObjectLoadManager* SpaceWar::PhysicsObjectLoadManager::m_instance;

SpaceWar::PhysicsObjectLoadManager::PhysicsObjectLoadManager()
{

}

SpaceWar::PhysicsObjectLoadManager::~PhysicsObjectLoadManager()
{

}
