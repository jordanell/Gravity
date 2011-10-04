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
	Texture2D tex;
	Manager::Manager():
		Game()
	{
	
	}
	
	void Manager::Initialize()
	{
		Game::Initialize();
		tex.Texture = Content->LoadTexture("Launcher/Wall.jpg");
	}
	
	void Manager::Draw()
	{
		Render->Draw(&tex, &Rectangle(0,0,400,600), &Color(255,255,255,255));
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

