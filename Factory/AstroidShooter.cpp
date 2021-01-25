#include "AstroidShooter.h"
#include "PhysicsWorldScene.h"
#include "Region.h"
#include "Unit.h"
#include "GameTexture.h"
#include "TestAstroid.h"
#include "PlayerPlaneManager.h"
#include "PlayerPlane.h"


using namespace std;
USING_NS_CC;
using namespace SpaceWar;

bool SpaceWar::AstroidShooter::init()
{
	auto layer = PhysicsWorldScene::getLayerSpr();
	layer->addChild(this);
	setAstroidsPerCall(2);
	return true;
}

void SpaceWar::AstroidShooter::shootAstroid()
{
	int random_asdroid = ((rand() % 3) + 1);
	for (int i = 0; i < m_astroids_per_call; i++)
	{
		//然后射向中心就可以了！
		Vec2 pos;
		Vec2 some_point = Region::GetRandPointInRandRegions();

		Vec2 player_point;
		if (PlayerPlaneManager::getInstance()->getPlayerPlaneAgent()->isValid()) {
			auto player = static_cast<PlayerPlane*>(PlayerPlaneManager::getInstance()->getPlayerPlaneAgent()->getSpaceObject());
			player_point = player->convertToWorldSpace(player->getMiddlePoint());
		}
		//astroid speed...
		Vec2 speed = (player_point - some_point).getNormalized();
		speed = speed * 60000.0f;

		//create a astroid
		Astroid* astroid;
		switch (random_asdroid) {
		case 1:
			astroid = TestAstroid::create("Astroid1");

			break;
		case 2:
			astroid = TestAstroid::create("Astroid2");

			break;
		case 3:
			astroid = TestAstroid::create("Astroid3");

			break;
		}

		//set pos...
		b2Body* body = astroid->GetBody();
		body->SetTransform(Unit::Tob2Vec2(some_point), 0);
		astroid->synchronize();

		//apply some force..
		body->ApplyForceToCenter(Unit::Tob2Vec2(speed), true);
		body->ApplyTorque(400.0f, true);
		//add to layer...
		Layer* layer = PhysicsWorldScene::getLayerSpr();
		layer->addChild(astroid, 1, "Astroid");
		astroid->activate();
	}


}

SpaceWar::AstroidShooter* SpaceWar::AstroidShooter::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new AstroidShooter();
		if (m_instance != nullptr) {
			m_instance->init();
		}
	}
	return m_instance;
}

void SpaceWar::AstroidShooter::destroy()
{
	this->stopAllActions();
	this->removeFromParent();
	if (m_instance != nullptr)
		do { delete (m_instance); (m_instance) = nullptr; } while (0);
}

SpaceWar::AstroidShooter* SpaceWar::AstroidShooter::m_instance;

SpaceWar::AstroidShooter::AstroidShooter()
{



}

SpaceWar::AstroidShooter::~AstroidShooter()
{



}

















