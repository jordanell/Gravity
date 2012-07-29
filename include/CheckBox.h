//
//  CheckBox.h
//
//  Created by Jordan Ell 07-27-2012.
//  Copyright 2011. All rights reserved.

#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "framework.h"
#include "GuiObject.h"
#include "InputEvent.h"
#include "Scene.h"
#include <list>

using namespace framework;

namespace ManhattanProject
{
	class CheckBox : public GuiObject, public InputEvent
	{
        public:
            CheckBox(Game* game);
            CheckBox(Game* game, Texture2D* background, framework::Rectangle size, Scene* scene);
            
            void Initialize();
            
            void Update();
            void Draw();
            
            void OnLButtonDown(int mX, int mY);
            void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);
            
            bool IsActive();

        protected:
            Texture2D* check;
            Scene* scene;

	};
}

#endif
