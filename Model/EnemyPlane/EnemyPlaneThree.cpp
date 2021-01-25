#include "EnemyPlaneThree.h"
#include "PlayerBullet.h"
#include "GameTexture.h"
#include "ShootPattern.h"
#include "Unit.h"
#include "SprayForce.h"
#include "TwistForce.h"
#include "MovePattern.h"
#include "Time.h"
#include "ShootPattenManager.h"
#include "Region.h"
#include "ObserverPatternInfo.h"
#include "Missile.h"
#include "ParticleManager.h"
#include "SimpleAudioEngine.h"
#include "PlayerPlane.h"


using namespace std;
USING_NS_CC;
using namespace SpaceWar;
using namespace CocosDenshion;


void SpaceWar::EnemyPlaneThree::update(float dt)
{
	EnemyPlane::update(dt);
}

void SpaceWar::EnemyPlaneThree::onEnter()
{
	EnemyPlane::onEnter();
}

void SpaceWar::EnemyPlaneThree::onExit()
{
	//ȡ�����ĵ���Ϣ..
	__NotificationCenter::getInstance()->removeObserver(this, string("ExplosionInfo"));
	EnemyPlane::onExit();
}

void SpaceWar::EnemyPlaneThree::cleanup()
{
	EnemyPlane::cleanup();

}

void SpaceWar::EnemyPlaneThree::activate()
{

	EnemyPlane::activate();

	m_spraying_left_point_effect->setVisible(true);
	m_spraying_right_point_effect->setVisible(true);
	//����move_pattern

	schedule(CC_CALLBACK_0(EnemyPlaneThree::move, this),
		0.1,
		CC_REPEAT_FOREVER,
		0,
		string("EnemyPlaneThree::move"));


}

void SpaceWar::EnemyPlaneThree::shoot()
{
	m_shoot_interval -= 0.1f;
	if (Unit::floatCmpEqual(m_shoot_interval,0)) {
		if (this->m_shoot_bullet_pattern)
			this->m_shoot_bullet_pattern->m_shoot(this->m_shoot_bullet_pattern);
		//����
		m_shoot_interval = 2.0f;

	}


}

//
void SpaceWar::EnemyPlaneThree::move()
{

	if (this->m_move_pattern)
		this->m_move_pattern->m_move(m_move_pattern);

}

void SpaceWar::EnemyPlaneThree::manualDestroy(float time)
{
	//


	EnemyPlane::manualDestroy(time);
}

SpaceWar::EnemyPlaneThree* SpaceWar::EnemyPlaneThree::clone()
{
	EnemyPlaneThree* plane = EnemyPlaneThree::create(this->m_filename);


	plane->setPosition(this->getPosition());
	plane->setRotation(this->getRotation());
	plane->GetBody()->SetTransform(this->GetBody()->GetPosition(), this->GetBody()->GetAngle());

	//���÷���ģʽ
	if (this->m_shoot_bullet_pattern)
		plane->setShootBulletPattern(this->m_shoot_bullet_pattern->clone(plane));
	else
		plane->setShootBulletPattern(nullptr);

	//�����˶�ģʽ
	if (this->m_move_pattern)
		plane->setMovePattern(this->m_move_pattern->clone(plane));
	else
		plane->setMovePattern(nullptr);

	return plane;
}

void SpaceWar::EnemyPlaneThree::BeginContact(cocos2d::Vec2 contact, CPhysicsSprite* other)
{

	EnemyPlane::BeginContact(contact, other);

	//����RTTI���б����..

	//������ӵ���ײ
	if (dynamic_cast<PlayerBullet*>(other)) {
		auto bullet = dynamic_cast<PlayerBullet*>(other);
		//�õ�����ӵ����ٶȴ�С...
		float bullet_speed = bullet->GetBody()->GetLinearVelocity().Length();
		this->setHp(this->getHp() - bullet_speed);
		//����
		this->runAction(TintBy::create(0.1, 0, 255, 255));

	}

	//�͵�����ײ,
	if (dynamic_cast<Missile*>(other)) {
		this->setHp(0);
		__NotificationCenter::getInstance()->postNotification("Mess[Blast]", this);
	}

	//�͵л���ײ
	if (dynamic_cast<EnemyPlane*>(other)) {
		this->setHp(0);
		__NotificationCenter::getInstance()->postNotification("Mess[Blast]", this);
	}

	//����ҷɻ���ײ
	if (dynamic_cast<PlayerPlane*>(other)) {
		this->setHp(0);
		__NotificationCenter::getInstance()->postNotification("Mess[Blast]", this);
	}

	if (this->getHp() <= 0) {
		if (call_timer == 0) {
			//�л�������
			__NotificationCenter::getInstance()->postNotification("Mess[TimeToUpdateHitEnemyNum]");
			this->manualDestroy(0);
			//��ը��Ϣ
			__NotificationCenter::getInstance()->postNotification("Mess[Blast]", this);
			//��ը��Ч����
			SimpleAudioEngine::getInstance()->playEffect(GameTexture::getInstance()->getTextureRelativePath("music_enemy_explosion").c_str());
			call_timer++;
		}
	}
	return;
}
void SpaceWar::EnemyPlaneThree::EndContact(cocos2d::Vec2 contact, CPhysicsSprite* other)
{
	EnemyPlane::EndContact(contact, other);
}



//
bool SpaceWar::EnemyPlaneThree::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!EnemyPlane::init());
		Size visibleSize = Director::getInstance()->getVisibleSize();
		//Do Sth..

		//////////////���û����ķɻ���Ϣ
		this->setShootingRate(3.0f);
		this->setSprayingLeftPoint(Vec2(3,36));
		this->setSprayingRightPoint(Vec2(58,36));
		this->setShootingPoint(Vec2(30,84));
		this->setMiddlePoint(Vec2(30,42));
		this->setShootingLeftPoint(Vec2(13,68));
		this->setShootingRightPoint(Vec2(48,68));
		this->setHp(80);
		this->setBlastRadius(500);
		m_shoot_interval = 2.0f;
		call_timer = 0;
		//////////////////////����Ĭ��body_def����
		Vec2 pos = Vec2(Region::Up::GetPoint(4, 2));
		b2BodyDef body_def;
		body_def.type = b2_dynamicBody;
		body_def.linearVelocity = b2Vec2(0, 0);
		body_def.linearDamping = 0;
		body_def.angularVelocity = 0;
		body_def.angularDamping = 0;
		body_def.gravityScale = 0;
		body_def.angle = Unit::PI;
		body_def.position = b2Vec2(0, 0);
		body_def.fixedRotation = false;//false��ʾ����������������Ť��Ӱ��..
		body_def.userData = this;

		//init the body..
		this->initBody(body_def, this->m_filename);

		///////////////////////�����������Ч��...
		m_spraying_left_point_effect = ParticleSystemQuad::create(GameTexture::getInstance()->getTextureRelativePath("enemy_plane_fire"));
		m_spraying_right_point_effect = ParticleSystemQuad::create(GameTexture::getInstance()->getTextureRelativePath("enemy_plane_fire"));;
		this->addChild(m_spraying_left_point_effect, 1);
		this->addChild(m_spraying_right_point_effect, 1);
		m_spraying_left_point_effect->setPosition(m_spraying_left_point);
		m_spraying_right_point_effect->setPosition(m_spraying_right_point);


		m_spraying_left_point_effect->setPositionType(ParticleSystem::PositionType::RELATIVE);
		m_spraying_right_point_effect->setPositionType(ParticleSystem::PositionType::RELATIVE);


		m_spraying_left_point_effect->setEmissionRate(100);
		m_spraying_right_point_effect->setEmissionRate(100);


		m_spraying_left_point_effect->setVisible(false);
		m_spraying_right_point_effect->setVisible(false);


		schedule(CC_CALLBACK_0(EnemyPlaneThree::shoot, this),
			0.1f,
			CC_REPEAT_FOREVER,
			0,
			"EnemyPlaneThree::shoot");

		//Do Sth..
		bRet = true;
	} while (0);

	return bRet;
}

void SpaceWar::EnemyPlaneThree::speak()
{
	auto pos = this->getPosition();
	log("EnemyPlaneThree:%s:Position:(%f,%f)", this->getGuid().c_str(), pos.x, pos.y);

}

SpaceWar::EnemyPlaneThree::~EnemyPlaneThree()
{

}



SpaceWar::EnemyPlaneThree* SpaceWar::EnemyPlaneThree::create(const std::string& filename)
{
	EnemyPlaneThree *sprite = new (std::nothrow) EnemyPlaneThree();
	sprite->m_filename = filename;
	auto file_path = GameTexture::getInstance()->getTextureRelativePath(filename);
	if (sprite && sprite->initWithFile(file_path) && sprite->init())
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}
