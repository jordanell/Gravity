/* 
 * File:   CharacterMap.h
 * Author: jordan
 *
 * Created on July 30, 2012, 1:17 PM
 */

#ifndef CHARACTERMAP_H
#define	CHARACTERMAP_H

#include "framework.h"
#include "GuiObject.h"
#include <string>
#include <map>
#include <fstream>

#ifdef __linux__	
  #include "SDL/SDL_ttf.h"
  #include "SDL/SDL.h"
  #include "SDL/SDL_opengl.h"
#else
  #include "SDL_ttf.h"
  #include "SDL.h"
  #include "SDL_opengl.h"
#endif

using namespace framework;

namespace gravity
{
    class CharacterMap: public GuiObject
    {
      public:
        CharacterMap(Game* game);
        CharacterMap(Game* game, string font, int fontsize);
        
        Texture2D* GetCharacter(string character);
        
        int SpaceSize;
        
      private:
        int FontSize;
        string FontName;
        TTF_Font* Font;
        
        map<string,Texture2D*> CharMap;
        
        void LoadFont(string font);
        void RenderFont();
        
    };
}

#endif	/* CHARACTERMAP_H */

