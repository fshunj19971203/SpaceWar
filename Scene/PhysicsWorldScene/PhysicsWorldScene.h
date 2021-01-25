
#ifndef PhysicsWorldScene_h__
#define PhysicsWorldScene_h__
//
#include "cocos2d.h"
#include "GLES-Render.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCCustomCommand.h"
#include "math/Mat4.h"

#include "ui/CocosGUI.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
USING_NS_CC;

using namespace ui;
using namespace cocostudio;
using namespace cocostudio::timeline;
using namespace std;


class PhysicsWorldScene
{
public:
	static cocos2d::Layer* getLayerSpr() { return m_layer_spr; }
	static cocos2d::Layer* getLayerShowingData() { return m_layer_showing_data; }

	static void setLayerSpr(cocos2d::Layer* val) { m_layer_spr = val; }
	static void setLayerShowingData(cocos2d::Layer* val) { m_layer_showing_data = val; }

public:
	static cocos2d::Scene* createScene(int current_game_level);
private:
	static cocos2d::Layer* m_layer_spr;
	static cocos2d::Layer* m_layer_showing_data;
};


class PhysicsWorldSceneLayer :public cocos2d::Layer
{
public:
	//schedule函数
	void scheduleFunc();
	//订阅的消息
	void subscribe();
	void unsubscribe();
	void InitGameLevel();
	void ExecuteGameLevel();
	virtual void update(float dt);
public:
	//
	void handleGameOver(cocos2d::Ref* sender);
public:
	virtual bool init();
	virtual void onEnter();
	virtual  void onExit();
	virtual void onEnterTransitionDidFinish();
	bool initWorldBorder();
	void RedirectToGameOverScene();
	//getter,setter..
	inline b2Body* getScreenWall() const { return m_screen_wall; }
	//other..
	CREATE_FUNC(PhysicsWorldSceneLayer);
	virtual void draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, uint32_t flags)override;
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	//控制暂停，
	void menuPauseCallback(cocos2d::Ref* sender);
	void menuResumeCallback(cocos2d::Ref* sender);
	void menuBackCallback(cocos2d::Ref* Sender);

	//

	//关卡结束调用

protected:
	void onDraw(const cocos2d::Mat4& transform, uint32_t flags);
protected:
	cocos2d::CustomCommand _customCmd;
	cocos2d::Menu* menu;//游戏返回主页和继续游戏的菜单
	cocos2d::Label* label;//
private:
	b2Body* m_screen_wall;
};



class PhysicsWorldSceneLayerDataShowing :public cocos2d::Layer
{
public:
	virtual bool init();
	CREATE_FUNC(PhysicsWorldSceneLayerDataShowing);
	void updateHpNum(cocos2d::Ref* sender);
	void updateHitEnemyNum(cocos2d::Ref* sender);
	void updateMissileNum(cocos2d::Ref* sender);
	inline int getHitEnemyNumReal() const { return m_hit_enemy_num_real; }
	inline void setHitEnemyNumReal(int val) { m_hit_enemy_num_real = val; }
public:
	void subscribe();
public:
	//离开的时候要销毁
	virtual void onExit();
private:
	//标签
	Text* label_hit;
	Text* label_hp;
	Text* label_missile;
	Button* bt_pause;
	////数字
	//cocos2d::Label* m_hit_enemy_num;
	//cocos2d::Label* m_current_player_plane_hp_num;
	//cocos2d::Label* m_missile_num;

	//
	int m_hit_enemy_num_real;

};







#endif // TestScene_h__



