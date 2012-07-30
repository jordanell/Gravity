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
	#include "SDL/SDL_ttf.h"
#else
	#include "SDL.h"
	#include "SDL_opengl.h"
	#include "SDL_image.h"
	#include "SDL_ttf.h"
#endif

#include "Texture2D.h"
#include "Rectangle.h"
#include "Color.h"
#include "Vector2.h"

#include <math.h>

namespace framework
{
	class RenderEngine
	{
		public:
			RenderEngine(const char* windowName, int width, int height, bool fullScreen);

			void PreDraw();
			//Destination rectangle
			void Draw(Texture2D* tex, Rectangle rec, Color color);
			void Draw(Texture2D* tex, Rectangle rec, Color color, float rotation, float scale);
			void Draw(Texture2D* tex, Rectangle rec, Rectangle source, Color color, float rotation, float scale);
			//Destination vector
			void Draw(Texture2D* tex, Vector2 vec, Color color);
			void Draw(Texture2D* tex, Vector2 vec, Color color, float rotation, float scale);
			void Draw(Texture2D* tex, Vector2 vec, Rectangle source, Color color, float rotation, float scale);
			void PostDraw();

			bool GetFullScreen();
			int GetWidth();
			int GetHeight();

			void SetCaption(const char* windowName);
			void SetResolution(int width, int height);
			void SetFullScreen(bool fullScreen);


		protected:
			int Width;
			int Height;
			bool FullScreen;

			void Init(const char* windowName, bool fullScreen);

	};
}

#endif
