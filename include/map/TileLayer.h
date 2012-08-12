/*
 * This is the header for the TileLayer class.
 * This class is used to hold a list of tiles and can draw those tiles
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#ifndef TILELAYER_H
#define TILELAYER_H

#include "framework.h"
#include "Tile.h"
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

		protected:
			Game* game;

			framework::Rectangle Size;
			list<Tile*> Tiles;
	};
}

#endif
