//
//  InputManager.h
//

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "GameFramework.h"
#include "InputModule.h"
#include "GameSceneInput.h"
#include <list>

class SceneManager;

using namespace GameFramework;

namespace ManhattanProject
{
    class InputManager: public GameComponent
    {
        public:
            InputManager(Game* game);
            void Initialize();
            void Update(); 
        protected:
            SDL_Event event;
			InputModule* ActiveInput;
            list<GameComponent> Components;
    };
}

#endif
