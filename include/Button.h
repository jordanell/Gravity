//
//  Button.h
//
//  Created by Braden Simpson on 11-12-16.
//  Copyright 2011. All rights reserved.

#ifndef BUTTON_H
#define BUTTON_H

#include "GameFramework.h"
#include "GuiObject.h"
#include "InputEvent.h"
#include "Scene.h"
#include <list>

using namespace GameFramework;

namespace ManhattanProject
{
	class Button : public GuiObject, public InputEvent
	{
        public:
            Button(Game* game);
            Button(Game* game, Texture2D* background, float s, float rot,
            		Vector2 pos, Color col, Rectangle size, Scene* scene);
            void Initialize();
            void Update();
            void Draw();
            void (*LButtonDownCallback)(Game* game, Scene* scene);
            //void (Button::*LButtonDownCallback)();
            void OnLButtonDown(int mX, int mY);
        protected:
            Texture2D* background;
            Texture2D* hover;
            Texture2D* active;
            Scene* scene;
	};
}

#endif
