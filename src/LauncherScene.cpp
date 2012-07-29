/*
 * This is the implementation file for the LauncherScene class.
 * Author: Jordan Ell
 * Date: 09/10/11
 */

#include "LauncherScene.h"
#include <iostream>

using namespace framework;

namespace ManhattanProject
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
        LauncherScene *lscene = dynamic_cast<LauncherScene*>(scene);
        if (lscene->sm != NULL)
            lscene->sm->toGameScene();
    }

	LauncherScene::LauncherScene(Game* game):
		Scene(game)
	{
		this->game = game;

		this->Initialize();
	}

    LauncherScene::LauncherScene(Game* game, SceneManager* sm):
        Scene(game)
	{
		this->game = game;
        this->sm = sm;
        
		this->Initialize();
	}

   	void LauncherScene::Initialize()
	{
	    // Create background image
		background = game->Content->LoadTexture("Launcher/Wall.jpg");

		// Create start and quit buttons
        startBtn = new Button(game, game->Content->LoadTexture("Launcher/startbutton.png"), framework::Rectangle(450, 345, 100, 50), this);
        quitBtn = new Button(game, game->Content->LoadTexture("Launcher/quitbutton.png"), framework::Rectangle(340, 345, 100, 50), this);

        // Create sound and full screen check boxes
        fullScreen = new CheckBox(game, game->Content->LoadTexture("Launcher/startbutton.png"), framework::Rectangle(50, 260, 30, 30), this);
        fullScreenLabel = new Label(game, "Full screen", 100, Color(255, 255, 255, 255), framework::Rectangle(85, 260, 100, 30), this);
		sound = new CheckBox(game, game->Content->LoadTexture("Launcher/startbutton.png"), framework::Rectangle(50, 300, 30, 30), this);
		//soundLabel = new Label(game, "Enable Sound", 100, Color(255, 255, 255, 255), framework::Rectangle(85, 300, 100, 30), this);
		

        quitBtn->LButtonDownCallback = &quitButtonDown;
        startBtn->LButtonDownCallback = &startButtonDown;
        Scene::Initialize();
	}

	void LauncherScene::Draw()
	{
		//Draw the background texture
		game->Render->Draw(background, framework::Rectangle(0,0,600,400), Color(255,255,255,150));
        startBtn->Draw();
        quitBtn->Draw();
        fullScreen->Draw();
        fullScreenLabel->Draw();
        sound->Draw();
        //soundLabel->Draw();
        
		Scene::Draw();
	}

	void LauncherScene::Update()
	{
		Scene::Update();
	}
}



