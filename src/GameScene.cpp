/*
 * This is the implementation file for the LauncherScene class.
 * Author: Jordan Ell
 * Date: 09/10/11
 */

#include "GameScene.h"

using namespace GameFramework;

namespace ManhattanProject
{
	GameScene::GameScene(Game* game):
		Scene(game)
	{
		this->game = game;

		this->Initialize();
	}
	
	GameScene::~GameScene()
	{
		delete Map;
	}

	void GameScene::Initialize()
	{
		// Create Tile Map
		while(1)
		{
		Map = new TileMap(game, Camera(Vector2(0, 0), Vector2(400, 600)), GameFramework::Rectangle(-1000,-1000,2000,2000));

		Map->AddTileLayer();

		Map->PrintLayers();
		
		delete Map;
		}

		Scene::Initialize();
	}

	void GameScene::Draw()
	{


		Scene::Draw();
	}

	void GameScene::Update()
	{

		Scene::Update();
	}
}

