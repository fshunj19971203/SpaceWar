#ifndef BaseLayer_h__
#define BaseLayer_h__
#include "cocos2d.h"
namespace SpaceWar {
	class BaseLayer : public cocos2d::Layer
	{
	public:
		virtual bool init();
		virtual void onEnterTransitionDidFinish();
		void menuBackCallback(cocos2d::Ref* pSender);
	};
}
#endif // BaseLayer_h__
