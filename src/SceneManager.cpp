/*
 * This is the implementation file for the SceneManager class.
 * Author: Jordan Ell
 * Date: 01/10/11
 */

#include "SceneManager.h"
#include <iostream>

using namespace GameFramework;

namespace ManhattanProject
{
	SceneManager::SceneManager(Game* game):
		DrawableGameComponent(game)
	{
		this->game = game;
		this->Initialize();
	}

	void SceneManager::Initialize()
	{
        //Initialize the InputManager
        this->inputManager = new InputManager(game);
        
		//Always initialize to the launcher scene
        //testScene = new LauncherScene(game);
        //ActiveScene = testScene;
        
		testScene = new GameScene(game);
		ActiveScene = testScene;

		DrawableGameComponent::Initialize();
	}

	void SceneManager::Draw()
	{

		if(ActiveScene != NULL)
			ActiveScene->Draw();
		DrawableGameComponent::Draw();
	}

	void SceneManager::Update()
	{
        inputManager->Update();
		if(ActiveScene != NULL)
			ActiveScene->Update();
		DrawableGameComponent::Update();
	}
}
