/*
 * This is the implementation file for the CollisionLayer class.
 * Author: Jordan Ell
 * Date: 16/10/11
 */

#include "CollisionLayer.h"

using namespace GameFramework;

namespace ManhattanProject
{
	CollisionLayer::CollisionLayer(Game* game, Camera camera)
	{
		this->game = game;
		this->camera = camera;
	}
	
	bool CollisionLayer::CheckCollision(Rectangle* rec)
	{
	
	}
	
	void CollisionLayer::AddCollision(Rectangle position, float Rotation)
	{
		CollisionRectangle newRec(position.X, position.Y, position.Height, position.Width, Rotation);
		CollisionTree.InsertElement(newRec, position.X, position.Y);
	}
}