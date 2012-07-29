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
#else
	#include "SDL_ttf.h"
#endif

using namespace framework;

namespace ManhattanProject
{
	class Label : public GuiObject
	{
        public:
            Label(Game* game);
            Label(Game* game, string text, Color color, framework::Rectangle size, Scene* scene);
            void Initialize();

            void Update();
            void Draw();

            string text;
            Color color;

        protected:
            TTF_Font* font;
            Scene* scene;
	};
}

#endif
