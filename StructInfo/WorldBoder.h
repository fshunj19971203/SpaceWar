#ifndef WorldBoder_h__
#define WorldBoder_h__
#include "cocos2d.h"

namespace SpaceWar {
	class WorldBoder {
	public:
		//methods
		bool init();
		
	private:
		//var
		cocos2d::Vec2 end;
	//others.
	public:
		static WorldBoder* getInstance();
		static void destroy();
	private:
		static WorldBoder* m_instance;
	private:
		WorldBoder();
		virtual ~WorldBoder();
	};
	
}

#endif // WorldBoder_h__
