/*
 * This is the implementation file for the Entity class.
 * Author: Jordan Ell
 * Date: 09/01/12
 */

#include "Entity.h"

using namespace GameFramework;

namespace ManhattanProject
{
	Entity::Entity(Game* game):
		DrawableGameComponent(game)
	{
		this->game = game;
	}
	
	void Entity::Initialize()
	{
	
	}
	
	void Entity::Update()
	{
	
	}
	
	void Entity::Draw()
	{
	
	}
	
	GameFramework::Rectangle Entity::GetCollisionRectangle()
	{
		return GameFramework::Rectangle();
	}
}



