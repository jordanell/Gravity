/*
 * This is the header for the Color class.
 * Author: Jordan Ell
 * Date: 22/09/11
 */

#ifndef COLOR_H
#define COLOR_H

namespace GameFramework
{
	class Color
	{
		public:
			int Red;
			int Green;
			int Blue;
			int Alpha;

			Color();
            static Color* White();
			Color(int r, int g, int b, int a);
	};
}

#endif
