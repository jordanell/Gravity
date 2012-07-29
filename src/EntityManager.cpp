/*
 * This is the implementation file for the EntityManager class.
 * Author: Jordan Ell
 * Date: 21/01/12
 */

#include "EntityManager.h"

using namespace framework;

namespace ManhattanProject
{
	EntityManager::EntityManager(Game* game):
		DrawableGameComponent(game)
	{
		this->game = game;
	}
	
	EntityManager::EntityManager(Game* game, TileMap* Map):
		DrawableGameComponent(game)
	{
		this->game = game;
		this->Map = Map;
	}
	
	void EntityManager::Initialize()
	{
		
	}
	
	list<Entity*> EntityManager::GetActiveEntities()
	{
		return Entities;
	}
	
	void EntityManager::Update()
	{
		
	}
	
	void EntityManager::Draw()
	{
		
	}
}

