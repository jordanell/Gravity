//
//  GuiObject.h
//  Game_braden
//
//  Created by Braden Simpson on 11-12-17.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef GUIOBJECT_H
#define GUIOBJECT_H

#include "GameFramework.h"
#include "Camera.h"
#include "DrawableGameComponent.h"
#include "Scene.h"

using namespace GameFramework;

namespace ManhattanProject
{
    class GuiObject: public DrawableGameComponent
    {
        public:
            GuiObject(Game* game);
            GuiObject(Game* game, Texture2D* background, float s, float rot, Vector2 pos, Color col, Scene* scene);
            void Initialize();
            void Update();
            void Draw(Camera camera);
            float scale;
            float rotation;
            GameFramework::Rectangle size;
            Vector2 position;
            Color color;

        protected:
            Texture2D* background;
            Texture2D* hover;
            Texture2D* active;
            Game* game;
            Scene* scene;
    };
}
#endif
