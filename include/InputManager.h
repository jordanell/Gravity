//
//  InputManager.h
//

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "GameFramework.h"
#include "SceneManager.h"
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
			
			void SetScene(SceneManager* sceneManager);
        protected:
            SDL_Event event;
			SceneManager* sceneManager;
    };
}

#endif
