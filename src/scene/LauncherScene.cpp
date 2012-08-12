/*
 * This is the implementation file for the LauncherScene class.
 * Author: Jordan Ell
 * Date: 09/10/11
 */

#include "LauncherScene.h"
#include "CharacterMap.h"
#include <iostream>

using namespace framework;

namespace gravity
{

    /*
     * This is the function for the quit button
     */
    void quitButtonDown(Game* game, Scene* scene)
    {
        game->Exit();
    }

    /*
     * This is the function for the start button
     */
    void startButtonDown(Game* game, Scene* scene)
    {
        LauncherScene *lscene = dynamic_cast<LauncherScene*> (scene);
        if (lscene->sm != NULL)
            lscene->sm->toGameScene();
    }

    LauncherScene::LauncherScene(Game* game) :
    Scene(game)
    {
        this->game = game;

        this->Initialize();
    }

    LauncherScene::LauncherScene(Game* game, SceneManager* sm) :
    Scene(game)
    {
        this->game = game;
        this->sm = sm;

        this->Initialize();
    }

    void LauncherScene::Initialize()
    {
        // Create background image
        background = game->Content->LoadTexture("scene/launcher/Background.png");

        // Create start and quit buttons
        startBtn = new Button(game, game->Content->LoadTexture("scene/launcher/startbutton.png"), framework::Rectangle(350, 325, 100, 50), this);
        quitBtn = new Button(game, game->Content->LoadTexture("scene/launcher/quitbutton.png"), framework::Rectangle(460, 325, 100, 50), this);

        // Create sound and full screen check boxes
        fullScreen = new CheckBox(game, game->Content->LoadTexture("scene/launcher/CheckBox.png"), framework::Rectangle(40, 260, 16, 16), this);
        sound = new CheckBox(game, game->Content->LoadTexture("scene/launcher/CheckBox.png"), framework::Rectangle(40, 280, 16, 16), this);
        
        charMap = new CharacterMap(game, "fonts/illuminate.ttf", 16);
        fsText = new TextBox(game, framework::Rectangle(65, 258, 200, 17), "full screen", Color(200,37,54,255), charMap);
        esText = new TextBox(game, framework::Rectangle(65, 278, 200, 17), "enable sound", Color(5,118,255,255), charMap);   

        quitBtn->LButtonDownCallback = &quitButtonDown;
        startBtn->LButtonDownCallback = &startButtonDown;
        Scene::Initialize();
    }

    void LauncherScene::Draw()
    {
        //Draw the background texture
        game->Render->Draw(background, framework::Rectangle(0, 0, 600, 400), Color(255, 255, 255, 255));
        startBtn->Draw();
        quitBtn->Draw();
        fullScreen->Draw();
        sound->Draw();
        
        fsText->Draw();
        esText->Draw();

        Scene::Draw();
    }

    void LauncherScene::Update()
    {
        Scene::Update();
    }
}



