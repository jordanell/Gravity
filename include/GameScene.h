/*
 * This is the header for the GameScene class.
 * This class will be used to encapsulate the Game level scenes
 * Author: Jordan Ell
 * Date: 24/10/11
 */

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "GameFramework.h"
#include "Scene.h"
#include "TileMap.h"

using namespace GameFramework;

namespace ManhattanProject
{
	class GameScene: public Scene
	{
		public:
			GameScene(Game* game);
		
			void Initialize();
			void Update();	
			void Draw();
		
		protected:
	};
}

#endif