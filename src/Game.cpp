/*
 * This class represents a base Game.
 * Author: Jordan Ell
 * Date: 21/09/11
 */

#include "Game.h"

namespace Game_Framework
{
	Game::Game()
	{
		//Add properties here
	}

	void Game::Run()
	{
		for(;;)
		{
			//Add in frame rate stuff here
			Update();
			Draw();
		}
	}

	void Game::Exit()
	{
		exit(0);
	}

	void Game::BeginDraw()
	{

	}

	void Game::Draw()
	{

	}

	void Game::EndDraw()
	{


	}

	void Game::Update()
	{


	}
}

