/*
 * This class represents a base Game.
 * Author: Jordan Ell
 * Date: 21/09/11
 */

#include "Game.h"

namespace framework
{

    Game::Game()
    {
    }

    void Game::Initialize()
    {
        //Create RenderEngine
        Render = new RenderEngine("Game", DEFAULT_WIDTH, DEFAULT_HEIGHT, false);
        //Create ContentManager
        Content = new ContentManager();
        //Create Component Collection
        Components = new GameComponentCollection();
    }

    void Game::Run()
    {
        //Before game runs call the initializer
        Initialize();

        Timer FPS;

        for (;;)
        {
            FPS.Start();

            Update();

            BeginDraw();
            Draw();
            EndDraw();

            if (FPS.GetTicks() < (MILLISECONDS / FRAMES_PER_SECOND))
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
        Components->Draw();
    }

    void Game::EndDraw()
    {
        Render->PostDraw();
    }

    void Game::Update()
    {
        Components->Update();
    }
}

