/*
 * This is the implementation for the PathfindingObject class.
 * Author: Jordan Ell
 * Date: 21/01/12
 */

#include "PathfindingObject.h"

using namespace framework;

namespace ManhattanProject
{
	PathfindingObject::PathfindingObject()
	{
		entity = NULL;
	}
	
	PathfindingObject::PathfindingObject(Entity* entity, Point Destination)
	{
		this->entity = entity;
		this->Destination = Destination;
	}
	
	void PathfindingObject::SetObject(Entity* entity, Point Destination)
	{
		this->entity = entity;
		this->Destination = Destination;
	}
	
	Entity* PathfindingObject::GetEntity()
	{
		return this->entity;
	}
	
	Point PathfindingObject::GetDestination()
	{
		return Destination;
	}
}

