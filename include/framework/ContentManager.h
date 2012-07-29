/*
 * This is the header for the ContentManager class.
 * Author: Jordan Ell
 * Date: 22/09/11
 */

#ifndef CONTENTMANAGER_H
#define CONTENTMANAGER_H

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

#include <string>

#include <stdio.h>  /* defines FILENAME_MAX */
#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
#endif

#include "Exception.h"
#include "Texture2D.h"
#include "Text.h"
#include <map>

#include "../tinyxml.h"
#include "../tinystr.h"


namespace framework
{
	class ContentManager
	{
		public:
			char RootDirectory[FILENAME_MAX];

			ContentManager();

			Texture2D* LoadTexture(const std::string &fileName);
			void ClearTextureMap();
			
			Text* CreateText(const std::string &fontFile, const std::string &text, Color color, int size);

			TTF_Font* LoadFont(const std::string &fileName, int size);

		protected:
			map<const std::string, Texture2D> Textures;
			map<const std::string, Texture2D>::iterator iterator;

			Texture2D* InsertTexture(const std::string &fileName, Texture2D texture);
			Texture2D* TextureMapContains(const std::string &fileName);
	};
}

#endif
