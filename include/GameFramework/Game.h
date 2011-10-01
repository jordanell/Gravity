/*
 * This is the header for the Game class.
 * Author: Jordan Ell
 * Date: 21/09/11
 */

#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <list>

#ifdef __linux__
	#include "SDL/SDL.h"
#else
	#include "SDL.h"
#endif

#include "GameComponent.h"
#include "GameComponentCollection.h"
#include "DrawableGameComponent.h"
#include "RenderEngine.h"
#include "ContentManager.h"
#include "Timer.h"
#include "Defines.h"

using namespace std;

namespace GameFramework
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
			virtual void Initialize();

			void BeginDraw();
			virtual void Draw();
			void EndDraw();

			virtual void Update();
	};
}

#endif
