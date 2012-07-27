//
//  CheckBox.cpp
//

#include <iostream>
#include "CheckBox.h"
using namespace GameFramework;

namespace ManhattanProject
{
    CheckBox::CheckBox(Game* game, Texture2D* box, float s, float rot, Vector2 pos, Color col,
    		GameFramework::Rectangle size, Scene* scene):GuiObject(game, box, s, rot, pos, col, scene)
    {
        this->game = game;
        if (box == NULL)
			this->box = game->Content->LoadTexture("/../content/Form/StandardButton.jpg");
		else
			this->box = box;
		this->scale = s;
		this->rotation = rot;
		this->position = pos;
		this->color = col;
		this->size = size;
		this->scene = scene;
		this->Initialize();
    }

    void CheckBox::Initialize()
    {
		list<Uint8> listeners;
		listeners.push_back(SDL_MOUSEBUTTONDOWN);
		listeners.push_back(SDL_MOUSEMOTION);
		scene->AddListener(this, listeners);

		isChecked = false;

		check = game->Content->LoadTexture("Launcher/Check.jpg");
		active = game->Content->LoadTexture("Launcher/button2.png");
    }

    void CheckBox::Draw()
	{
        game->Render->Draw(box, this->position, color);
        if(isChecked)
            game->Render->Draw(check, size, color);
        if(isActive)
            game->Render->Draw(active, size, color);
	}

	void CheckBox::Update()
	{

	}

	void CheckBox::OnLButtonDown(int mX, int mY)
	{
		if (this->size.ContainsPoint(new GameFramework::Point(mX, mY)))
		{
			isChecked = !isChecked;
		}
	}

	void CheckBox::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle)
	{
        if (this->size.ContainsPoint(new GameFramework::Point(mX, mY)))
			isActive = true;
		else
            isActive = false;
	}

}
