#ifndef Region_h__
#define Region_h__

#include "cocos2d.h"

namespace SpaceWar {
	class Region
	{
	public:
		static const int Left = 0;
		static const int UpperLeft = 1;
		static const int Up = 2;
		static const int Right = 3;
		static const int UpperRight = 4;

		static cocos2d::Vec2 GetRandPointInRandRegions();
		static cocos2d::Vec2 GetRandPointInHorizon();
		static cocos2d::Vec2 GetRandPointInUpperLeftRight();

	public:
		class Center
		{
		public:
			static cocos2d::Vec2 GetPoint(int row, int rank);
			static cocos2d::Vec2 GetRandPoint();
		};

		class Left
		{
		public:
			static cocos2d::Vec2 GetPoint(int row, int rank);
			static cocos2d::Vec2 GetRandPoint();
		};
		class UpperLeft
		{
		public:
			static cocos2d::Vec2 GetPoint(int row, int rank);
			static cocos2d::Vec2 GetRandPoint();
		};
		class Up
		{
		public:
			static cocos2d::Vec2 GetPoint(int row, int rank);
			static cocos2d::Vec2 GetRandPoint();
		};
		class UpperRight
		{
		public:
			static cocos2d::Vec2 GetPoint(int row, int rank);
			static cocos2d::Vec2 GetRandPoint();
		};
		class Right
		{
		public:
			static cocos2d::Vec2 GetPoint(int row, int rank);
			static cocos2d::Vec2 GetRandPoint();
		};
	public:
		static int init();//��ʼ��all_points;
	private:
		static cocos2d::Vec2 all_points[50];//ע��,������1��25;�����о�����..
	};
}



#endif // Region_h__









