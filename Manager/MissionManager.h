#ifndef MissionManager_h__
#define MissionManager_h__

// #MissionManager
namespace SpaceWar {
	class Mission;
	class MissionManager {
	public:
		//methods
		bool init();
		//**************************�ؿ�1

		//һ���ɻ���Up�������½�
		Mission* getMission100(float start);

		/*
		�����ɻ���Up���½�
		*/
		Mission* getMission1(float start);


		/*

		5�����ŷɻ���Up��ͬʱ�����½�

		*/
		Mission* getMission2(float start);



		/*

		5�����ŷɻ���Up��˳������½�(����)
		*/
		Mission* getMission6(float start);


		/*
			5�����ŷɻ���Up��˳������½�(����)
		*/
		Mission* getMission8(float start);


		/*
		5�����ŷɻ���Left��˳���������

		*/
		Mission* getMission7(float start);



		/*
		5�����ŷɻ���Right��˳���������

		*/
		Mission* getMission9(float start);


		/*
5�����ŷɻ���Left��˳���������(����)

*/
		Mission* getMission10(float start);


		/*
5�����ŷɻ���Right��˳��������ƣ�����

*/
		Mission* getMission11(float start);
		/*
		ͬʱ��
		һ�ŷɻ���Left����ֱ�ߺ�����
		һ�ŷɻ���Right����ֱ�ߺ�����
		*/
		Mission* getMission5(float start);


		/*
		2�����ŷɻ�����Up��ֱ�ߺ���ͷ

		*/
		Mission* getMission3(float start);

		/*
		n�������ɻ���Left��ֱ�ߺ���ͷ

		*/
		Mission* getMission14(float start);


		/*
		n�������ɻ���Right��ֱ�ߺ���ͷ

		*/
		Mission* getMission15(float start);


		/*

		2�����ŷɻ�����Up��ֱ�ߺ���ת
		*/
		Mission* getMission4(float start);



		/*
		3���ɻ�45�ȴ����ϽǴ���Center�е�
		*/
		Mission* getMission12(float start);
		/*
			3���ɻ�45�ȴ����ϽǴ���Center�е�
		*/
		Mission* getMission13(float start);



		//һ���ɻ��ɹ��е�
		Mission* getMission111(float start);



		// �ؿ�1,
		Mission* getMissionMakePlane1(float start,float interval,int calls);



		//�ؿ�2:
		//����1�л�������Ns��ÿfrequencys����һ��
		Mission* getMissionMakePlane2(float start,float interval,int calls);


		//�ؿ�3  :
		Mission* getMissionMakeAsdroid(float start,float interval,int calls);


		//�Է���ģʽ�Ĳ�������
		Mission* getMissionX(float start);
	private:
		//var

	//others.
	public:
		static MissionManager* getInstance();
		static void destroy();
	private:
		static MissionManager* m_instance;
	private:
		MissionManager();
		virtual ~MissionManager();
	};


}

#endif // MissionManager_h__
