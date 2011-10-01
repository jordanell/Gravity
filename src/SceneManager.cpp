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
	}
	
	void SceneManager::Initialize()
	{
	
		DrawableGameComponent::Initialize();
	}
	
	void SceneManager::Draw()
	{
	
		DrawableGameComponent::Draw();
	}
	
	void SceneManager::Update()
	{
	
		DrawableGameComponent::Update();
	}
}
