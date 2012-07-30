/* 
 * File:   TextBox.cpp
 * Author: jordan
 * 
 * Created on July 30, 2012, 2:58 PM
 */

#include "TextBox.h"

using namespace framework;

namespace ManhattanProject
{

    TextBox::TextBox(Game* game) :
    GuiObject(game)
    {

    }

    TextBox::TextBox(Game* game, framework::Rectangle position, string text, Color color, CharacterMap* charmap) :
    GuiObject(game)
    {
        this->Position = position;
        this->Text = text;
        this->CharMap = charmap;
        this->color = color;
        
        this->Cursor = Vector2(Position.X, Position.Y);
    }
    
    void TextBox::UpdateText(string text)
    {
        this->Text = text;
    }

    void TextBox::Draw()
    {
        char cText[Text.size()];
        int size = Text.size();
        for(int x = 0; x <= size; x++)
            cText[x]=Text[x];
        
        char* pch = strtok(cText, " ");
        while(pch != NULL)
        {
            DrawWord(pch);
            pch = strtok(NULL, " ");
        }
        
        Cursor.X = Position.X;
        Cursor.Y = Position.Y;
    }

    void TextBox::DrawWord(string word)
    {
        if(Cursor.X + WordPixelSize(word) > Position.X + Position.Width)
            MoveCursorNextLine();
        int size = word.size();
        for(int x = 0; x < size; x++)
            DrawCharacter(word.substr(x,1));
        Cursor.X += CharMap->SpaceSize;
    }

    void TextBox::DrawCharacter(string character)
    {
        Texture2D* tex = CharMap->GetCharacter(character);
        game->Render->Draw(tex, Cursor, color);
        Cursor.X = Cursor.X + tex->Width;
    }
    
    void TextBox::MoveCursorNextLine()
    {
        int height = CharMap->GetCharacter("A")->Height*1.1
        Cursor.Y += height;
        Cursor.X = Position.X;
    }
    
    int TextBox::WordPixelSize(string word)
    {
        int size = word.size();
        int pixelSize = 0;
        for(int x = 0; x < size; x++)
            pixelSize += CharMap->GetCharacter(word.substr(x,1))->Width;
        
        return pixelSize;
    }
}

