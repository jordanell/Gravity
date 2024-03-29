/* 
 * File:   TextBox.h
 * Author: jordan
 *
 * Created on July 30, 2012, 2:58 PM
 */

#ifndef TEXTBOX_H
#define	TEXTBOX_H

#include "framework.h"
#include "CharacterMap.h"

#include <string>
#include <stdio.h>

using namespace framework;

namespace gravity
{

    class TextBox : public GuiObject
    {
      public:
        TextBox(Game* game);
        TextBox(Game* game, framework::Rectangle position, string text, Color color, CharacterMap* charmap);

        void Draw();
        void UpdateText(string text);

        framework::Rectangle Bounding;

      private:
        void DrawWord(string word);
        void DrawCharacter(string character);

        void MoveCursorNextLine();

        int WordPixelSize(string word);

        void PreProcessPosition();


        string Text;
        CharacterMap* CharMap;
        Vector2 Cursor;

        Scene* scene;

        framework::Rectangle Position;
        Color color;


    };
}

#endif	/* TEXTBOX_H */

