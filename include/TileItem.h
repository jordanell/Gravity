/*
 * This is the header for the TileItem class.
 * This class is just like a tile but displays an item
 * Author: Jordan Ell
 * Date: 16/4/2012
 */

#ifndef TILE_H
#define TILE_H

#include "GameFramework.h"
#include "Camera.h"
#include "MapObject.h"
#include <string>
#include <list>

using namespace GameFramework;

namespace ManhattanProject
{
	class TileItem: public MapObject
	{
	public:
		TileItem(Game* game);
		TileItem(Game* game, Vector2 s, float rot, Vector2 pos, Color col);

		void Update();
		void Draw(Camera camera);
		Color TintColor;
		bool FlipHorizontally;
		bool FlipVertically;
		string ItemName;


	protected:
		Game* game;
	};
}

#endif
