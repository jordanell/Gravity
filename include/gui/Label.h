/* 
 * File:   Label.h
 * Author: jordan
 *
 * Created on July 30, 2012, 7:10 PM
 */

#ifndef LABEL_H
#define	LABEL_H

#include "framework.h"
#include "GuiObject.h"
#include "CharacterMap.h"
#include "TextBox.h"

#include <string>

namespace gravity
{

    class Label: public GuiObject
    {
      public:
        Label(Game* game);
        Label(Game* game, Texture2D* background, framework::Rectangle position, Color backgroundColor,
            Color fontColor, string text, CharacterMap* charMap);
        
        void SetText(string text);
        
        void Draw();
        void Update();
        
      private:
        Texture2D* Background;
        framework::Rectangle Position;
        TextBox* Text;

    };
}

#endif	/* LABEL_H */

