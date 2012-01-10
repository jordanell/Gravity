/*
 * This is the header for the GameScene class.
 * This class will be used to encapsulate the Game level scenes
 * Author: Jordan Ell
 * Date: 24/10/11
 */

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <stdio.h>  /* defines FILENAME_MAX */
#ifdef WINDOWS
#include <direct.h>
	#define GetCurrentDir _getcwd
#else
#include <unistd.h>
	#define GetCurrentDir getcwd
#endif

#include "GameFramework.h"
#include "Scene.h"
#include "TileMap.h"

#include "tinyxml.h"
#include "tinystr.h"

// Entities
#include "Player.h"

using namespace GameFramework;

namespace ManhattanProject
{
	class GameScene: public Scene
	{
		public:
			char RootDirectory[FILENAME_MAX];
			
			GameScene(Game* game);

			void Initialize();
			
			int StringToNumber(const string &Text);
			
			void CreateMap(TiXmlNode* pParent, TileMap* Map);
			void ParseMapObject(TiXmlNode* pParent, TileMap* TileMap);
			
			TileMap* LoadMap(string fileName);
			
			void Update();
			void Draw();
			
			~GameScene();

		protected:
			TileMap* Map;
			Player* player;
	};
}

#endif
