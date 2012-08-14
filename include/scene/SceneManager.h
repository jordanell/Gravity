/*
 * This is the header for the SceneManager class.
 * This class will be used to control the creating, deleting and drawing/updating of particular scenes.
 * Author: Jordan Ell
 * Date: 01/10/11
 */

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "framework.h"
#include "Scene.h"
#include "LauncherScene.h"
#include "GameScene.h"
#include "MenuScene.h"

using namespace framework;

namespace gravity
{
	class SceneManager: public DrawableGameComponent
	{
		public:
			SceneManager(Game* game);
            void toGameScene();
			Scene* ActiveScene;
			void Initialize();
			void Draw();
			void Update();

		protected:
			Scene* testScene;
	};
}

#endif
