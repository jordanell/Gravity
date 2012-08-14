//
//  CheckBox.cpp
//

#include <iostream>
#include "CheckBox.h"
using namespace framework;

namespace gravity
{

    CheckBox::CheckBox(Game* game, Texture2D* box, framework::Rectangle position, Scene* scene) :
    GuiObject(game)
    {
        this->box = box;

        this->Position = position;
        this->scene = scene;

        this->Initialize();
    }

    void CheckBox::Initialize()
    {
        list<Uint8> listeners;
        listeners.push_back(SDL_MOUSEBUTTONDOWN);
        listeners.push_back(SDL_MOUSEMOTION);
        scene->AddListener(this, listeners);

        this->color = Color(255, 255, 255, 255);
        IsActive = false;

        check = game->Content->LoadTexture("scene/launcher/CheckDot.png");
        hover = game->Content->LoadTexture("scene/launcher/CheckHover.png");
    }

    void CheckBox::Draw()
    {
        game->Render->Draw(box, Position, color);
        if (IsActive)
            game->Render->Draw(check, Position, color);
        if (IsHover)
            game->Render->Draw(hover, Position, color);
    }

    void CheckBox::Update()
    {

    }

    void CheckBox::OnLButtonDown(int mX, int mY)
    {
        if (this->Position.ContainsPoint(new framework::Point(mX, mY)))
        {
            IsActive = !IsActive;
        }
    }

    void CheckBox::OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle)
    {
        if (this->Position.ContainsPoint(new framework::Point(mX, mY)))
            IsHover = true;
        else
            IsHover = false;
    }
}
