/*
 * This is the header for the Game class.
 * Author: Jordan Ell
 * Date: 21/09/11
 */

#ifndef GAME_H
#define GAME_H

#include <stdlib.h>

namespace Game_Framework
{
	class Game
	{
		public:
			Game();

			void Run();
			
			void Exit();
		
		protected:
			void BeginDraw();
			void Draw();
			void EndDraw();

			void Update();
	};
}

#endif
