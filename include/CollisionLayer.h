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
#include "Camera.h"
#include <list>

using namespace GameFramework;

namespace ManhattanProject
{
	class CollisionLayer
	{
		public:
			CollisionLayer(Game* game, GameFramework::Rectangle Size);

			bool CheckCollision(GameFramework::Rectangle* rec);

			void AddCollision(Vector2 pos, int Width, int Height, float Rotation);

			list<CollisionRectangle*> GetCollisions();

			void Draw(Camera camera);

		protected:
			Game* game;
			GameFramework::Rectangle Size;

			QuadTree<CollisionRectangle*>* CollisionTree;
			list<CollisionRectangle*> ActiveCollisions;
	};
}

#endif
