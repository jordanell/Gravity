//
//  Button.cpp
//

#include <iostream>
#include "Button.h"
using namespace framework;

namespace gravity
{

    void DefaultFunc(Game* game, Scene* sm)
    {
        cout << "Default button listener";
    }

    Button::Button(Game* game, Texture2D* button, framework::Rectangle position, Scene* scene) :
    GuiObject(game)
    {
        this->button = button;

        this->Position = position;
        this->scene = scene;
        this->LButtonDownCallback = &DefaultFunc;
        
        this->Initialize();
    }

    void Button::Initialize()
    {
        list<Uint8> listeners;
        listeners.push_back(SDL_MOUSEBUTTONDOWN);
        listeners.push_back(SDL_MOUSEMOTION);
        scene->AddListener(this, listeners);
        IsActive = false;

        this->color = Color(255, 255, 255, 255);
    }

    void Button::Draw()
    {
        game->Render->Draw(button, this->Position, color);
        
        GuiObject::Draw();
    }

    void Button::Update()
    {
        
        GuiObject::Update();
    }

    void Button::OnLButtonDown(int mX, int mY)
    {
        if (this->Position.ContainsPoint(new framework::Point(mX, mY)))
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

    void Button::OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle)
    {
        if (this->Position.ContainsPoint(new framework::Point(mX, mY)))
            IsHover = true;
        else
            IsHover = false;
    }

}
