/*
 * This is the header for the TileLayer class.
 * This class is used to hold a list of tiles and can draw those tiles
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#ifndef TILELAYER_H
#define TILELAYER_H

#include "framework.h"
#include "MapObject.h"
#include "QuadTree.h"
#include "Tile.h"
#include "Container.h"
#include "Item.h"
#include "CollisionRectangle.h"
#include "Camera.h"
#include <list>

using namespace framework;

namespace gravity
{
	class TileLayer
	{
		public:
			TileLayer(Game* game, framework::Rectangle rec);

			~TileLayer();

			void Update();
			void Draw(Camera camera);

			void AddTile(Tile* tile);
			void AddTile(Texture2D* tex, Vector2 scale, float rotation, Vector2 position, Color color);
			void AddContainer(Game* game, Texture2D* Tile, Vector2 Position, list<Item> Items, string Name, string Description);
			void AddItem(Game* game, Texture2D* Icon, Texture2D* Tile, Vector2 Position, float hp, float ep, float sp,
						 float ap, float dp, string Name, string Description);
			void Print();

			void Debugging();

		protected:
			Game* game;

			framework::Rectangle Size;
			QuadTree<MapObject*>* TileTree;
			list<MapObject*> DrawingTiles;
			bool debugging;
	};
}

#endif
