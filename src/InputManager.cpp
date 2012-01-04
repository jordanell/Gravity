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
        
    }
    
    void InputManager::Update()
    {
        while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				this->game->Exit();
		}
    }
}