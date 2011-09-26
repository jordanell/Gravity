/*
 * This is the header for the Game class.
 * Author: Jordan Ell
 * Date: 21/09/11
 */

#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <list>

#include "SDL/SDL.h"

#include "GameComponent.h"
#include "GameComponentCollection.h"
#include "DrawableGameComponent.h"
#include "RenderEngine.h"
#include "ContentManager.h"
#include "Timer.h"
#include "Defines.h"

using namespace std;

namespace Game_Framework
{
	class Game
	{
		public:
			GameComponentCollection* Components;
			RenderEngine* Render;
			ContentManager* Content;

			Game();

			void Run();
			
			void Exit();
		
		protected:
			void Initialize();

			void BeginDraw();
			void Draw();
			void EndDraw();

			void Update();
	};
}

#endif
