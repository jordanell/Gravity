/*
 * This is the header for Rectangle class.
 * Author: Jordan Ell
 * Date: 21/09/11
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"

namespace GameFramework
{
	class Rectangle
	{
		public:
			int X;
			int Y;
			int Height;
			int Width;

			Rectangle();
			Rectangle(int X, int Y, int Height, int Width);
		
			int Bottom();
			int Left();
			int Right();
			int Top();
			Point* Centre();
			bool ContainsPoint(Point* p);
			bool Intersects(Rectangle* rectangle);
	};
}

#endif

