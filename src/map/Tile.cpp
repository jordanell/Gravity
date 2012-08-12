/*
 * This is the implementation file for the Tile class.
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#include "Tile.h"

using namespace framework;

namespace gravity
{
	Tile::Tile(Game* game)
	{
		this->game = game;
		this->TintColor = Color();
	}

	Tile::Tile(Game* game, Texture2D* tex, Vector2 s, float rot, Vector2 pos, Color col)
	{
		this->game = game;
		Texture = tex;
		TintColor = col;
	}

	void Tile::Draw(Camera camera)
	{
		
	}

	void Tile::Update()
	{

	}
}

