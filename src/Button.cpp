//
//  Button.cpp
//

#include <iostream>
#include "Button.h"

using namespace GameFramework;

namespace ManhattanProject 
{
    Button::Button(Game* game, Texture2D* background, float s, float rot, Vector2 pos, Color col,
    		GameFramework::Rectangle size, Scene* scene):GuiObject(game, background, s, rot, pos, col, scene)
    {
        this->game = game;
		if (background == NULL)
			// This is a standard button.
			this->background = game->Content->LoadTexture("/../content/Form/StandardButton.jpg");
		else
			this->background = background;
		this->scale = s;
		this->rotation = rot;
		this->position = pos;
		this->color = col;
		this->size = size;
		this->scene = scene;
		this->Initialize();
    }
    
    void Button::Initialize()
    {
    	list<Uint8> events (SDL_MOUSEBUTTONDOWN);
    	this->scene->AddListener(this, events);
    }
    
    void Button::Draw()
	{
		game->Render->Draw(background, Vector2(position.X, position.Y), color);
	}
    
	void Button::Update()
	{

	}

	void Button::onMButtonDown(int mX, int mY)
	{
		if (this->size.ContainsPoint(new GameFramework::Point(mX, mY)))
		{
			cout << "PRESSED DOWN\n";
		}
	}

}
