/*
 * This is the definition for the ContentManager class.
 * Author: Jordan Ell
 * Date: 22/09/11
 */

#include "ContentManager.h"

namespace Game_Framework
{
	ContentManager::ContentManager()
	{
		GetCurrentDir(RootDirectory, sizeof(RootDirectory));
		RootDirectory[sizeof(RootDirectory) -1] = '\0';
	}

	unsigned int ContentManager::LoadTexture(const std::string &fileName)
	{
		SDL_Surface *image = IMG_Load(fileName.c_str());

		SDL_DisplayFormatAlpha(image);
	
		unsigned object(0);

		glGenTextures(1, &object);

		glBindTexture(GL_TEXTURE_2D, object);

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	  	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	 
	  	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	  	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->w, image->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);
	 
	 	 //Free surface
	 	 SDL_FreeSurface(image);

		return object;
	}	
}
