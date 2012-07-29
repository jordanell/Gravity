/*
 * This is the header for the LauncherScene class.
 * This class will be used to encapsulate the game launcher presented on startup
 * Author: Jordan Ell
 * Date: 09/10/11
 */

#ifndef LAUNCHERSCENE_H
#define LAUNCHERSCENE_H

#include "framework.h"
#include "Scene.h"
#include "Button.h"
#include "CheckBox.h"
#include "Label.h"
#include "DropDown.h"
#include "SceneManager.h"

#ifdef __linux__
	#include "SDL/SDL_ttf.h"
#else
	#include "SDL_ttf.h"
#endif

using namespace framework;

namespace ManhattanProject
{
    class SceneManager;class Button;
    
	class LauncherScene: public Scene
	{
		public:
			LauncherScene(Game* game);
            LauncherScene(Game* game, SceneManager* sm);
             
			void Initialize();
			
			void Update();
			void Draw();

			CheckBox* fullScreen;
			Label* fullScreenLabel;
			
			CheckBox* sound;
			//Label* soundLabel;

			DropDown* resolution;
			
			SceneManager* sm;

		protected:
			Texture2D* background;
            Button* startBtn;
            Button* quitBtn;
	};
}

#endif
