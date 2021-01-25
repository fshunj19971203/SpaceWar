#ifndef PhysicsDebugDraw_h__
#define PhysicsDebugDraw_h__



namespace SpaceWar {
	class PhysicsDebugDrawManager {
	public:
		//methods
		bool init();
	private:
		//var
		
	//others.
	public:
		static PhysicsDebugDrawManager* getInstance();
		static void destroy();
	private:
		static PhysicsDebugDrawManager* m_instance;
	private:
		PhysicsDebugDrawManager();
		virtual ~PhysicsDebugDrawManager();
	};
	

}

#endif // PhysicsDebugDraw_h__
