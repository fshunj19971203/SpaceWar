#include "TestAstroid.h"
#include "Astroid.h"
#include "PhysicsObjectLoadManager.h"
#include "PhysicsManager.h"
#include "Plane.h"
#include "PlayerBullet.h"
#include "Missile.h"
#include "GameTexture.h"
#include "Region.h"
#include "Unit.h"
#include "SimpleAudioEngine.h"

using namespace std;
USING_NS_CC;
using namespace SpaceWar;
using namespace CocosDenshion;

bool SpaceWar::TestAstroid::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Astroid::init());
		Size visibleSize = Director::getInstance()->getVisibleSize();
		//Do Sth..
		this->setHp(30);



		//////////////////////设置默认body_def属性
		Vec2 pos = Vec2(Region::Up::GetPoint(4, 2));
		b2BodyDef body_def;
		body_def.type = b2_dynamicBody;
		body_def.linearVelocity = b2Vec2(0, 0);
		body_def.linearDamping = 0;
		body_def.angularVelocity = 0;
		body_def.angularDamping = 0;
		body_def.gravityScale = 0;
		body_def.angle = 0;
		body_def.position = b2Vec2(0, 0);
		body_def.fixedRotation = false;//false表示可以自旋，可以受扭力影响..
		body_def.userData = this;

		//init the body..
		this->initBody(body_def, this->m_filename);

		call_timer = 0;
		//Do Sth..
		bRet = true;
	} while (0);

	return bRet;
}

SpaceWar::TestAstroid* SpaceWar::TestAstroid::create()
{
	TestAstroid *sprite = new (std::nothrow) TestAstroid();
	if (sprite && sprite->init())
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}



SpaceWar::TestAstroid* SpaceWar::TestAstroid::create(const std::string& filename)
{
	TestAstroid *sprite = new (std::nothrow) TestAstroid();
	sprite->m_filename = filename;
	if (sprite &&
		sprite->initWithFile(GameTexture::getInstance()->getTextureRelativePath(filename)) &&
		sprite->init())
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}



void SpaceWar::TestAstroid::update(float dt)
{
	Astroid::update(dt);
}

void SpaceWar::TestAstroid::onEnter()
{
	Astroid::onEnter();
}

void SpaceWar::TestAstroid::onExit()
{
	Astroid::onExit();
}

void SpaceWar::TestAstroid::cleanup()
{
	Astroid::cleanup();
}



void SpaceWar::TestAstroid::activate()
{
	Astroid::activate();
}

void SpaceWar::TestAstroid::manualDestroy(float time)
{

	Astroid::manualDestroy(time);
}

void SpaceWar::TestAstroid::BeginContact(cocos2d::Vec2 contact, CPhysicsSprite* other)
{

	Astroid::BeginContact(contact, other);

	//和子弹碰撞
	if (dynamic_cast<Bullet*>(other)) {
		auto bullet = dynamic_cast<Bullet*>(other);
		//得到玩家子弹的速度大小...
		float bullet_speed = bullet->GetBody()->GetLinearVelocity().Length();
		this->setHp(this->getHp() - bullet_speed);
		//设置
		this->runAction(TintBy::create(0.1, 0, 255, 255));
	}


	//和飞机碰撞
	if (dynamic_cast<Plane*>(other)) {
		this->setHp(0);
		__NotificationCenter::getInstance()->postNotification("Mess[Blast]", this);
	}


	//和导弹相撞,注意，第一次的BeginContact就应该消灭，
	else if (dynamic_cast<Missile*>(other)) {
		this->setHp(0);
		__NotificationCenter::getInstance()->postNotification("Mess[Blast]", this);
	}

	
	if (this->getHp() <= 0) {
		if (call_timer == 0) {
			this->manualDestroy(0);
			__NotificationCenter::getInstance()->postNotification("Mess[Blast]", this);
			SimpleAudioEngine::getInstance()->playEffect(GameTexture::getInstance()->getTextureRelativePath("music_astroid_explosion").c_str());
			call_timer++;
		}
	}
	return;
}


void SpaceWar::TestAstroid::EndContact(cocos2d::Vec2 contact, CPhysicsSprite* other)
{
	Astroid::EndContact(contact, other);
}

SpaceWar::TestAstroid::~TestAstroid()
{

}





