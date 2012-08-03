/*
 * This is the header for the Pathfinding Object class.
 * This class is used to hold values for objects waiting in the pathfinding queue
 * Author: Jordan Ell
 * Date: 21/01/12
 */

#ifndef PATHFINDINGOBJECT_H
#define PATHFINDINGOBJECT_H

#include "framework.h"
#include "Entity.h"

using namespace framework;

namespace gravity
{
	class PathfindingObject
	{
		public:
			PathfindingObject();
			PathfindingObject(Entity* entity, Point Destination);
		
			void SetObject(Entity* entity, Point Destination);
		
			Entity* GetEntity();
			Point GetDestination();
		
		protected:
			Entity* entity;
			Point Destination;
	};
}

#endif
