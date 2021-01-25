#include "Unit.h"
#include "boost/uuid/uuid.hpp"
#include "boost/uuid/uuid_generators.hpp"
#include "boost/uuid/uuid_io.hpp"


USING_NS_CC;
using namespace std;

b2Vec2 SpaceWar::Unit::getUnitVector(float degree)
{
	return b2Vec2(0, 0);
}

cocos2d::Vec2 SpaceWar::Unit::getSpritePosWhenPinedAt(cocos2d::Vec2 which_to_pine, cocos2d::Vec2 pine_at_wor_pos)
{
	return Vec2(pine_at_wor_pos.x - which_to_pine.x, pine_at_wor_pos.y - which_to_pine.y);
}

bool SpaceWar::Unit::RelativeToLeft(cocos2d::Vec2 vec)
{
	return true;
}

bool SpaceWar::Unit::RelativeToRight(cocos2d::Vec2 vec)
{
	return true;
}

b2Vec2 SpaceWar::Unit::Tob2Vec2(cocos2d::Vec2 vec)
{
	return b2Vec2(vec.x / 32, vec.y / 32);
}

Vec2 SpaceWar::Unit::ToVec2(b2Vec2 vec)
{
	return Vec2(vec.x * 32, vec.y * 32);

}



bool SpaceWar::Unit::floatCmpGreaterEqual(float a, float b)
{
	if (a > b || Unit::floatCmpEqual(a, b)) {
		return true;
	}
	else
		return false;
}

bool SpaceWar::Unit::floatCmpLessEqual(float a, float b)
{
	if (a < b || Unit::floatCmpEqual(a, b)) {
		return true;
	}
	else
		return false;
}

bool SpaceWar::Unit::floatCmpEqual(float a, float b)
{
	if (abs(a - b) < EPSINON) {
		return true;
	}
	else
		return false;
}

float SpaceWar::Unit::degToRad(float deg)
{
	return deg * (PI / 180.0f);
}

float SpaceWar::Unit::radToDeg(float rad)
{
	return rad * (180.0f / PI);
}

std::string SpaceWar::Unit::generateGuid()
{
	boost::uuids::uuid uid = boost::uuids::random_generator()();
	string uid_str = boost::uuids::to_string(uid);
	return uid_str;

}

float SpaceWar::Unit::rotateToAVec(cocos2d::Vec2 vec1, cocos2d::Vec2 vec2)
{
	Vec3 result;
	Vec3 vec3_1 = Vec3(vec1.x, vec1.y, 0);
	Vec3 vec3_2 = Vec3(vec2.x, vec2.y, 0);
	float angle = Vec3::angle(vec3_1, vec3_2);
	Vec3::cross(vec3_1, vec3_2, &result);

	if (result.z > 0) {
		//vec3_2在vec3_1的左手边，那就是逆时针转angle就可以
		return angle;
	}
	else if (result.z < 0) {
		//vec3_2在vec3_1的右手边,那就是顺时针转angle就可以
		return -angle;
	}
}

// cocos2d::Vec2 SpaceWar::Unit::getNormalVectorLeft(cocos2d::Vec2 vec)
// {
// // 	6 * x + 7 * y = 0;
// // 
// // 	y = -6x / 7;
// 
// 	return Vec2(vec.y,-vec.x).getNormalized();
// }

// b2Vec2 SpaceWar::Unit::getNormalVectorRight(cocos2d::Vec2 vec)
// {
// 
// }

// bool SpaceWar::Unit::RelativeToLeft(cocos2d::Vec2 vec)
// {
// 
// }
// 
// bool SpaceWar::Unit::RelativeToRight(cocos2d::Vec2 vec)
// {
// 
// }

const float SpaceWar::Unit::PI = 3.1415926f;
//[ep'sailən; 'epsilɔn]误差。。
const float SpaceWar::Unit::EPSINON = 0.0001;


