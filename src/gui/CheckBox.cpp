//
//  CheckBox.cpp
//

#include <iostream>
#include "CheckBox.h"
using namespace framework;

namespace gravity
{

    CheckBox::CheckBox(Game* game, Texture2D* background, framework::Rectangle size, Scene* scene) :
    GuiObject(game)
    {
        this->game = game;

        if (background == NULL)
            this->background = game->Content->LoadTexture("/../content/Form/StandardButton.jpg");
        else
            this->background = background;

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

        this->color = Color(255, 255, 255, 255);
        isActive = false;

        check = game->Content->LoadTexture("Launcher/CheckDot.png");
        hover = game->Content->LoadTexture("Launcher/CheckHover.png");
    }

    void CheckBox::Draw()
    {
        game->Render->Draw(background, size, color);
        if (isActive)
            game->Render->Draw(check, size, color);
        if (isHover)
            game->Render->Draw(hover, size, color);
    }

    void CheckBox::Update()
    {

    }

    void CheckBox::OnLButtonDown(int mX, int mY)
    {
        if (this->size.ContainsPoint(new framework::Point(mX, mY)))
        {
            isActive = !isActive;
        }
    }

    void CheckBox::OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle)
    {
        if (this->size.ContainsPoint(new framework::Point(mX, mY)))
            isHover = true;
        else
            isHover = false;
    }

    bool CheckBox::IsActive()
    {
        return isActive;
    }
}
