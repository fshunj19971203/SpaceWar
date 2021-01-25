#ifndef ShootPattern_h__
#define ShootPattern_h__
#include "cocos2d.h"
#include <functional>

namespace SpaceWar {
	class Plane;
	class ShootPattern
	{
	public:
		static ShootPattern* create(Plane* plane);
		ShootPattern* clone(Plane* plane);
		std::function<void(ShootPattern* shoot)> m_shoot;
	private:
		virtual bool init(Plane* plane);
		//gettter..setter..
	public:
		inline SpaceWar::Plane* getPlane() const { return m_plane; }
		inline void setPlane(SpaceWar::Plane* val) { m_plane = val; }
	private:
		Plane* m_plane;
	};
}

#endif // ShootPattern_h__
