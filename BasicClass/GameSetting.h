#ifndef GameSetting_h__
#define GameSetting_h__
#include "cocos2d.h"

namespace SpaceWar {
	//������!
	class GameSetting {
		//���󷽷�
	public:
		void init();
		cocos2d::Size GetDesignResolutionSize();
		cocos2d::Size GetSmallResolutionSize();
		cocos2d::Size GetMediumResolutionSize();
		cocos2d::Size GetLargeResolutionSize();

		//��̬����
	public:
		static GameSetting* getInstance();
		static void Destroy();//�ڳ��������ʱ�����.
							  //��ֹĬ�Ϲ���.
	private:
		GameSetting();//���캯����˽�е�,���������ⴴ��!ֻ��������
		virtual ~GameSetting();
		//�������������
	private:
		//��̬��������.
		static GameSetting* m_instance;
		//��Ļ��С��Ϣ
		cocos2d::Size m_designResolutionSize;
		cocos2d::Size m_smallResolutionSize;
		cocos2d::Size m_mediumResolutionSize;
		cocos2d::Size m_largeResolutionSize;

		//


		//
	};




}




#endif // GameSetting_h__







