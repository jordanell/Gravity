/*
 * This is the header for the TileMap class.
 * This class is used to hold a list of TileLayers and can draw those layers to make up the map.
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#ifndef TILEMAP_H
#define TILEMAP_H

#include "GameFramework.h"
#include "GameDefines.h"
#include "TileLayer.h"
#include "CollisionLayer.h"
#include "Camera.h"
#include <list>

using namespace GameFramework;

namespace ManhattanProject
{
	class TileMap: public DrawableGameComponent
	{
		public:
			Camera camera;
			
			TileMap(Game* game);
			TileMap(Game* game, Camera camera, Rectangle Size);
		
			void Initialize();
			void Update();	
			void Draw();
		
			void AddTileLayer();
			void AddTileLayer(TileLayer layer);
			
			void AddCollisionLayer();
			void AddCollisionLayer(CollisionLayer layer);
			
			void PrintLayers();
			
			void Debugging();
		
		protected:
			list<TileLayer> layers;
			list<CollisionLayer> collision;
			Rectangle Size;
			
			bool debugging;
	};
}

#endif
