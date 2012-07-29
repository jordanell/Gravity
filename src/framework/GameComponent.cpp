/*
 * This class represents the GameComponent.
 * Author: Jordan Ell
 * Date: 21/09/11
 */

#include "GameComponent.h"

namespace framework
{
	GameComponent::GameComponent(Game* game)
	{
		Enabled = true;
		this->game = game;
	}

	void GameComponent::Initialize()
	{
	}

	void GameComponent::Update()
	{
	}	
}

