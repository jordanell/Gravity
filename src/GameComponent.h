/*
 * This is the header for the GameComponent class.
 * Author: Jordan Ell
 * Date: 21/09/11
 */

#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H

#include "Game.h"

namespace Game_Framework
{
	class GameComponent
	{
		public:
			bool Enabled;
			Game* game;

			GameComponent(Game* game);

			virtual void Init();
			virtual void Update();		
	};
}

#endif
