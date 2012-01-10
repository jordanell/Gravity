//
//  GuiObject.cpp
//  Game_braden
//
//  Created by Braden Simpson on 11-12-17.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "GuiObject.h"

using namespace GameFramework;

namespace ManhattanProject
{
	GuiObject::GuiObject(Game* game):
        DrawableGameComponent(game)
	{
		this->game = game;
	}
	
	GuiObject::GuiObject(Game* game, Texture2D* background, float s, float rot, Vector2 pos, Color col, Scene* scene):
        DrawableGameComponent(game)
	{
		this->game = game;
		background = background;
		scale = s;
		rotation = rot;
		position = pos;
		color = col;
		this->scene = scene;
	}
	
    void GuiObject::Initialize()
    {
        
    }
    
	void GuiObject::Draw(Camera camera)
	{
		//Draw this guiobject
		game->Render->Draw(background, Vector2(position.X-camera.Position.X, position.Y-camera.Position.Y), color);
	}
	
	void GuiObject::Update()
	{
    }
}
