/*
 * This is the definition for the ContentManager class.
 * Author: Jordan Ell
 * Date: 22/09/11
 */

#include "ContentManager.h"
#include <iostream>

namespace framework
{
	ContentManager::ContentManager()
	{
		GetCurrentDir(RootDirectory, sizeof(RootDirectory));
		RootDirectory[sizeof(RootDirectory) -1] = '\0';
	}

	Texture2D* ContentManager::LoadTexture(const std::string &fileName)
	{
		std::string file = GetCurrentDir(RootDirectory, sizeof(RootDirectory));
		file += "/../content/";
		file += fileName;

		Texture2D* texture;

		//Check if the texture is already loaded
		texture = TextureMapContains(fileName);
		if(texture != NULL)
			return texture;

		Texture2D tex;

		//The texture is not in the map so load the texture
		SDL_Surface *image = IMG_Load(file.c_str());

		if(!image)
		{
			throw Exception("File does not exist", 200, __FILE__, __LINE__);
		}

		image = SDL_DisplayFormatAlpha(image);
		unsigned object(0);

		glGenTextures(1, &object);

		glBindTexture(GL_TEXTURE_2D, object);

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	  	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	  	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	  	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->w, image->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, image->pixels);

		tex.Width = image->w;
		tex.Height = image->h;
		tex.Texture = object;

	 	 //Free surface
	 	 SDL_FreeSurface(image);

		//Insert texture into map
		texture = InsertTexture(fileName, tex);

		return texture;
	}

	Texture2D* ContentManager::InsertTexture(const std::string &fileName, Texture2D texture)
	{
		iterator = Textures.end();
		Textures.insert(iterator, pair<const std::string, Texture2D>(fileName.c_str(), texture));

		return &Textures.find(fileName.c_str())->second;
	}

	Texture2D* ContentManager::TextureMapContains(const std::string &fileName)
	{
		iterator = Textures.find(fileName.c_str());

		if(iterator != Textures.end())
			return &(iterator->second);
		else
			return NULL;
	}

	void ContentManager::ClearTextureMap()
	{
		Textures.clear();
	}
        
        TTF_Font* ContentManager::LoadFont(string fileName, int size)
        {
            string file = GetCurrentDir(RootDirectory, sizeof(RootDirectory));
            file += "/../content/";
            file += fileName;
            
            TTF_Font* font;
            font = TTF_OpenFont(file.c_str(), size);
            
            if(font == NULL)
                throw Exception("File does not exist", 200, __FILE__, __LINE__);
            return font;
        }
}
