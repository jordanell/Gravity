//
//  GuiObject.cpp
//  Game_braden
//
//  Created by Braden Simpson on 11-12-17.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "GuiObject.h"

using namespace framework;

namespace gravity
{

    GuiObject::GuiObject(Game* game) :
    DrawableGameComponent(game)
    {
        this->game = game;
        this->isHover = false;
    }

    GuiObject::GuiObject(Game* game, Texture2D* background, framework::Rectangle size, float rotation, Color color, Scene* scene) :
    DrawableGameComponent(game)
    {
        this->game = game;
        this->background = background;
        this->rotation = rotation;
        this->size = size;
        this->color = color;
        this->scene = scene;
        this->isHover = false;

        Initialize();
    }

    void GuiObject::Initialize()
    {

    }

    void GuiObject::Draw(Camera camera)
    {
        //Draw this guiobject
        game->Render->Draw(background, size, color);
    }

    void GuiObject::Update()
    {
    }
}
