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
		background = game->Content->LoadTexture("Launcher/Wall.jpg");
		Scene::Initialize();
	}
	
	void LauncherScene::Draw()
	{
		//Draw the background texture
		game->Render->Draw(background, Rectangle(0,0,400,600), Color(255,255,255,255));
		
		Scene::Draw();
	}
	
	void LauncherScene::Update()
	{
		
		Scene::Update();
	}
}


