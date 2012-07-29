//
//  DropDown.cpp
//

#include <iostream>
#include "DropDown.h"
using namespace framework;

namespace ManhattanProject
{
    DropDown::DropDown(Game* game, list<string> items, framework::Rectangle size, Scene* scene):
        GuiObject(game)
    {
        this->game = game;
        this->items = items;
		this->size = size;
		this->scene = scene;
		this->Initialize();
    }

    void DropDown::Initialize()
    {
        label = new Label(game, "Something", Color(255,0,0,1), size, scene);
    }

    void DropDown::Draw()
	{
        label->Draw();
	}

	void DropDown::Update()
	{

	}

	void DropDown::CreateList()
	{
        list<string>::iterator it;
        for(it=items.begin(); it != items.end(); it++)
        {
            // Create buttons and ad them to the list
        }
	}

	void DropDown::DestroyList()
	{
        list<Button*>::iterator it;
        for(it=buttons.begin(); it != buttons.end(); it++)
        {
            delete *it;
        }
	}

}
