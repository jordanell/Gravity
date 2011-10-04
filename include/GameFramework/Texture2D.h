/*
 * This is the header for the Texture2D class.
 * Author: Jordan Ell
 * Date: 22/09/11
 */

#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include <cstddef>

namespace GameFramework
{
	class Texture2D

	{
		public:
			Texture2D();

			unsigned int* Texture;
			int Width;
			int Height;
			
	};
}

#endif
