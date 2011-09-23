/*
 * This class represents a Color.
 * Author: Jordan Ell
 * Date: 22/09/11
 */

#include "Color.h"

namespace Game_Framework
{
	Color::Color()
	{
		Red = 0;
		Green = 0;
		Blue = 0;
		Alpha = 255;
	}

	Color::Color(int r, int g, int b, int a)
	{
		Red = r;
		Green = g;
		Blue = b;
		Alpha = a;
	}
}
