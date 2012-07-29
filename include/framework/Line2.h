/*
 * This is the header for Line2 class.
 * This class represents a line in 2D space.
 * Author: Jordan Ell
 * Date: 21/01/12
 */

#ifndef LINE2_H
#define LINE2_H

#include "Point.h"
#include <iostream>
#include <algorithm>
#include <math.h>

namespace framework
{
	class Line2
	{
		public:
			Point* p1;
			Point* p2;
		
			Line2();
			Line2(float X1, float Y1, float X2, float Y2);
		
			float Length();
			Point* IntersectsWith(Line2* line);
	};
}

#endif

