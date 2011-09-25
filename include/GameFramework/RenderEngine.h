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

#include "Texture2D.h"
#include "Rectangle.h"
#include "Color.h"
#include "Vector2.h"

namespace Game_Framework
{
	class RenderEngine

	{
		public:
			RenderEngine(char* windowName, int width, int height, bool fullScreen);

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

			void Init(char* windowName, bool fullScreen);
			
	};
}

#endif
