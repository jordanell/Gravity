/*
 * This is the header for the RenderEngine class.
 * Author: Jordan Ell
 * Date: 21/09/11
 */

#ifndef RENDERENGINE_H
#define RENDERENGINE_H

#ifdef __linux__
	#include "SDL/SDL.h"
	#include "SDL/SDL_opengl.h"
	#include "SDL/SDL_image.h"
#else
	#include "SDL.h"
	#include "SDL_opengl.h"
	#include "SDL_image.h"
#endif

#include "Texture2D.h"
#include "Rectangle.h"
#include "Color.h"
#include "Vector2.h"

namespace GameFramework
{
	class RenderEngine

	{
		public:
			RenderEngine(const char* windowName, int width, int height, bool fullScreen);

			void PreDraw();
			//Destination rectangle
			void Draw(Texture2D* tex, Rectangle* rec, Color* color);
			void Draw(Texture2D* tex, Rectangle* rec, Rectangle* source, Color* color);
			void Draw(Texture2D* tex, Rectangle* rec, Rectangle* source, Color* color, float rotation);
			//Destination vector
			void Draw(Texture2D* tex, Vector2* vec, Color* color);
			void Draw(Texture2D* tex, Vector2* vec, Rectangle* source, Color* color);
			void Draw(Texture2D* tex, Vector2* vec, Rectangle* source, Color* color, float rotation);
			void PostDraw();
			

		protected:
			int Width;
			int Height;

			void Init(const char* windowName, bool fullScreen);
			
	};
}

#endif
