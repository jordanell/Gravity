/*
 * This is the header for the Container class.
 * This class is used any object in the game that can contain items
 * Author: Jordan Ell
 * Date: 30/10/11
 */

#ifndef CONTAINER_H
#define CONTAINER_H

#include "GameFramework.h"
#include "Camera.h"
#include "Item.h"
#include "MapObject.h"
#include <list>
#include <string>

using namespace GameFramework;

namespace ManhattanProject
{
	class Container: public MapObject
	{
		public:
			Container(Game* game);
			Container(Game* game, Texture2D* Tile, Vector2 Position);
			Container(Game* game, Texture2D* Tile, Vector2 Position, list<Item> Items, string Name,
				      string Description);

			// Tile for the container
			Texture2D* Tile;

			string Name;
			string Description;

			Game* game;
			Vector2 Position;

			list<Item> Items;

			void Draw(Camera camera);

		private:

	};
}

#endif
