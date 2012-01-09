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
	LauncherScene::LauncherScene(Game* game):
		Scene(game)
	{
		this->game = game;

		this->Initialize();
	}

	void LauncherScene::Initialize()
	{
		background = game->Content->LoadTexture("/../content/Launcher/Wall.jpg");
        startBtn = new Button(game, game->Content->LoadTexture("/../content/Launcher/button.jpg"), float(1.0), float(0.0), Vector2(0,0), *(Color::White()), GameFramework::Rectangle(0, 0, 100, 300));
		Scene::Initialize();
	}

	void LauncherScene::Draw()
	{
		//Draw the background texture
		game->Render->Draw(background, GameFramework::Rectangle(0,0,400,600), Color(255,255,255,255));
        startBtn->Draw();
		Scene::Draw();
	}

	void LauncherScene::Update()
	{
		Scene::Update();
	}
}



