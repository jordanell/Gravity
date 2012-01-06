//
//  InputManager.cpp
//

#include <iostream>
#include "InputManager.h"

using namespace GameFramework;

namespace ManhattanProject 
{
    InputManager::InputManager(Game* game): 
        GameComponent(game)
    {
        this->game = game;
        this->Initialize();
    }
    
    void InputManager::Initialize()
    {
		ActiveInput = new GameSceneInput(this->game);
    }
    
    void InputManager::Update()
    {
		// This is the main event poll!
        while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				this->game->Exit();
				
			//Pass the event to the active input class here
			ActiveInput->Update(&event);
		}
    }

    //void AddListener(GameComponent* component,
}
