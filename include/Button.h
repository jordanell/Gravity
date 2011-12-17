//
//  Button.h
//  Game_braden
//
//  Created by Braden Simpson on 11-12-16.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef Game_braden_Button_h
#define Game_braden_Button_h

#include "GameFramework.h"
#include "Scene.h"

using namespace GameFramework;

namespace ManhattanProject
{
	class Button : public DrawableGameComponent
	{
    public:
        Button (Texture2D* background, Game* game);
        //Button (Texture2D* background, Texture2D* hover, Texture2D* active);
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