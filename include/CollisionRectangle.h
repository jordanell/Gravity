/*
 * This is the header for the CollisionRectangle class.
 * This class represents a rectangle used for collision as well as contain some extra properties
 * Author: Jordan Ell
 * Date: 20/10/11
 */

#ifndef COLLISIONRECTANGLE_H
#define COLLISIONRECTANGLE_H

#include "GameFramework.h"

using namespace GameFramework;

namespace ManhattanProject
{
	class CollisionRectangle: public Rectangle
	{
	public:
		CollisionRectangle();
		CollisionRectangle(int X, int Y, int Height, int Width);
		CollisionRectangle(int X, int Y, int Height, int Width, float Rotation);
		
		float Rotation;
	};
}

#endif