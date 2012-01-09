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
	
	void InputManager::SetScene(Scene* scene)
	{
		this->ActiveScene = scene;
	}
    
    void InputManager::Update()
    {
		// This is the main event poll!
        while(SDL_PollEvent(&event))
		{
			switch (event.type)
            {
                case SDL_QUIT: {
			    	this->game->Exit();
                    break;
                }
            }
			
			
		}
    }
}
