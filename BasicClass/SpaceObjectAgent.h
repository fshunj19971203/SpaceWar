#ifndef SpaceObjectAgent_h__
#define SpaceObjectAgent_h__
#include "cocos2d.h"

namespace SpaceWar {
	class SpaceObject;
	class SpaceObjectAgent :public cocos2d::Node {
		friend class Plane;
	public:
		static SpaceObjectAgent* create(bool valid, SpaceObject* object);
	public:
		SpaceObjectAgent() {};
		~SpaceObjectAgent();
	public:
		bool init(bool valid, SpaceObject* object);
		void destroy();
		
	public:
		inline bool isValid() { return m_valid == true; };
		inline SpaceObject* getSpaceObject() const { return m_object; };
	public:
		//ÿ3s��checkһ��״̬�����Ϊfalse��3s���Ի٣�
		void autoCheck();
	private:
		bool m_valid;
		SpaceObject* m_object;

	};

}

#endif // SpaceObjectAgent_h__
