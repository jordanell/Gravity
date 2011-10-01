/*
 * This is the header for the SceneManager class.
 * This class will be used to control the creating, deleting and drawing/updating of particular scenes.
 * Author: Jordan Ell
 * Date: 01/10/11
 */

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
 
#include "GameFramework.h"
#include "Scene.h"

using namespace GameFramework; 

namespace ManhattanProject
{
	class SceneManager: public DrawableGameComponent
	{
		public:
			SceneManager(Game* game);
			
			void Initialize();
			void Draw();
			void Update();
	};
}

#endif
