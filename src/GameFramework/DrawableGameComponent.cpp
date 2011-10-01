/*
 * This class represents the DrawableGameComponent.
 * Author: Jordan Ell
 * Date: 21/09/11
 */

#include "DrawableGameComponent.h"

namespace GameFramework
{
	DrawableGameComponent::DrawableGameComponent(Game* game)
		: GameComponent(game)
	{
		Enabled = true;
		Visible = true;
		this->game = game;
	}

	void DrawableGameComponent::Initialize()
	{
	}

	void DrawableGameComponent::Update()
	{
	}

	void DrawableGameComponent::Draw()
	{
	}	
}
