#ifndef GameSetting_h__
#define GameSetting_h__
#include "cocos2d.h"

namespace SpaceWar {
	//单例类!
	class GameSetting {
		//对象方法
	public:
		void init();
		cocos2d::Size GetDesignResolutionSize();
		cocos2d::Size GetSmallResolutionSize();
		cocos2d::Size GetMediumResolutionSize();
		cocos2d::Size GetLargeResolutionSize();

		//静态方法
	public:
		static GameSetting* getInstance();
		static void Destroy();//在程序结束的时候调用.
							  //禁止默认构造.
	private:
		GameSetting();//构造函数是私有的,不能在类外创建!只能在类里
		virtual ~GameSetting();
		//单例类对象数据
	private:
		//静态单例对象.
		static GameSetting* m_instance;
		//屏幕大小信息
		cocos2d::Size m_designResolutionSize;
		cocos2d::Size m_smallResolutionSize;
		cocos2d::Size m_mediumResolutionSize;
		cocos2d::Size m_largeResolutionSize;

		//


		//
	};




}




#endif // GameSetting_h__







