/*
 * This is the header for the Player class.
 * This class will be used for the main character class.
 * Author: Jordan Ell
 * Date: 09/01/12
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "framework.h"
#include "Entity.h"
#include "Camera.h"
#include "InputEvent.h"
#include "Scene.h"
#include <list>

using namespace framework;

namespace gravity
{
	class Player: public Entity, public InputEvent
	{
		public:
			Player(Game* game);
			Player(Game* game, Scene* scene, Camera* camera);
		
			void Initialize();
			void Update();
			void Draw();
			
			void OnLButtonDown(int mX, int mY);
			
		private:
			Camera* camera;
			Scene* scene;
	};
}

#endif

