/*
 * This is the implementation file for the Object class.
 * Author: Jordan Ell
 * Date: 06/11/11
 */

#include "Object.h"

using namespace GameFramework;

namespace ManhattanProject
{
	Object::Object(Game* game):
		DrawableGameComponent(game)
	{
		this->game = game;
	}
	
	void Object::Initialize()
	{
		
	}
	
	void Object::Draw(Camera camera)
	{
		
		DrawableGameComponent::Draw();
	}
	
	void Object::Update()
	{
		
		DrawableGameComponent::Update();
	}
}