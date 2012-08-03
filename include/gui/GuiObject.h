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
    class GuiObject: public DrawableGameComponent
    {
        public:
            GuiObject(Game* game);
            GuiObject(Game* game, Texture2D* background, framework::Rectangle size, float rotation, Color color, Scene* scene);
            
            void Initialize();
            
            void Update();
            void Draw(Camera camera);
            
            float rotation;
            framework::Rectangle size;
            Color color;

        protected:
            Texture2D* background;
            Texture2D* hover;
            Texture2D* active;
            
            bool isActive;
            bool isHover;
            
            Scene* scene;
    };
}
#endif
