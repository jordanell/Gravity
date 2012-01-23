/*
 * This is the header for the Entity class.
 * This class will be the base class for all live entities in the game
 * Author: Jordan Ell
 * Date: 09/01/12
 */

#ifndef ENTITY_H
#define ENTITY_H

#include "GameFramework.h"
#include "CollisionRectangle.h"

using namespace GameFramework;

namespace ManhattanProject
{
	class Entity: public DrawableGameComponent
	{
		public:
			Entity(Game* game);
			
			virtual void Initialize();
			virtual void Update();
			virtual void Draw();
			
			virtual GameFramework::Rectangle GetCollisionRectangle();
				
		private:
		
	};
}

#endif

