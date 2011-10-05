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
	Texture2D* tex;
	Texture2D* tex2;
	Manager::Manager():
		Game()
	{
	
	}
	
	void Manager::Initialize()
	{
		Game::Initialize();
		tex = Content->LoadTexture("Launcher/Wall.jpg");
		tex2 = Content->LoadTexture("Launcher/Button.jpg");
	}
	
	void Manager::Draw()
	{
		Render->Draw(tex, &Rectangle(0,0,400,600), &Color(255,255,255,255));
		Render->Draw(tex2, &Rectangle(200,300,50,200), &Rectangle(0,0,156,354), &Color(255,255,255,255));
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

