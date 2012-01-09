/*
 * This is the implementation file for the Scene class.
 * Author: Jordan Ell
 * Date: 01/10/11
 */
 
#include "Scene.h"

using namespace GameFramework;

namespace ManhattanProject
{
	Scene::Scene(Game* game):
		DrawableGameComponent(game)
	{
		this->game = game;
	}
	
	void Scene::Initialize()
	{
		Components = new GameComponentCollection();
	}
	
	void Scene::Draw()
	{
		Components->Draw();
	
		DrawableGameComponent::Draw();
	}
	
	void Scene::Update()
	{
		Components->Update();
	
		DrawableGameComponent::Update();
	}
}
 


