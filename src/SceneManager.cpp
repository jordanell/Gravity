/*
 * This is the implementation file for the SceneManager class.
 * Author: Jordan Ell
 * Date: 01/10/11
 */
 
#include "SceneManager.h"
 
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
		//Always initialize to the launcher scene
		launcher = new LauncherScene(game);
		ActiveScene = launcher;
	
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
	
		if(ActiveScene != NULL)
			ActiveScene->Update();
		DrawableGameComponent::Update();
	}
}
