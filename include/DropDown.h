//
//  DropDown.h
//
//  Created by Jordan Ell on 07-27-2012.
//  Copyright 2011. All rights reserved.

#ifndef DROPDOWN_H
#define DROPDOWN_H

#include "GameFramework.h"
#include "GuiObject.h"
#include "InputEvent.h"
#include "Button.h"
#include "Label.h"
#include "Scene.h"
#include <list>
#include <string>

using namespace GameFramework;

namespace ManhattanProject
{
	class DropDown : public GuiObject, public InputEvent
	{
        public:
            DropDown(Game* game);
            DropDown(Game* game, list<string> items, GameFramework::Rectangle size, Scene* scene);
            void Initialize();

            void CreateList();
            void DestroyList();

            void Update();
            void Draw();

            list<string> items;
            list<Button*> buttons;
            Button* dropDownArrow;
            Label* label;

        protected:
            Scene* scene;
	};
}

#endif
