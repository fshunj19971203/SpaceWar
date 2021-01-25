#include "Plane.h"
#include "ShootPattern.h"
#include "SpaceObjectAgent.h"
#include "PhysicsWorldScene.h"

using namespace std;
USING_NS_CC;
using namespace SpaceWar;

bool SpaceWar::Plane::init()
{
	SpaceObject::init();
	// 	m_shoot_bomb_pattern = nullptr;
	m_shoot_bullet_pattern = nullptr;


	//设置代理人
			//agent is an auto_release object..
	SpaceObjectAgent* agent = SpaceObjectAgent::create(true, this);
	//加入层中
	auto layer = PhysicsWorldScene::getLayerSpr();
	layer->addChild(agent);
	//
	this->setAgent(agent);

	//飞机的爆炸影响半径
	this->setBlastRadius(500);
	return true;
}

SpaceWar::Plane::~Plane()
{
	log("Plane::~Plane");
}

void SpaceWar::Plane::onEnter()
{
	SpaceObject::onEnter();

}

void SpaceWar::Plane::onExit()
{
	SpaceObject::onExit();
	//告诉代理人消亡了
	this->m_agent->m_object = nullptr;
	this->m_agent->m_valid = false;
}

ShootPattern* SpaceWar::Plane::getShootBulletPattern() const
{
	return m_shoot_bullet_pattern;
}

void SpaceWar::Plane::setShootBulletPattern(ShootPattern* shoot_bullet_pattern)
{
	m_shoot_bullet_pattern = shoot_bullet_pattern;

}

void SpaceWar::Plane::manualDestroy(float time)
{
	//告诉代理人消亡了
	this->m_agent->m_object = nullptr;
	this->m_agent->m_valid = false;

	//
	SpaceObject::manualDestroy(time);
}

