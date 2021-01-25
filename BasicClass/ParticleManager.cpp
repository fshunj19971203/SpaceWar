#include "ParticleManager.h"
#include "GameTexture.h"
#include "PhysicsWorldScene.h"
#include "Unit.h"


using namespace std;
USING_NS_CC;
using namespace SpaceWar;

bool SpaceWar::ParticleManager::init()
{
	return true;
}

cocos2d::ParticleSystemQuad* SpaceWar::ParticleManager::setEnemyPlaneExplosionToLayer(cocos2d::Vec2 world_point)
{
	auto effect = ParticleSystemQuad::create(GameTexture::getInstance()->getTextureRelativePath("enemy_plane_explosion"));

	effect->setPositionType(ParticleSystem::PositionType::RELATIVE);
	effect->setPosition(world_point);
	effect->setVisible(true);

	auto layer = PhysicsWorldScene::getLayerSpr();
	layer->addChild(effect, 1, "enemy_plane_explosion");
	//这里最重要，因为getEnemyPlaneExplosion可能被连续调用多次的，因此每一个scheduleOnce必须唯一。
	this->scheduleOnce(CC_CALLBACK_0(ParticleManager::destroyEnemyPlaneExplosion, this),
		4.0f,
		Unit::generateGuid());

	return effect;

}

cocos2d::ParticleSystemQuad* SpaceWar::ParticleManager::setMissileExplosionToLayer(cocos2d::Vec2 world_point)
{
	auto effect = ParticleSystemQuad::create(GameTexture::getInstance()->getTextureRelativePath("miss_explosion"));

	effect->setPositionType(ParticleSystem::PositionType::RELATIVE);
	effect->setPosition(world_point);
	effect->setVisible(true);

	auto layer = PhysicsWorldScene::getLayerSpr();
	layer->addChild(effect, 1, "miss_explosion");

	this->scheduleOnce(CC_CALLBACK_0(ParticleManager::destroyMissileExplosion, this),
		4.0f,
		Unit::generateGuid());

	return effect;
}

cocos2d::ParticleSystemQuad* SpaceWar::ParticleManager::setAstroidExplosionToLayer(cocos2d::Vec2 world_point)
{
	auto effect = ParticleSystemQuad::create(GameTexture::getInstance()->getTextureRelativePath("astroid_explosion.plist"));

	effect->setPositionType(ParticleSystem::PositionType::RELATIVE);
	effect->setPosition(world_point);
	effect->setVisible(true);

	auto layer = PhysicsWorldScene::getLayerSpr();
	layer->addChild(effect, 1, "astroid_explosion");

	this->scheduleOnce(CC_CALLBACK_0(ParticleManager::destroyAstroidExplosion, this),
		4.0f,
		Unit::generateGuid());

	return effect;
}

cocos2d::ParticleSystemQuad* SpaceWar::ParticleManager::setPlayerPlaneExplosionToLayer(cocos2d::Vec2 world_point)
{
	auto effect = ParticleSystemQuad::create(GameTexture::getInstance()->getTextureRelativePath("player_plane_explosion"));

	effect->setPositionType(ParticleSystem::PositionType::RELATIVE);
	effect->setPosition(world_point);
	effect->setVisible(true);

	auto layer = PhysicsWorldScene::getLayerSpr();
	layer->addChild(effect, 1, "player_plane_explosion");
	//这里最重要，因为getEnemyPlaneExplosion可能被连续调用多次的，因此每一个scheduleOnce必须唯一。
	this->scheduleOnce(CC_CALLBACK_0(ParticleManager::destroyPlayerPlanedExplosion, this),
		4.0f,
		Unit::generateGuid());

	return effect;
}

void SpaceWar::ParticleManager::destroyEnemyPlaneExplosion()
{
	auto layer = PhysicsWorldScene::getLayerSpr();
	layer->removeChildByName("enemy_plane_explosion", true);
}

void SpaceWar::ParticleManager::destroyMissileExplosion()
{
	auto layer = PhysicsWorldScene::getLayerSpr();
	layer->removeChildByName("miss_explosion", true);
}

void SpaceWar::ParticleManager::destroyAstroidExplosion()
{
	auto layer = PhysicsWorldScene::getLayerSpr();
	layer->removeChildByName("astroid_explosion", true);
}

void SpaceWar::ParticleManager::destroyPlayerPlanedExplosion()
{
	auto layer = PhysicsWorldScene::getLayerSpr();
	layer->removeChildByName("player_plane_explosion", true);
}

SpaceWar::ParticleManager* SpaceWar::ParticleManager::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new ParticleManager();
		if (m_instance != nullptr) {
			m_instance->init();
		}
	}
	return m_instance;
}

void SpaceWar::ParticleManager::destroy()
{
	if (m_instance != nullptr)
		do { delete (m_instance); (m_instance) = nullptr; } while (0);
}

SpaceWar::ParticleManager* SpaceWar::ParticleManager::m_instance;

SpaceWar::ParticleManager::ParticleManager()
{

}

SpaceWar::ParticleManager::~ParticleManager()
{

}
