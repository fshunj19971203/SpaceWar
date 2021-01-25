#ifndef Unit_h__
#define Unit_h__

#include "Box2D/Box2D.h"
#include "cocos2d.h"
#include <string>
#include <sstream>
namespace SpaceWar {
	class Unit
	{
		//坐标点,速度值的转换
	public:
		static inline float PTM(float pixel) { return pixel / 32; };
		static inline float MTP(float meter) { return meter * 32; };
		//角速度转换---rad/s和deg/f-->默认帧率为60;
		static inline float RTD_RATE(float rad_s) { return (rad_s * (180 / (FPS*PI))); };
		static inline float DTR_RATE(float deg_f) { return (deg_f * ((FPS*PI) / 180)); };

		//Force转换



		//其他实用
		b2Vec2 getUnitVector(float degree);//由角度得到对应的单位（力）向量


		//在锚点在左下角的情况下，把sprite的某个点（a,b）订在父节点的（x,y）处;此时sprite的坐标是.
		static cocos2d::Vec2 getSpritePosWhenPinedAt(cocos2d::Vec2 which_to_pine,
			cocos2d::Vec2 pine_at_wor_pos);



		//计算一个向量的左边的法向量或者右边的法向量..
// 		static inline Vec2 getNormalVectorLeft(cocos2d::Vec2 vec);
// 		static inline Vec2 getNormalVectorRight(cocos2d::Vec2 vec);


		//判断一个向量在另外一个向量的左边还是右边（左手坐标系的叉积，以及左手定则..）

		static bool RelativeToLeft(cocos2d::Vec2 vec);
		static bool RelativeToRight(cocos2d::Vec2 vec);


		
		//两个坐标点的转换
		static b2Vec2 Tob2Vec2(cocos2d::Vec2 vec);
		static cocos2d::Vec2 ToVec2(b2Vec2 vec);



		//浮点数相关的
		bool static floatCmpGreaterEqual(float a, float b);
		bool static floatCmpLessEqual(float a, float b);
		bool static floatCmpEqual(float a, float b);




		//角度和弧度的转换；
		static float degToRad(float deg);
		static float radToDeg(float rad);

		//
		static std::string generateGuid();



		//一个向量转向另外一个向量，需要逆时针转多少度
		//注意，返回值>0表示逆时针转的弧度，<0表示顺时针转的弧度
		static float rotateToAVec(cocos2d::Vec2 vec1, cocos2d::Vec2 vec2);
	public:
		static const int PixelToMeter = 32;
		static const int FPS = 60;
		const static float PI;
		const static float EPSINON;
	private:
		Unit() {};
		~Unit() {};
	};

inline std::string num2str(int i)
{
    std::stringstream ss;
    ss << i;
	return std::string(ss.str());
};

inline std::string num2str(double i)
{
    std::stringstream ss;
    ss << i;
	return std::string(ss.str());
};

}

#endif // Unit_h__

