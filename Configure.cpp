#include "Configure.h"
//standard..
#include <string>
#include <fstream>
#include <sstream>
//third
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_iterators.hpp"
#include "rapidxml/rapidxml_sax3.hpp"
#include "rapidxml/rapidxml_utils.hpp"
//#include "rapidxml/rapidxml_print.hpp"
//cocos..
#include "cocos2d.h"
#include "Unit.h"
#include "FileHelper.h"
#include <iosfwd>

USING_NS_CC;
using namespace std;
using namespace rapidxml;
using namespace SpaceWar;
bool ConfigureManager::init()
{
	//FileHelper::createDirectory(string("/storage/emulated/0/Android/data/com.fshunj.uu"));
	ssize_t len;
	char *data = (char*)FileUtils::getInstance()->getFileData("space_war_material/config/config.xml", "rb", &len);
	// 拷贝文件（从资源目录拷贝到可写目录）
	//FileHelper::copyFile("space_war_material/config/config.xml");
	auto str = istringstream(string(data, len) + string("\0"));
	file<char> fdoc(str);

	xml_document<>   doc;
	doc.parse<0>(fdoc.data(), fdoc.size());

	// 获取根节点config,处理各个Plane
	xml_node<>* root = doc.first_node();
	Vec2 point;
	for (rapidxml::xml_node<> * node = root->first_node();
		node != NULL;
		node = node->next_sibling())
	{
		//get left fire point 
		auto left_node = node->first_node();
		auto left_x_node = left_node->first_node();
		auto left_x = left_x_node->value();
		point.x = Value(left_x).asFloat();
		auto left_y = left_x_node->next_sibling()->value();
		point.y = Value(left_y).asFloat();
		this->m_fire_points_map[string(node->name())][string("LeftFire")] = Vec2(point.x, point.y);


		//get right fire point 
		auto right_node = left_node->next_sibling();
		auto right_x_node = right_node->first_node();
		auto right_x = right_x_node->value();
		point.x = Value(right_x).asFloat();
		auto right_y = right_x_node->next_sibling()->value();
		point.y = Value(right_y).asFloat();
		this->m_fire_points_map[string(node->name())][string("RightFire")] = Vec2(point.x, point.y);

		//get the left shoot point
		auto left_shoot_node = right_node->next_sibling();
		auto left_shoot_x_node = left_shoot_node->first_node();
		auto left_shoot_x = left_shoot_x_node->value();
		point.x = Value(left_shoot_x).asFloat();
		auto left_shoot_y = left_shoot_x_node->next_sibling()->value();
		point.y = Value(left_shoot_y).asFloat();
		this->m_fire_points_map[string(node->name())][string("LeftShoot")] = Vec2(point.x, point.y);

		//get the right shoot 
		auto right_shoot_node = left_shoot_node->next_sibling();
		auto right_shoot_x_node = right_shoot_node->first_node();
		auto right_shoot_x = right_shoot_x_node->value();
		point.x = Value(right_shoot_x).asFloat();
		auto right_shoot_y = right_shoot_x_node->next_sibling()->value();
		point.y = Value(right_shoot_y).asFloat();
		this->m_fire_points_map[string(node->name())][string("RightShoot")] = Vec2(point.x, point.y);

		//get the middle shooting point..
		auto middle_shoot_node = right_shoot_node->next_sibling();
		auto middle_shoot_x_node = middle_shoot_node->first_node();
		auto middle_shoot_x = middle_shoot_x_node->value();
		point.x = Value(middle_shoot_x).asFloat();
		auto middle_shoot_y = middle_shoot_x_node->next_sibling()->value();
		point.y = Value(middle_shoot_y).asFloat();
		this->m_fire_points_map[string(node->name())][string("MiddleShoot")] = Vec2(point.x, point.y);

	}

	//print the map
	//for (auto i : m_fire_points_map)
	//{
	//	CCLOG(i.first.c_str());
	//	for (auto j : i.second)
	//	{
	//		CCLOG((j.first + "  x:" + num2str(j.second.x) + "-->y:" + num2str(j.second.y)).c_str());
	//		//CCLOG(j.second.x);
	//	}
	//}

	return 1;
}

cocos2d::Vec2 ConfigureManager::getLeftFirePointInPercent(const string & name)
{
	return this->m_fire_points_map[name]["LeftFire"];
}

cocos2d::Vec2 ConfigureManager::getRightFirePointInPercent(const string & name)
{

	return this->m_fire_points_map[name]["RightFire"];
}

cocos2d::Vec2 ConfigureManager::getLeftShootPointInPercent(const std::string & name)
{

	return this->m_fire_points_map[name]["LeftShoot"];
}

cocos2d::Vec2 ConfigureManager::getRightShootPointInPercent(const std::string & name)
{
	return this->m_fire_points_map[name]["RightShoot"];
}

cocos2d::Vec2 ConfigureManager::getMiddleShootPointInPercent(const std::string & name)
{

	return this->m_fire_points_map[name]["MiddleShoot"];
}

ConfigureManager* ConfigureManager::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new ConfigureManager();
		if (m_instance != nullptr) {
			m_instance->init();
		}
	}
	return m_instance;

}

void ConfigureManager::destroy()
{
	if (m_instance != nullptr)
		do { delete (m_instance); (m_instance) = nullptr; } while (0);
}

ConfigureManager* ConfigureManager::m_instance;

ConfigureManager::ConfigureManager()
{

}

ConfigureManager::~ConfigureManager()
{

}
