/*
 * This is the implementation for the PathfindingManager class.
 * Author: Jordan Ell
 * Date: 21/01/12
 */

#include "PathfindingManager.h"

using namespace GameFramework;

namespace ManhattanProject
{
	PathfindingManager::PathfindingManager(Game* game):
		GameComponent(game)
	{
		this->game = game;
	}
	
	PathfindingManager::PathfindingManager(Game* game, list<CollisionRectangle*> ActiveCollisions):
		GameComponent(game)
	{
		this->game = game;
		this->ActiveCollisions = ActiveCollisions;
		
	}
	
	PathfindingManager::PathfindingManager(Game* game, list<CollisionRectangle*> ActiveCollisions, list<Entity*> Entities):
		GameComponent(game)
	{
		this->game = game;
		this->ActiveCollisions = ActiveCollisions;
		this->Entities = Entities;
	}
	
	PathfindingManager::~PathfindingManager()
	{
	
	}
	
	void PathfindingManager::Initialize()
	{
	
	}
	
	void PathfindingManager::SetEntities(list<Entity*> Entities)
	{
		this->Entities = Entities;
	}
	
	void PathfindingManager::SetCollisions(list<CollisionRectangle*> ActiveCollisions)
	{
		this->ActiveCollisions = ActiveCollisions;
	}
	
	void PathfindingManager::FindPath(Entity* entity, Point Destination)
	{
		PathfindingObject* object = new PathfindingObject(entity, Destination);
		AddToQueue(object);
	}
	
	void PathfindingManager::Update()
	{
	
	}
	
	void PathfindingManager::AddToQueue(PathfindingObject* object)
	{
		pathfindingQueue.push_back(object);
	}
	
	PathfindingObject* PathfindingManager::PopQueue()
	{
		PathfindingObject* object;
		object = pathfindingQueue.front();
		pathfindingQueue.pop_front();
		return object;
	}
	
	bool PathfindingManager::IsQueued()
	{
		// This needs to be tested
		if(pathfindingQueue.front() == NULL)
			return false;
		else
			return true;
	}
}

