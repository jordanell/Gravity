/*
 * This is the implementation file for the LauncherScene class.
 * Author: Jordan Ell
 * Date: 09/10/11
 */

#include "LauncherScene.h"
#include <iostream>

using namespace GameFramework;

namespace ManhattanProject
{
    void quitButtonDown(Game* game, Scene* scene)
    {
        game->Exit();
    }
    
    void startButtonDown(Game* game, Scene* scene)
    {
        LauncherScene *lscene = dynamic_cast<LauncherScene*>(scene);
        
        cout << "TODO @braden go to start scene";
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
		background = game->Content->LoadTexture("Launcher/Wall.jpg");
        startBtn = new Button(game, game->Content->LoadTexture("Launcher/startbutton.png"), float(1.0), float(0.0), Vector2(150,300), *(Color::White()), GameFramework::Rectangle(150, 300, 50, 100), this);
        quitBtn = new Button(game, game->Content->LoadTexture("Launcher/quitbutton.png"), float(1.0), float(0.0), Vector2(250,300), *(Color::White()), GameFramework::Rectangle(250, 300, 50, 100), this);
        
        quitBtn->LButtonDownCallback = &quitButtonDown;
        startBtn->LButtonDownCallback = &startButtonDown;
        Scene::Initialize();
	}

	void LauncherScene::Draw()
	{
		//Draw the background texture
		game->Render->Draw(background, GameFramework::Rectangle(0,0,400,600), Color(255,255,255,150));
        startBtn->Draw();
        quitBtn->Draw();
		Scene::Draw();
	}

	void LauncherScene::Update()
	{
		Scene::Update();
	}
}



