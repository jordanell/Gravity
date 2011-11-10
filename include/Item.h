/*
 * This is the header for the Item class.
 * This class is used to represent items in the game.
 * Author: Jordan Ell
 * Date: 30/10/11
 */

#ifndef ITEM_H
#define ITEM_H

#include "GameFramework.h"
#include "Camera.h"
#include "MapObject.h"
#include <string>

using namespace GameFramework;

namespace ManhattanProject
{
	class Item: public MapObject
	{
		public:
			Item(Game* game);
			Item(Game* game, Texture2D* Icon, Texture2D* Tile, float hp, float ep, float sp, float ap, float dp);
			Item(Game* game, Texture2D* Icon, Texture2D* Tile, Vector2 Position,
				 float hp, float ep, float sp, float ap, float dp, string Name, string Description);

			// Health points and energy points
			float hp;
			float ep;

			// Strength points, agility points and dexterity
			float sp;
			float ap;
			float dp;

			// Icon is for UI, tile is for drawing on map.
			Texture2D* Icon;
			Texture2D* Tile;

			string Name;
			string Description;

			Game* game;

			Vector2 Position;

			void Draw(Camera camera);

		private:

	};
}

#endif

