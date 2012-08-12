/*
 * This is the header for the Entity class.
 * This class will be the base class for all live entities in the game
 * Author: Jordan Ell
 * Date: 09/01/12
 */

#ifndef ENTITY_H
#define ENTITY_H

#include "framework.h"

using namespace framework;

namespace gravity
{
	class Entity: public DrawableGameComponent
	{
		public:
			Entity(Game* game);
			
			virtual void Initialize();
			virtual void Update();
			virtual void Draw();
				
		private:
		
	};
}

#endif

