//
//  Label.h
//
//  Created by Jordan Ell on 07-27-2012.
//  Copyright 2011. All rights reserved.

#ifndef LABEL_H
#define LABEL_H

#include "framework.h"
#include "GuiObject.h"
#include "Scene.h"
#include <list>
#include <string>

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

namespace ManhattanProject
{
	class Label : public GuiObject
	{
        public:
            Label(Game* game);
            Label(Game* game, string writing, int fontSize, Color color, framework::Rectangle size, Scene* scene);
            Label(Game* game, Texture2D* background, string writing, int fontSize, Color color, framework::Rectangle size, Scene* scene);
            
            void Initialize();

            void Update();
            void Draw();
            
            Text* text;
            Texture2D* background;
            
            string Writing;
            int FontSize;

        protected:
            Scene* scene;
	};
}

#endif
