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
	}

	void Game::EndDraw()
	{
		Render->PostDraw();
	}

	void Game::Update()
	{
		Node* iterator;

		for(iterator = Components->Head; iterator != NULL; iterator = iterator->Next)
			iterator->Component->Update();
	}
}

