/*
 * This class represents a 2D Line.
 * Author: Jordan Ell
 * Date: 21/01/12
 */

#include "Line2.h"

using namespace std;

namespace framework
{	
	Line2::Line2()
	{
		p1 = new Point();
		p2 = new Point();
	}
	
	Line2::Line2(float X1, float Y1, float X2, float Y2)
	{
		p1 = new Point(X1, Y1);
		p2 = new Point(X2, Y2);
	}
	
	float Line2::Length()
	{
		return sqrt(((p1->X - p2->X)*(p1->X - p2->X)) + ((p1->Y - p2->Y)*(p1->Y - p2->Y)));
	}
	
	Point* Line2::IntersectsWith(Line2* line)
	{
		float d = (p1->X - p2->X) * (line->p1->Y - line->p2->Y) - (p1->Y - p2->Y) * (line->p1->X - line->p2->X);
		// If d is zero, there is no intersection
		if(d == 0)
			return NULL;
			
		// Get the x and y
		float pre = (p1->X*p2->Y - p1->Y*p2->X), post = (line->p1->X*line->p2->Y - line->p1->Y*line->p2->X);
		float x = ( pre * (line->p1->X - line->p2->X) - (p1->X - p2->X) * post ) / d;
		float y = ( pre * (line->p1->Y - line->p2->Y) - (p1->Y - p2->Y) * post ) / d;
		
		// Check if the x and y coordinates are within both lines
		if ( x < min(p1->X, p2->X) || x > max(p1->X, p2->X) ||
			x < min(line->p1->X, line->p2->X) || x > max(line->p1->X, line->p2->X) ) return NULL;
		if ( y < min(p1->Y, p2->Y) || y > max(p1->Y, p2->Y) ||
			y < min(line->p1->Y, line->p2->Y) || y > max(line->p1->Y, line->p2->Y) ) return NULL;
		
		// Return the point of intersection
		Point* ret = new Point();
		ret->X = x;
		ret->Y = y;
		return ret;
	}
}
