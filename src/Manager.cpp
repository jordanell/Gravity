/*
 * This is the implementation file for the Manager class.
 * Author: Jordan Ell
 * Date: 01/10/11
 */
 
#include "Manager.h"
#include <iostream>
 
using namespace GameFramework;
 
namespace ManhattanProject
{
	Manager::Manager():
		Game()
	{
	
	}
	
	void Manager::Initialize()
	{
		Game::Initialize();
		
		sceneManager = new SceneManager(this);
		this->Components->Add(sceneManager);
	}
	
	void Manager::Draw()
	{
	
		Game::Draw();
	}
	
	void Manager::Update()
	{
		//Check if the X has been pressed and if so then exit the game.
		//This code may need to be moved to an I/O class.
		SDL_PollEvent(&event);
		if(event.type == SDL_QUIT)
			this->Exit();
		
		Game::Update();
	}
}

