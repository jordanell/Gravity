/*
 * This is the header for the CollisionLayer class.
 * This class is used to hold a list of collision objects and can check for collision
 * Author: Jordan Ell
 * Date: 16/10/11
 */

#ifndef COLLISIONLAYER_H
#define COLLISIONLAYER_H

#include "framework.h"
#include "QuadTree.h"
#include "CollisionRectangle.h"
#include "Camera.h"
#include <list>

using namespace framework;

namespace ManhattanProject
{
	class CollisionLayer
	{
		public:
			CollisionLayer(Game* game, framework::Rectangle Size);

			bool CheckCollision(framework::Rectangle* rec);
	
			void AddCollision(CollisionRectangle* collision);

			void AddCollision(Vector2 pos, int Width, int Height, float Rotation);

			list<CollisionRectangle*> GetCollisions();

			void Draw(Camera camera);

		protected:
			Game* game;
			framework::Rectangle Size;

			QuadTree<CollisionRectangle*>* CollisionTree;
			list<CollisionRectangle*> ActiveCollisions;
	};
}

#endif
