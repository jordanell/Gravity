/*
 * This is the header for the Text class.
 * Author: Jordan Ell
 * Date: 29/07/12
 */

#ifndef TEXT_H
#define TEXT_H

#ifdef __linux__
	#include "SDL/SDL.h"
	#include "SDL/SDL_ttf.h"
#else
	#include "SDL.h"
	#include "SDL_ttf.h"
#endif

#include "Color.h"
#include <string>
#include <cstddef>

using namespace std;

namespace framework
{
	class Text
	{
		public:
			Text();
			
			TTF_Font* Font;
			unsigned int Texture;
			
			std::string Writing;
			
			int Size;
			int Width;
			int Height;
			
			Color color;
	};
}

#endif
