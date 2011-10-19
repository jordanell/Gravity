/*
 * This is the header for the TileLayer class.
 * This class is used to hold a list of tiles and can draw those tiles
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#ifndef TILELAYER_H
#define TILELAYER_H

#include "GameFramework.h"
#include "Tile.h"
#include "QuadTree.h"
#include "Camera.h"
#include <list>

using namespace GameFramework;

namespace ManhattanProject
{
	class TileLayer
	{
		public:
			TileLayer(Game* game, Camera camera, Rectangle rec);
		
			void Update();	
			void Draw();
		
			void AddTile(Texture2D* tex, float alpha, float scale, float rotation, Vector2 position, Color color);
		
		protected:
			Game* game;
			
			Rectangle Size;
			QuadTree<Tile> TileTree;
			list<Tile*> DrawingTiles;
			Camera camera;
			
			
	};
}

#endif
