/*
 * This is the header for the Player class.
 * This class will be used for the main character class.
 * Author: Jordan Ell
 * Date: 09/01/12
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "GameFramework.h"
#include "Entity.h"
#include "Camera.h"
#include "InputEvent.h"
#include "Scene.h"
#include <list>

using namespace GameFramework;

namespace ManhattanProject
{
	class Player: public Entity, public InputEvent
	{
		public:
			Player(Game* game);
			Player(Game* game, Scene* scene, Camera* camera);
		
			void Initialize();
			void Update();
			void Draw();
			
			void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
			
		private:
			Camera* camera;
			Scene* scene;
	};
}

#endif

