#ifndef Unit_h__
#define Unit_h__

#include "Box2D/Box2D.h"
#include "cocos2d.h"
#include <string>
#include <sstream>
namespace SpaceWar {
	class Unit
	{
		//�����,�ٶ�ֵ��ת��
	public:
		static inline float PTM(float pixel) { return pixel / 32; };
		static inline float MTP(float meter) { return meter * 32; };
		//���ٶ�ת��---rad/s��deg/f-->Ĭ��֡��Ϊ60;
		static inline float RTD_RATE(float rad_s) { return (rad_s * (180 / (FPS*PI))); };
		static inline float DTR_RATE(float deg_f) { return (deg_f * ((FPS*PI) / 180)); };

		//Forceת��



		//����ʵ��
		b2Vec2 getUnitVector(float degree);//�ɽǶȵõ���Ӧ�ĵ�λ����������


		//��ê�������½ǵ�����£���sprite��ĳ���㣨a,b�����ڸ��ڵ�ģ�x,y����;��ʱsprite��������.
		static cocos2d::Vec2 getSpritePosWhenPinedAt(cocos2d::Vec2 which_to_pine,
			cocos2d::Vec2 pine_at_wor_pos);



		//����һ����������ߵķ����������ұߵķ�����..
// 		static inline Vec2 getNormalVectorLeft(cocos2d::Vec2 vec);
// 		static inline Vec2 getNormalVectorRight(cocos2d::Vec2 vec);


		//�ж�һ������������һ����������߻����ұߣ���������ϵ�Ĳ�����Լ����ֶ���..��

		static bool RelativeToLeft(cocos2d::Vec2 vec);
		static bool RelativeToRight(cocos2d::Vec2 vec);


		
		//����������ת��
		static b2Vec2 Tob2Vec2(cocos2d::Vec2 vec);
		static cocos2d::Vec2 ToVec2(b2Vec2 vec);



		//��������ص�
		bool static floatCmpGreaterEqual(float a, float b);
		bool static floatCmpLessEqual(float a, float b);
		bool static floatCmpEqual(float a, float b);




		//�ǶȺͻ��ȵ�ת����
		static float degToRad(float deg);
		static float radToDeg(float rad);

		//
		static std::string generateGuid();



		//һ������ת������һ����������Ҫ��ʱ��ת���ٶ�
		//ע�⣬����ֵ>0��ʾ��ʱ��ת�Ļ��ȣ�<0��ʾ˳ʱ��ת�Ļ���
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

