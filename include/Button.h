//
//  Button.h
//  Game_braden
//
//  Created by Braden Simpson on 11-12-16.
//  Copyright 2011 __MyCompanyName__. All rights reserved.

#ifndef BUTTON_H
#define BUTTON_H

#include "GameFramework.h"
#include "GuiObject.h"

using namespace GameFramework;

namespace ManhattanProject
{
	class Button : public GuiObject
	{
        public:
            Button(Game* game);
            Button(Game* game, Texture2D* background, float s, float rot, Vector2 pos, Color col);
            void Initialize();
            void Update();
            void Draw();
        
        protected:
            Texture2D* background;
            Texture2D* hover;
            Texture2D* active;
	};
}

#endif