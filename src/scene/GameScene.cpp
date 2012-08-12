/*
 * This is the implementation file for the LauncherScene class.
 * Author: Jordan Ell
 * Date: 09/10/11
 */

#include "GameScene.h"

using namespace framework;

namespace gravity
{
	GameScene::GameScene(Game* game):
		Scene(game)
	{
		this->game = game;
		this->Initialize();

		GetCurrentDir(RootDirectory, sizeof(RootDirectory));
		RootDirectory[sizeof(RootDirectory) -1] = '\0';
	}

    	GameScene::GameScene(Game* game, SceneManager* sm):
        	Scene(game)
	{
		this->game = game;
        	this->sm = sm;
		this->Initialize();

		GetCurrentDir(RootDirectory, sizeof(RootDirectory));
		RootDirectory[sizeof(RootDirectory) -1] = '\0';
	}

	GameScene::~GameScene()
	{
		delete Map;
	}

	void GameScene::Initialize()
	{
		// Create the map loader and load the map
		MapLoader* ml = new MapLoader(this->game);
		Map = ml->LoadMap(this->game, "maps/testlevel.xml", this);

		// Initialize the entities here
		player = new Player(game, this, &Map->camera);
		entityManager = new EntityManager(game, Map);


		Scene::Initialize();
	}

	void GameScene::Draw()
	{
		Map->Draw();

		player->Draw();

		Scene::Draw();
	}

	void GameScene::Update()
	{
		// Call the update on the map
		Map->Update();

		Scene::Update();
	}
}

