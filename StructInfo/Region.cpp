#include "Region.h"
#include "GameSetting.h"


using namespace std;
USING_NS_CC;
using namespace SpaceWar;

//�ȿճ�ʼ������
cocos2d::Vec2 SpaceWar::Region::all_points[] = {};


cocos2d::Vec2 SpaceWar::Region::Center::GetPoint(int row, int rank)
{
	return all_points[(row - 1) * 7 + rank];
}

cocos2d::Vec2 SpaceWar::Region::Center::GetRandPoint()
{
	return GetPoint(1 + rand() % 6, 1 + rand() % 6);
}

cocos2d::Vec2 SpaceWar::Region::Left::GetPoint(int row, int rank)
{
	//�õ���Ļ��С
	auto _size = Director::getInstance()->getVisibleSize();
	//�൱�ڵ�����width����
	auto pos = all_points[(row - 1) * 7 + rank];
	return Vec2((pos.x - _size.width), pos.y);
}

cocos2d::Vec2 SpaceWar::Region::Left::GetRandPoint()
{
	return GetPoint(1 + rand() % 6, 1 + rand() % 6);
}

cocos2d::Vec2 SpaceWar::Region::UpperLeft::GetPoint(int row, int rank)
{
	//�õ���Ļ��С
	auto _size = Director::getInstance()->getVisibleSize();

	//�൱�ڵ�����width����,������height����..
	auto pos = all_points[(row - 1) * 7 + rank];
	return Vec2((pos.x - _size.width), pos.y + _size.height);
}

cocos2d::Vec2 SpaceWar::Region::UpperLeft::GetRandPoint()
{
	return GetPoint(1 + rand() % 6, 1 + rand() % 6);
}

cocos2d::Vec2 SpaceWar::Region::Up::GetPoint(int row, int rank)
{
	//�õ���Ļ��С
	//Size _size = GameSetting::getInstance()->GetDesignResolutionSize();
	auto _size = Director::getInstance()->getVisibleSize();

	//�൱�ڵ�������height����..
	auto pos = all_points[(row - 1) * 7 + rank];
	return Vec2(pos.x, pos.y + _size.height);
}

cocos2d::Vec2 SpaceWar::Region::Up::GetRandPoint()
{
	return GetPoint(1 + rand() % 6, 1 + rand() % 6);
}

cocos2d::Vec2 SpaceWar::Region::UpperRight::GetPoint(int row, int rank)
{
	//�õ���Ļ��С

	auto _size = Director::getInstance()->getVisibleSize();

	//�൱�ڵ�������width����,������height..
	auto pos = all_points[(row - 1) * 7 + rank];
	return Vec2(pos.x + _size.width, pos.y + _size.height);
}

cocos2d::Vec2 SpaceWar::Region::UpperRight::GetRandPoint()
{
	return GetPoint(1 + rand() % 6, 1 + rand() % 6);
}

cocos2d::Vec2 SpaceWar::Region::Right::GetPoint(int row, int rank)
{
	//�õ���Ļ��С

	auto _size = Director::getInstance()->getVisibleSize();
	//�൱�ڵ�������width����,
	auto pos = all_points[(row - 1) * 7 + rank];
	return Vec2(pos.x + _size.width, pos.y);
}


cocos2d::Vec2 SpaceWar::Region::Right::GetRandPoint()
{
	return GetPoint(1 + rand() % 6, 1 + rand() % 6);
}

cocos2d::Vec2 SpaceWar::Region::GetRandPointInRandRegions()
{
	int rand_region = rand() % 4;
	log("-----------------rand_region:%d------------------", rand_region);
	switch (rand_region)
	{
	case Left:
		return Left::GetRandPoint();
	case UpperLeft:
		return UpperLeft::GetRandPoint();
	case Up:
		return Up::GetRandPoint();
	case UpperRight:
		return UpperRight::GetRandPoint();
	case Right:
		return Right::GetRandPoint();
	}
}

cocos2d::Vec2 SpaceWar::Region::GetRandPointInHorizon()
{
	auto temp = 1 + rand() % 6;
	log("-----------------rand point:(%d)------------------", temp);
	return Center::GetPoint(7, 1 + rand() % 6);
}

cocos2d::Vec2 SpaceWar::Region::GetRandPointInUpperLeftRight()
{
	int arr[3] = { 0,1,3 };
	int rand_region = rand() % 3;
	log("-----------------rand_region:%d------------------", rand_region);
	switch (arr[rand_region])
	{
	case Left:
		return Left::GetRandPoint();
	case UpperLeft:
		return UpperLeft::GetRandPoint();
	case Up:
		return Up::GetRandPoint();
	case UpperRight:
		return UpperRight::GetRandPoint();
	case Right:
		return Right::GetRandPoint();
	}
}

int SpaceWar::Region::init()
{
	//*****��ʼ��all_points//

	//�õ���Ļ��С

	auto _size = Director::getInstance()->getVisibleSize();

	//���Ͻ�����
	Vec2 left_up_point(0, _size.height);
	//-->1/7��width
	float sixth_width = 0.16666f * _size.width;
	//-->1/7��height
	float sixth_height = 0.16666f * _size.height;
	//forѭ������
	int i, row, rank;
	i = 1;
	for (row = 1; row <= 7; row++) {
		for (rank = 1; rank <= 7; rank++) {
			//�ҵ�(row,rank)��������
			all_points[i++] = Vec2(
				left_up_point.x + (rank - 1)*sixth_width,
				left_up_point.y - (row - 1)*sixth_height);
		}

	}
	return 1;
}






