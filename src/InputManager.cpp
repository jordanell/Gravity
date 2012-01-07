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
			switch (event.type)
            {
                case SDL_QUIT: {
			    	this->game->Exit();
                    break;
                }
			    case SDL_KEYDOWN: {
                  cout << "onkeydown";
                  //OnKeyDown(Event->key.keysym.sym,Event->key.keysym.mod,Event->key.keysym.unicode);
                  break;
                }
            }
			//Pass the event to the active input class here
			ActiveInput->Update(&event);
		}
    }
}
