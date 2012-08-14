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
        
        Initialize();
    }

    void GuiObject::Initialize()
    {
        
    }

    void GuiObject::Draw()
    {
        
        DrawableGameComponent::Draw();
    }

    void GuiObject::Update()
    {
        
        DrawableGameComponent::Update();
    }
}
