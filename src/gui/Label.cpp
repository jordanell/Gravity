/* 
 * File:   Label.cpp
 * Author: jordan
 * 
 * Created on July 30, 2012, 7:10 PM
 */

#include "Label.h"

namespace ManhattanProject
{

    Label::Label(Game* game):
    GuiObject(game)
    {

    }

    Label::Label(Game* game, Texture2D* background, framework::Rectangle position, Color backgroundColor,
            Color fontColor, string text, CharacterMap* charMap):
    GuiObject(game)
    {
        this->Background = background;
        this->Position = position;
        this->color = backgroundColor;
        
        this->Text = new TextBox(game, position, text, fontColor, charMap);
    }

    void Label::SetText(string text)
    {
        this->Text->UpdateText(text);
    }

    void Label::Draw()
    {
        game->Render->Draw(Background, Position, color);
        Text->Draw();
    }

    void Label::Update()
    {

    }

}