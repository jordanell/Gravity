/*
 * This is the header for the RenderEngine class.
 * Author: Jordan Ell
 * Date: 21/09/11
 */

#ifndef RENDERENGINE_H
#define RENDERENGINE_H

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include "SDL/SDL_image.h"

namespace Game_Framework
{
	class RenderEngine

	{
		public:
			RenderEngine(char* windowName, int width, int height, bool fullScreen);

			void PreDraw();
			void Draw();
			void PostDraw();
			

		protected:
			int width;
			int height;

			void Init(char* windowName, int width, int height, bool fullScreen);
			
	};
}

#endif
