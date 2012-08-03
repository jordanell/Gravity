/*
 * This is the implementation file for the SceneManager class.
 * Author: Jordan Ell
 * Date: 01/10/11
 */

#include "SceneManager.h"
#include <iostream>


using namespace framework;

namespace gravity
{
	SceneManager::SceneManager(Game* game):
		DrawableGameComponent(game)
	{
		this->game = game;
		this->Initialize();
	}

	void SceneManager::Initialize()
	{
		//Always initialize to the launcher scene
        testScene = new LauncherScene(game, this);
        ActiveScene = testScene;

//		testScene = new GameScene(game);
//		ActiveScene = testScene;

		DrawableGameComponent::Initialize();
	}

    void SceneManager::toGameScene()
    {
        testScene = new GameScene(game, this);
        this->ActiveScene = testScene;
    }

	void SceneManager::Draw()
	{
		if(ActiveScene != NULL)
			ActiveScene->Draw();
		DrawableGameComponent::Draw();
	}

	void SceneManager::Update()
	{
		if(ActiveScene != NULL)
			ActiveScene->Update();
		DrawableGameComponent::Update();
	}
}
