/*
 * This is the header for the CollisionRectangle class.
 * This class represents a rectangle used for collision as well as contain some extra properties
 * Author: Jordan Ell
 * Date: 20/10/11
 */

#ifndef COLLISIONRECTANGLE_H
#define COLLISIONRECTANGLE_H

#include "framework.h"
#include "MapObject.h"
#include "Camera.h"

using namespace framework;

namespace gravity
{
	class CollisionRectangle: public MapObject
	{
	public:
		CollisionRectangle(Game* game);
		CollisionRectangle(Game* game, Vector2 pos, int Height, int Width);
		CollisionRectangle(Game* game, Vector2 pos, int Height, int Width, float Rotation);

		int Height;
		int Width;
		Color TintColor;

		void Draw(Camera camera);
	};
}

#endif
