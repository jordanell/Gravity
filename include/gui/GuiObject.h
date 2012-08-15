//
//  GuiObject.h
//  Game_braden
//
//  Created by Braden Simpson on 11-12-17.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef GUIOBJECT_H
#define GUIOBJECT_H

#include "framework.h"
#include "Camera.h"
#include "DrawableGameComponent.h"
#include "Scene.h"

using namespace framework;

namespace gravity
{
    class GuiObject : public DrawableGameComponent
    {
      public:
        GuiObject(Game* game);

        void Initialize();

        void Update();
        void Draw();
    };
}
#endif
