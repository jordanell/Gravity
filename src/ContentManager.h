/*
 * This is the header for the ContentManager class.
 * Author: Jordan Ell
 * Date: 22/09/11
 */

#ifndef CONTENTMANAGER_H
#define CONTENTMANAGER_H

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include "SDL/SDL_image.h"

#include <string>

#include <stdio.h>  /* defines FILENAME_MAX */
#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
 #endif


namespace Game_Framework
{
	class ContentManager

	{
		public:
			char RootDirectory[FILENAME_MAX];

			ContentManager();

			unsigned int LoadTexture(const std::string &fileName);	
	};
}

#endif
