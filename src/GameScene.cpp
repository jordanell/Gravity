/*
 * This is the implementation file for the LauncherScene class.
 * Author: Jordan Ell
 * Date: 09/10/11
 */

#include "GameScene.h"

using namespace framework;

namespace ManhattanProject
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
		// Create the serializer and load the map
		Serializer* ser = new Serializer(this->game);
		Map = ser->LoadMap(this->game, "Maps/Sandbox.xml", this);

		// Initialize the entities here
		player = new Player(game, this, &Map->camera);
		entityManager = new EntityManager(game, Map);

		// Initialize the path finding system here
		pathFinder = new PathfindingManager(game);

		// Initialize the UI Components here


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

		// Update the path finder information
		pathFinder->SetCollisions(Map->GetCollisionLayer()->GetCollisions());
		pathFinder->SetEntities(entityManager->GetActiveEntities());
		pathFinder->Update();

		Scene::Update();
	}
}

