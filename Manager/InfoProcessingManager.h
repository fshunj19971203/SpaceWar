#ifndef InfoProcessingManager_h__
#define InfoProcessingManager_h__
#include "cocos2d.h"


namespace SpaceWar {
	//�۲���ģʽ�е�������Ϣ����
	class InfoProcessingManager :public cocos2d::Ref
	{
	public:
		//methods
		bool init();

	public:
		//getter..setter.
		inline void* getTracedObject() const { return tracedObject; }
		inline void setTracedObject(void* val) { tracedObject = val; }
		inline float getDistance() const { return distance; }
		inline void setDistance(float val) { distance = val; }
		inline void clear() { tracedObject = nullptr; distance = 10000.0f; };
	private:
		//var
		//��������ѯ������ĵл�..
		void* tracedObject;
		float distance;
	public:
		static InfoProcessingManager* getInstance();
		static void destroy();
	private:
		static InfoProcessingManager* m_instance;
	private:
		InfoProcessingManager();
		virtual ~InfoProcessingManager();
	};





}

#endif // InterChangeManager_h__
