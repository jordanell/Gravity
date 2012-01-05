//
//  InputManager.h
//

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "GameFramework.h"
#include <list>

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
            list<GameComponent> Components;
    };
}

#endif
