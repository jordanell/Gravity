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
		
		//Instantiate the QuadTree
		CollisionTree = new QuadTree<MapObject*>(Size.Height, Size.Width, Size.X, Size.Y, DEFAULT_QUADTREE_RECT);
	}

	bool CollisionLayer::CheckCollision(GameFramework::Rectangle* rec)
	{
		return false;
	}

	void CollisionLayer::AddCollision(int X, int Y, int Width, int Height, float Rotation)
	{
		CollisionRectangle* newRec = new CollisionRectangle(X, Y, Height, Width, Rotation);
		CollisionTree->InsertElement(newRec, X, Y);
	}
}
