/* 
 * File:   TextBox.cpp
 * Author: jordan
 * 
 * Created on July 30, 2012, 2:58 PM
 */

#include "TextBox.h"

using namespace framework;

namespace gravity
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
        
        this->PreProcessPosition();
    }
    
    void TextBox::UpdateText(string text)
    {
        this->Text = text;
        PreProcessPosition();
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
        int height = CharMap->GetCharacter("A")->Height;
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
    
    void TextBox::PreProcessPosition()
    {
        int maxX = 0;
        int maxY = 0;
        
        int tempX = 0;
        
        char cText[Text.size()];
        int size = Text.size();
        for(int x = 0; x <= size; x++)
            cText[x]=Text[x];
        
        char* pch = strtok(cText, " ");
        while(pch != NULL)
        {
            // Word
            string word = pch;
            if(Cursor.X + WordPixelSize(word) > Position.X + Position.Width)
            {
                if(tempX > maxX)
                {
                    maxX = tempX;
                    tempX = 0;
                }
                MoveCursorNextLine();
                maxY += CharMap->GetCharacter("A")->Height;
            }
            int size = word.size();
            for(int x = 0; x < size; x++)
                tempX += CharMap->GetCharacter(word.substr(x,1))->Width;
            Cursor.X += CharMap->SpaceSize;
            tempX += CharMap->SpaceSize;
            
            
            pch = strtok(NULL, " ");
        }
        if(maxX == 0)
            maxX = tempX;
        maxY += CharMap->GetCharacter("a")->Height;
        
        Cursor.X = Position.X;
        Cursor.Y = Position.Y;
        
        this->Bounding = Rectangle(Position.X, Position.Y, maxX - CharMap->SpaceSize, maxY);
    }
}

