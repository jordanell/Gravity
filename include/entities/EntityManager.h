/*
 * This is the header for the EntityManager class.
 * This class will be used to manage all the entities that appear in the game.
 * Author: Jordan Ell
 * Date: 21/01/12
 */

#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <list>
#include "TileMap.h"
#include "Entity.h"
#include "Hero.h"

using namespace framework;

namespace gravity
{
	class EntityManager: public DrawableGameComponent
	{
		public:
			EntityManager(Game* game);
			EntityManager(Game* game, TileMap* Map);
			
			void Initialize();
			
			list<Entity*> GetActiveEntities();
			
			void Update();
			void Draw();
                        
                        Hero* hero;
		
		protected:
			list<Entity*> Entities;
			TileMap* Map;
	};
}

#endif
