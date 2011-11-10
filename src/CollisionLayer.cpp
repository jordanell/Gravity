/*
 * This is the implementation file for the CollisionLayer class.
 * Author: Jordan Ell
 * Date: 16/10/11
 */

#include "CollisionLayer.h"

using namespace GameFramework;

namespace ManhattanProject
{
	CollisionLayer::CollisionLayer(Game* game, GameFramework::Rectangle Size)
	{
		this->game = game;
		this->Size = Size;
	}

	bool CollisionLayer::CheckCollision(GameFramework::Rectangle* rec)
	{
		return false;
	}

	void CollisionLayer::AddCollision(GameFramework::Rectangle position, float Rotation)
	{
		CollisionRectangle newRec(position.X, position.Y, position.Height, position.Width, Rotation);
		CollisionTree.InsertElement(newRec, position.X, position.Y);
	}
}
