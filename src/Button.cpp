//
//  Button.cpp
//  Game_braden
//
//  Created by Braden Simpson on 11-12-16.
//

#include <iostream>
#include "Button.h"

using namespace GameFramework;

namespace ManhattanProject 
{
    Button::Button(Game* game, Texture2D* background, float s, float rot, Vector2 pos, Color col): Tile(game, background, s, rot, pos, col)
    {
        this->game = game;
		this->background = background;
		this->scale = s;
		this->rotation = rot;
		this->position = pos;
		this->color = col;
        this->Initialize();
    }
    
    void Button::Initialize()
    {
        DrawableGameComponent::Initialize();
    }
    
    void Button::Draw()
	{
		game->Render->Draw(background, Vector2(position.X, position.Y), color);
		DrawableGameComponent::Draw();
	}
    
	void Button::Update()
	{
		DrawableGameComponent::Update();
	}
}