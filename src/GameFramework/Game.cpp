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
		Timer FPS;

		for(;;)
		{
			FPS.Start();

			Update();
		
			BeginDraw();
			Draw();
			EndDraw();

			if(FPS.GetTicks() < MILLISECONDS / FRAMES_PER_SECOND)
				SDL_Delay((MILLISECONDS / FRAMES_PER_SECOND) - FPS.GetTicks());
		}
	}

	void Game::Exit()
	{
		exit(0);
	}

	void Game::BeginDraw()
	{
		Render->PreDraw();
	}

	void Game::Draw()
	{
		list<GameComponent>::iterator it;
		GameComponent* component;
		DrawableGameComponent* drawable;

		for(it = Components.begin(); it != Components.end(); it++)
		{
			component = &(*it);
			drawable = dynamic_cast<DrawableGameComponent*>(component);
			if(drawable)
				drawable->Draw();
		}
	}

	void Game::EndDraw()
	{
		Render->PostDraw();
	}

	void Game::Update()
	{
		list<GameComponent>::iterator it;

		for(it = Components.begin(); it != Components.end(); it++)
			it->Update();
	}
}

