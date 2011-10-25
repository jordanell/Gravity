/*
 * This is the header for the CollisionLayer class.
 * This class is used to hold a list of collision objects and can check for collision
 * Author: Jordan Ell
 * Date: 16/10/11
 */

#ifndef COLLISIONLAYER_H
#define COLLISIONLAYER_H

#include "GameFramework.h"
#include "QuadTree.h"
#include "CollisionRectangle.h"
#include <list>

using namespace GameFramework;

namespace ManhattanProject
{
	class CollisionLayer
	{
		public:
			CollisionLayer(Game* game, Rectangle Size);
		
			bool CheckCollision(Rectangle* rec);
		
			void AddCollision(Rectangle position, float Rotation);
		
		protected:
			Game* game;
			Rectangle Size;
		
			QuadTree<Rectangle> CollisionTree;
			list<Rectangle*> ActiveCollisions;
	};
}

#endif