/*
 * This is the implementation file for the Object class.
 * Author: Jordan Ell
 * Date: 06/11/11
 */

#include "MapObject.h"

using namespace GameFramework;

namespace ManhattanProject
{
	MapObject::MapObject(Game* game):
		DrawableGameComponent(game)
	{
		this->game = game;
	}
	
	void MapObject::Initialize()
	{
		
	}
	
	void MapObject::Draw(Camera camera)
	{
		
		DrawableGameComponent::Draw();
	}
	
	void MapObject::Update()
	{
		
		DrawableGameComponent::Update();
	}
}