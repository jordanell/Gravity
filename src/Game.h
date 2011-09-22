/*
 * This is the header for the Game class.
 * Author: Jordan Ell
 * Date: 21/09/11
 */

#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <list>
#include "GameComponent.h"
#include "RenderEngine.h"

using namespace std;

namespace Game_Framework
{
	class Game
	{
		public:
			list<GameComponent> Components;
			RenderEngine* Render;

			Game();

			void Run();
			
			void Exit();
		
		protected:
			list<GameComponent> iterator;

			void BeginDraw();
			void Draw();
			void EndDraw();

			void Update();
	};
}

#endif
