#ifndef MyUtility_h__
#define MyUtility_h__
#include "cocos2d.h"
#include <string>

namespace SpaceWar {
	class MyUtility
	{
	public:
		static std::string getCurrentTime();

		static std::string gbk_2_utf8(const std::string text);

		static std::string getUTF8Char(const std::string key);

	};

}

#endif // MyUtility_h__
