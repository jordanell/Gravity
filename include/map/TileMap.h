/*
 * This is the header for the TileMap class.
 * This class is used to hold a list of TileLayers and can draw those layers to make up the map.
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#ifndef TILEMAP_H
#define TILEMAP_H

#include "framework.h"
#include "TileLayer.h"
#include "InputEvent.h"
#include "Camera.h"
#include "Scene.h"
#include <list>
#include <string>

using namespace framework;

namespace gravity
{
	class TileMap: public DrawableGameComponent, InputEvent
	{
		public:
			Camera camera;
			SDL_Event event;

			TileMap(Game* game);
			TileMap(Game* game, Scene* scene, Camera camera, framework::Rectangle Size);

			~TileMap();

			void Initialize();
			void Update();
			void Draw();

			void AddTileLayer();
			void AddTileLayer(TileLayer* layer);

			TileLayer* LastAddedLayer();

			void SetSize(framework::Rectangle Size);

		protected:
			list<TileLayer*> layers;
			framework::Rectangle Size;
	};
}

#endif
