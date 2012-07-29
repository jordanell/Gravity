/*
 * This class represents a 2D point.
 * Author: Jordan Ell
 * Date: 21/09/11
 */

#include "Point.h"

namespace framework
{
	Point::Point()
	{
		X = 0;
		Y = 0;
	}

	Point::Point(float X, float Y)
	{
		this->X = X;
		this->Y = Y;
	}
}
