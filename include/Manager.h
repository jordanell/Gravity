/*
 * This is the header for the Manager class.
 * This is the base class for the entire game. It is the class that gets initialized from main and contains
 * the main game loop of updating and drawing.
 * Author: Jordan Ell
 * Date: 01/10/11
 */

#ifndef MANAGER_H
#define MANAGER_H

#include "framework.h"
#include "SceneManager.h"
#include "InputManager.h"

using namespace framework;

namespace ManhattanProject
{
	class Manager: public Game
	{
		public:
			SDL_Event event;
			SceneManager* sceneManager;
			InputManager* inputManager;
			Manager();

		protected:
			void Initialize();
			void Draw();
			void Update();
	};
}

#endif
