//
//  Label.cpp
//

#include <iostream>
#include "Label.h"
using namespace framework;

namespace ManhattanProject
{
    Label::Label(Game* game, string writing, int fontSize, Color color, framework::Rectangle size, Scene* scene):
        GuiObject(game)
    {
        this->game = game;
		this->size = size;
		this->color = color;
		this->Writing = writing;
		this->FontSize = fontSize;

		Initialize();
    }
    
    Label::Label(Game* game, Texture2D* background, string writing, int fontSize, Color color, framework::Rectangle size, Scene* scene):
		GuiObject(game)
	{
		this->game = game;
		this->size = size;
		this->color = color;
		this->Writing = writing;
		this->FontSize = fontSize;
		this->background = background;

		Initialize();
	}

    void Label::Initialize()
    {
		text = game->Content->CreateText("Fonts/TanglewoodTales.ttf", Writing.c_str(), color, FontSize);
    }

    void Label::Draw()
	{
        game->Render->Write(text, size, color);
	}

	void Label::Update()
	{

	}
}
