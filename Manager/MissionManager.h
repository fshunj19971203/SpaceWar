#ifndef MissionManager_h__
#define MissionManager_h__

// #MissionManager
namespace SpaceWar {
	class Mission;
	class MissionManager {
	public:
		//methods
		bool init();
		//**************************关卡1

		//一个飞机从Up区匀速下降
		Mission* getMission100(float start);

		/*
		两个飞机从Up区下降
		*/
		Mission* getMission1(float start);


		/*

		5个并排飞机从Up区同时加速下降

		*/
		Mission* getMission2(float start);



		/*

		5个并排飞机从Up区顺序加速下降(正序)
		*/
		Mission* getMission6(float start);


		/*
			5个并排飞机从Up区顺序加速下降(逆序)
		*/
		Mission* getMission8(float start);


		/*
		5个并排飞机从Left区顺序加速右移

		*/
		Mission* getMission7(float start);



		/*
		5个并排飞机从Right区顺序加速左移

		*/
		Mission* getMission9(float start);


		/*
5个并排飞机从Left区顺序加速右移(正序)

*/
		Mission* getMission10(float start);


		/*
5个并排飞机从Right区顺序加速左移（逆序）

*/
		Mission* getMission11(float start);
		/*
		同时，
		一排飞机从Left区先直线后向右
		一排飞机从Right区先直线后向左
		*/
		Mission* getMission5(float start);


		/*
		2个并排飞机从左Up区直线后饶头

		*/
		Mission* getMission3(float start);

		/*
		n个连续飞机从Left区直线后饶头

		*/
		Mission* getMission14(float start);


		/*
		n个连续飞机从Right区直线后饶头

		*/
		Mission* getMission15(float start);


		/*

		2个并排飞机从右Up区直线后右转
		*/
		Mission* getMission4(float start);



		/*
		3个飞机45度从左上角穿过Center中点
		*/
		Mission* getMission12(float start);
		/*
			3个飞机45度从右上角穿过Center中点
		*/
		Mission* getMission13(float start);



		//一个飞机飞过中点
		Mission* getMission111(float start);



		// 关卡1,
		Mission* getMissionMakePlane1(float start,float interval,int calls);



		//关卡2:
		//放置1敌机，持续Ns，每frequencys放置一次
		Mission* getMissionMakePlane2(float start,float interval,int calls);


		//关卡3  :
		Mission* getMissionMakeAsdroid(float start,float interval,int calls);


		//对发弹模式的测试任务：
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
