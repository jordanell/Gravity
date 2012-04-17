/*
 * This is the header for the Tile class.
 * This class will be used a the base class for all maps in the game. The tile is not a tile
 * In the conventional sense. It is not restricted in size or position.
 * Author: Jordan Ell
 * Date: 11/10/11
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
	class Tile: public MapObject
	{
	public:
		Tile(Game* game);
		Tile(Game* game, Texture2D* tex, Vector2 s, float rot, Vector2 pos, Color col);

		void Update();
		void Draw(Camera camera);

        Texture2D* Texture;
		Color TintColor;
		bool FlipHorizontally;
		bool FlipVertically;
		list<string> ItemNames;


	protected:
		Game* game;
	};
}

#endif
