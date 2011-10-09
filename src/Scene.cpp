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
		Node* iterator;
		GameComponent* component;
		DrawableGameComponent* drawable;
		
		for(iterator = Components->Head; iterator != NULL; iterator = iterator->Next)
		{
			component = iterator->Component;
			drawable = dynamic_cast<DrawableGameComponent*>(component);
			if(drawable)
				drawable->Draw();
		}
	
		DrawableGameComponent::Draw();
	}
	
	void Scene::Update()
	{
		Node* iterator;
		
		for(iterator = Components->Head; iterator != NULL; iterator = iterator->Next)
			iterator->Component->Update();
	
		DrawableGameComponent::Update();
	}
}
 


