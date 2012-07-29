/*
 * This is the header for the GameComponentCollection class.
 * Author: Jordan Ell
 * Date: 25/09/11
 */

#ifndef GAMECOMPONENTCOLLECTION_H
#define GAMECOMPONENTCOLLECTION_H

#include "GameComponent.h"
#include "DrawableGameComponent.h"
#include "Exception.h"
#include <cstddef>
#include <list>

namespace framework
{
	class GameComponentCollection
	{
		public:

			GameComponentCollection();

			void Add(GameComponent* Component);
			void Remove(GameComponent* Component);
			void Update();
			void Draw();
			
		private:
			list<GameComponent*> items;
			int Count;
	};
}

#endif
