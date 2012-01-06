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
#include "CollisionLayer.h"
#include "Camera.h"
#include <list>
#include <string>

using namespace GameFramework;

namespace ManhattanProject
{
	class TileMap: public DrawableGameComponent
	{
		public:
			Camera camera;
			SDL_Event event;

			TileMap(Game* game);
			TileMap(Game* game, Camera camera, GameFramework::Rectangle Size);
			
			~TileMap();

			void Initialize();
			void Update();
			void Draw();

			void AddTileLayer();
			void AddTileLayer(TileLayer* layer);
			
			TileLayer* LastAddedLayer();
			CollisionLayer* GetCollisionLayer();
			
			void SetSize(GameFramework::Rectangle Size);

			void PrintLayers();
			void Debugging();

		protected:
			list<TileLayer*> layers;
			CollisionLayer* collisionLayer;
			GameFramework::Rectangle Size;
			
			bool left;
			bool right;
			bool up;
			bool down;

			bool debugging;
	};
}

#endif
