/* 
 * File:   CharacterMap.cpp
 * Author: jordan
 * 
 * Created on July 30, 2012, 1:17 PM
 */

#include "CharacterMap.h"

using namespace framework;

namespace gravity
{

    CharacterMap::CharacterMap(Game* game) :
    GuiObject(game)
    {

    }

    CharacterMap::CharacterMap(Game* game, string font, int fontsize) :
    GuiObject(game)
    {
        this->FontName = font;
        this->FontSize = fontsize;
        this->SpaceSize = -1;

        LoadFont(font);
    }

    void CharacterMap::LoadFont(string font)
    {
        this->Font = game->Content->LoadFont(font, this->FontSize);
        RenderFont();
    }

    void CharacterMap::RenderFont()
    {
        ifstream infile("../include/gui/CharacterRange.txt");
        string line;
        while (getline(infile, line))
        {
            this->CharMap[line] = game->Render->RenderCharactersToTexture(Font, FontSize, Color(255, 255, 255, 255), line);
            if (!line.compare("i"))
                SpaceSize = CharMap[line]->Width;
        }
    }

    Texture2D* CharacterMap::GetCharacter(string character)
    {
        return CharMap[character];
    }
}

