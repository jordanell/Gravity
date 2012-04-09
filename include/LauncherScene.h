/*
 * This is the header for the LauncherScene class.
 * This class will be used to encapsulate the game launcher presented on startup
 * Author: Jordan Ell
 * Date: 09/10/11
 */

#ifndef LAUNCHERSCENE_H
#define LAUNCHERSCENE_H

#include "GameFramework.h"
#include "Scene.h"
#include "Button.h"
#include "SceneManager.h"
using namespace GameFramework;

namespace ManhattanProject
{
    class SceneManager;class Button;
	class LauncherScene: public Scene
	{
		public:
			LauncherScene(Game* game);
            LauncherScene(Game* game, SceneManager* sm);
            SceneManager* sm;
			void Initialize();
			void Update();
			void Draw();

		protected:
			Texture2D* background;
            Button* startBtn;
            Button* quitBtn;
	};
}

#endif
