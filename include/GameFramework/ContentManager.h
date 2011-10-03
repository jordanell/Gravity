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
#else
	#include "SDL.h"
	#include "SDL_opengl.h"
	#include "SDL_image.h"
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


namespace GameFramework
{
	class ContentManager

	{
		public:
			char RootDirectory[FILENAME_MAX];

			ContentManager();

			GLuint LoadTexture(const std::string &fileName);	
	};
}

#endif
