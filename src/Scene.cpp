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
	
	void Scene::AddListener(InputEvent* Component, list<Uint8> EventTypes)
	{
		Listener* listener = new Listener(game, Component, EventTypes);
		Listeners.push_back(listener);
	}
	
	void Scene::PollListeners(SDL_Event* event)
	{
		list<Listener*>::iterator it;
		
		for(it=Listeners.begin(); it!=Listeners.end(); it++)
		{
			Listener* listen = *it;
			if(listen->IsListeningOnEvent(event->type))
			{
				listen->Component->OnEvent(event);
			}
		}
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
 


