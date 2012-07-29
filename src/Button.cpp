//
//  Button.cpp
//

#include <iostream>
#include "Button.h"
using namespace framework;

namespace ManhattanProject
{
    void DefaultFunc(Game* game, Scene* sm) {
        cout << "Default button listener";
    }

    Button::Button(Game* game, Texture2D* background, float s, float rot, Vector2 pos, Color col,
    		framework::Rectangle size, Scene* scene):GuiObject(game, background, s, rot, pos, col, scene)
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
        this->LButtonDownCallback = &DefaultFunc;
		this->Initialize();
    }

    void Button::Initialize()
    {
		list<Uint8> listeners;
		listeners.push_back(SDL_MOUSEBUTTONDOWN);
		scene->AddListener(this, listeners);
    }

    void Button::Draw()
	{
		game->Render->Draw(background, this->position, color);
	}

	void Button::Update()
	{

	}

	void Button::OnLButtonDown(int mX, int mY)
	{
		if (this->size.ContainsPoint(new framework::Point(mX, mY)))
		{
			if (this->LButtonDownCallback != NULL)
                this->LButtonDownCallback(game, scene);
			return;
		}
	}

	void Button::SetText(string text)
	{
	    this->text = text;
	}

	string Button::GetText()
	{
	    return this->text;
	}

}
