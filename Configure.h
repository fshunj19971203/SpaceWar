#include <string>
#include "cocos2d.h"
#include <map>
class ConfigureManager {
public:
	//methods
	bool init();
	cocos2d::Vec2 getLeftFirePointInPercent(const std::string & name);
	cocos2d::Vec2 getRightFirePointInPercent(const std::string & name);
	cocos2d::Vec2 getLeftShootPointInPercent(const std::string & name);
	cocos2d::Vec2 getRightShootPointInPercent(const std::string & name);
	cocos2d::Vec2 getMiddleShootPointInPercent(const std::string & name);
private:
	//var
	std::map<std::string, std::map<std::string, cocos2d::Vec2>> m_fire_points_map;
	//others.
public:
	static ConfigureManager* getInstance();
	static void destroy();
private:
	static ConfigureManager* m_instance;
private:
	ConfigureManager();
	virtual ~ConfigureManager();
};
