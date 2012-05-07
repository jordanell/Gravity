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
		CollisionTree = new QuadTree<CollisionRectangle*>(Size.Height, Size.Width, Size.X, Size.Y, DEFAULT_QUADTREE_RECT);
	}

	bool CollisionLayer::CheckCollision(GameFramework::Rectangle* rec)
	{
		return false;
	}

    void CollisionLayer::AddCollision(CollisionRectangle* collision)
	{
		CollisionTree->InsertElement(collision, collision->Position.X, collision->Position.Y);
	}

	void CollisionLayer::AddCollision(Vector2 pos, int Width, int Height, float Rotation)
	{
		CollisionRectangle* newRec = new CollisionRectangle(game, pos, Height, Width, Rotation);
		CollisionTree->InsertElement(newRec, pos.X, pos.Y);
	}

	list<CollisionRectangle*> CollisionLayer::GetCollisions()
	{
		return ActiveCollisions;
	}

	void CollisionLayer::Draw(Camera camera)
	{
		//Get the list of collisions to draw
		ActiveCollisions = CollisionTree->GetElements(camera.GetRectangle());

		// Sort the list based on z index
		ActiveCollisions.sort();

		//Iterate over list and draw the collisions
		for(list<CollisionRectangle*>::iterator it = ActiveCollisions.begin(); it != ActiveCollisions.end(); it++)
		{
			CollisionRectangle* ptr = *it;
			ptr->Draw(camera);
		}
	}
}
