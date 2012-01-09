//
//  InputManager.h
//

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "GameFramework.h"
#include "Scene.h"
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
			
			void SetScene(Scene* scene);
        protected:
            SDL_Event event;
			Scene* ActiveScene;
    };
}

#endif
