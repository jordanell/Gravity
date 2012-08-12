/*
 * This is the header for the LauncherScene class.
 * This class will be used to encapsulate the game launcher presented on startup
 * Author: Jordan Ell
 * Date: 09/10/11
 */

#ifndef LAUNCHERSCENE_H
#define LAUNCHERSCENE_H

#include "framework.h"
#include "Scene.h"
#include "Button.h"
#include "CheckBox.h"
#include "CharacterMap.h"
#include "TextBox.h"
#include "Label.h"
#include "SceneManager.h"

#ifdef __linux__
#include "SDL/SDL_ttf.h"
#else
#include "SDL_ttf.h"
#endif

using namespace framework;

namespace gravity
{
    class SceneManager;
    class Button;
    class LauncherScene : public Scene
    {
      public:
        LauncherScene(Game* game);
        LauncherScene(Game* game, SceneManager* sm);

        void Initialize();

        void Update();
        void Draw();

        CheckBox* fullScreen;
        CheckBox* sound;

        SceneManager* sm;

      protected:
        Texture2D* background;
        Button* startBtn;
        Button* quitBtn;
        
        CharacterMap* charMap;
        TextBox* fsText;
        TextBox* esText;
    };
}

#endif
