/*
 * This is the header for the Color class.
 * Author: Jordan Ell
 * Date: 22/09/11
 */

#ifndef COLOR_H
#define COLOR_H

namespace Game_Framework
{
	class Color

	{
		public:
			int Red;
			int Green;
			int Blue;
			int Alpha;

			Color();
			Color(int r, int g, int b, int a);
	};
}

#endif
