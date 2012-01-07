/*
 * This is the header for the GameComponent class.
 * Author: Jordan Ell
 * Date: 21/09/11
 */

#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H

#include "Event.h"

namespace GameFramework
{
	//Forward dependancy
	class Game;

	class GameComponent : public Event
	{
		public:
			bool Enabled;
			Game* game;

			GameComponent(Game* game);

			virtual void Initialize();
			virtual void Update();		
	};
}

#endif
