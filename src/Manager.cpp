/*
 * This is the implementation file for the Manager class.
 * Author: Jordan Ell
 * Date: 01/10/11
 */

#include "Manager.h"
#include <iostream>

using namespace framework;

namespace ManhattanProject
{
	Manager::Manager():
		Game()
	{

	}

	void Manager::Initialize()
	{
		Game::Initialize();

		// Create the Scene Manager
		sceneManager = new SceneManager(this);
		this->Components->Add(sceneManager);

		// Create the Input Manager
		inputManager = new InputManager(this);
		inputManager->SetScene(sceneManager);
		this->Components->Add(inputManager);
	}

	void Manager::Draw()
	{

		Game::Draw();
	}

	void Manager::Update()
	{

		Game::Update();
	}
}

