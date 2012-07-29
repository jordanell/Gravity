//
//  Label.cpp
//

#include <iostream>
#include "Label.h"
using namespace framework;

namespace ManhattanProject
{
    Label::Label(Game* game, string text, Color color, framework::Rectangle size, Scene* scene):
        GuiObject(game)
    {
        this->game = game;
		this->size = size;
		this->color = color;
		this->text = text;

		Initialize();
    }

    void Label::Initialize()
    {
        font = game->Content->LoadFont("Fonts/TanglewoodTales.ttf", 24);
    }

    void Label::Draw()
	{
        game->Render->Write(font, size, "Testing Text", color);
	}

	void Label::Update()
	{

	}
}
