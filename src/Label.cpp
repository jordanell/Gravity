//
//  Label.cpp
//

#include <iostream>
#include "Label.h"
using namespace GameFramework;

namespace ManhattanProject
{
    Label::Label(Game* game, string text, Color color, GameFramework::Rectangle size, Scene* scene):
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
        font = game->Content->LoadFont("Fonts/CathedralNormal.ttf", 20);
    }

    void Label::Draw()
	{
        game->Render->Write(font, size, "800 X 600", color);
	}

	void Label::Update()
	{

	}
}
