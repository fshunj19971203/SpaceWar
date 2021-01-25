#include "BlastEffectManager.h"
#include "ObserverPatternInfo.h"
#include "GameTexture.h"
#include "PhysicsWorldScene.h"
#include "CPhysicsSprite.h"
#include "Unit.h"
#include "EnemyPlane.h"
#include "Missile.h"
#include "ParticleManager.h"
#include "Astroid.h"
#include "PlayerPlane.h"

using namespace std;
USING_NS_CC;
using namespace SpaceWar;

bool SpaceWar::BlastEffectManager::init()
{
	__NotificationCenter::getInstance()->addObserver(
		this,
		CC_CALLFUNCO_SELECTOR(BlastEffectManager::handleBlast),
		string("Mess[Blast]"),
		nullptr);
	return true;
}

void SpaceWar::BlastEffectManager::handleBlast(Ref* sender)
{
	//�л���ը
	if (dynamic_cast<EnemyPlane*>(sender)) {
		auto enemy_plane = dynamic_cast<EnemyPlane*>(sender);
		//����һ�����ӱ�ըЧ��
		ParticleManager::getInstance()->setEnemyPlaneExplosionToLayer(enemy_plane->convertToWorldSpace(enemy_plane->getMiddlePoint()));
	}

	//������ը
	if (dynamic_cast<Missile*>(sender)) {
		auto missile = dynamic_cast<Missile*>(sender);
		//���ñ�ըЧ��
		ParticleManager::getInstance()->setMissileExplosionToLayer(missile->convertToWorldSpace(missile->getMiddlePoint()));
	}

	//��ʯ��ը
	if (dynamic_cast<Astroid*>(sender)) {
		auto astroid = dynamic_cast<Astroid*>(sender);
		//���ñ�ըЧ��
		ParticleManager::getInstance()->setAstroidExplosionToLayer(astroid->convertToWorldSpace(astroid->getMiddlePoint()));
	}

	//��ҷɻ���ը
	if (dynamic_cast<PlayerPlane*>(sender)) {
		auto player_plane = dynamic_cast<PlayerPlane*>(sender);
		//����һ�����ӱ�ըЧ��
		ParticleManager::getInstance()->setPlayerPlaneExplosionToLayer(player_plane->convertToWorldSpace(player_plane->getMiddlePoint()));
	}
}





SpaceWar::BlastEffectManager* SpaceWar::BlastEffectManager::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new BlastEffectManager();
		if (m_instance != nullptr) {
			m_instance->init();
		}
	}
	return m_instance;
}

void SpaceWar::BlastEffectManager::destroy()
{
	if (m_instance != nullptr)
		do { delete (m_instance); (m_instance) = nullptr; } while (0);
}

SpaceWar::BlastEffectManager* SpaceWar::BlastEffectManager::m_instance;

SpaceWar::BlastEffectManager::BlastEffectManager()
{

}

SpaceWar::BlastEffectManager::~BlastEffectManager()
{

}
