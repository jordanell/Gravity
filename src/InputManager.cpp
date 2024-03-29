//
//  InputManager.cpp
//

#include <iostream>
#include "InputManager.h"

using namespace framework;

namespace gravity
{

    InputManager::InputManager(Game* game) :
    GameComponent(game)
    {
        this->game = game;
        this->Initialize();
    }

    void InputManager::Initialize()
    {

    }

    void InputManager::SetScene(SceneManager* sceneManager)
    {
        this->sceneManager = sceneManager;
    }

    void InputManager::Update()
    {
        // This is the main event poll!
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                {
                    this->game->Exit();
                    break;
                }
            }

            sceneManager->ActiveScene->PollListeners(&event);
        }
    }
}
