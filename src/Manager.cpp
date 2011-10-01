/*
 * This is the implementation file for the Manager class.
 * Author: Jordan Ell
 * Date: 01/10/11
 */
 
#include "Manager.h"
 
using namespace GameFramework;
 
namespace ManhattanProject
{
	Rectangle* rec = new Rectangle(0,0,100,100);
	Color* col = new Color(255, 0, 0, 255);
	
	Manager::Manager():
		Game()
	{
	
	}
	
	void Manager::Initialize()
	{
		Game::Initialize();
		
	}
	
	void Manager::Draw()
	{
		Render->Draw(NULL, rec, col);
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

