//
//  Button.h
//
//  Created by Braden Simpson on 11-12-16.
//  Copyright 2011. All rights reserved.

#ifndef BUTTON_H
#define BUTTON_H

#include "framework.h"
#include "GuiObject.h"
#include "InputEvent.h"
#include "Scene.h"
#include <list>

using namespace framework;

namespace ManhattanProject {

    class Button : public GuiObject, public InputEvent {
    public:
        Button(Game* game);
        Button(Game* game, Texture2D* background, framework::Rectangle size, Scene* scene);

        void Initialize();

        void Update();
        void Draw();

        void (*LButtonDownCallback)(Game* game, Scene* scene);
        void OnLButtonDown(int mX, int mY);
        void OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle);

        void SetText(string text);
        string GetText();

    protected:
        string text;
    };
}

#endif
