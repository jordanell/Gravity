/*
 * This is the header for the Pathfinding class.
 * This class is used take an entity in the world that needs to preform some pathfind operation
 * Author: Jordan Ell
 * Date: 21/01/12
 */

#ifndef PATHFINDINGMANAGER_H
#define PATHFINDINGMANAGER_H

#include "framework.h"
#include "Entity.h"
#include "PathfindingObject.h"
#include "CollisionRectangle.h"
#include <list>

using namespace framework;

namespace gravity
{
	class PathfindingManager: public GameComponent
	{
		public:
			PathfindingManager(Game* game);
			PathfindingManager(Game* game, list<CollisionRectangle*> ActiveCollisions);
			PathfindingManager(Game* game, list<CollisionRectangle*> ActiveCollisions, list<Entity*> Entities);
			
			~PathfindingManager();
			
			void Initialize();
			
			void SetEntities(list<Entity*> Entities);
			void SetCollisions(list<CollisionRectangle*> ActiveCollisions);
			
			void FindPath(Entity* entity, Point Destination);
			
			void Update();
		
		protected:
			void AddToQueue(PathfindingObject* object);
			PathfindingObject* PopQueue();
			bool IsQueued();
			
			list<PathfindingObject*> pathfindingQueue;
			list<CollisionRectangle*> ActiveCollisions;
			list<Entity*> Entities;
	};
}

#endif
