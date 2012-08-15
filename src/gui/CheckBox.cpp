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
        this->hover = NULL;
        this->check = NULL;

        this->Position = position;
        this->scene = scene;

        this->Initialize();
    }
    
    CheckBox::CheckBox(Game* game, Texture2D* box, Texture2D* hover, framework::Rectangle position, Scene* scene) :
    GuiObject(game)
    {
        this->box = box;
        this->hover = hover;
        this->check = NULL;

        this->Position = position;
        this->scene = scene;

        this->Initialize();
    }
    
    CheckBox::CheckBox(Game* game, Texture2D* box, Texture2D* hover, Texture2D* check, framework::Rectangle position, Scene* scene) :
    GuiObject(game)
    {
        this->box = box;
        this->hover = hover;
        this->check = check;

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
        IsHover = false;
    }

    void CheckBox::Draw()
    {
        game->Render->Draw(box, Position, color);
        if (IsHover && hover != NULL)
            game->Render->Draw(hover, Position, color);
        if (IsActive && check != NULL)
            game->Render->Draw(check, Position, color);
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
    
    bool CheckBox::GetStatus()
    {
        return IsActive;
    }
}
