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
#include "CollisionLayer.h"
#include "InputEvent.h"
#include "Camera.h"
#include "Scene.h"
#include <list>
#include <string>

using namespace framework;

namespace ManhattanProject
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
			CollisionLayer* GetCollisionLayer();

			void SetSize(framework::Rectangle Size);

			void PrintLayers();
			void Debugging();

			// Input stuff
			void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

		protected:
			list<TileLayer*> layers;
			CollisionLayer* collisionLayer;
			framework::Rectangle Size;

			bool debugging;
	};
}

#endif
