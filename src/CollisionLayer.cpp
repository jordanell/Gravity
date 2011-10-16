/*
 * This is the implementation file for the CollisionLayer class.
 * Author: Jordan Ell
 * Date: 16/10/11
 */

#include "CollisionLayer.h"

using namespace GameFramework;

namespace ManhattanProject
{
	CollisionLayer::CollisionLayer(Game* game)
	{
		this->game = game;
	}
	
	bool CollisionLayer::CheckCollision(Rectangle* rec)
	{
	
	}
	
	void CollisionLayer::AddCollision(int x, int y, int height, int width)
	{
		Rectangle newRec(x, y, height, width);
		collisions.push_back(newRec);
	}
}