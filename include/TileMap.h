/*
 * This is the header for the TileMap class.
 * This class is used to hold a list of TileLayers and can draw those layers to make up the map.
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#ifndef TILEMAP_H
#define TILEMAP_H

#include "GameFramework.h"
#include "TileLayer.h"
#include <list>

using namespace GameFramework;

namespace ManhattanProject
{
	class TileMap: public DrawableGameComponent
	{
		public:
			TileMap(Game* game);
		
			void Initialize();
			void Update();	
			void Draw();
		
			void AddLayer();
		
		protected:
			list<TileLayer> layers;
	};
}

#endif
