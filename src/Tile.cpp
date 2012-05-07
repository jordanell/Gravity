/*
 * This is the implementation file for the Tile class.
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#include "Tile.h"

using namespace GameFramework;

namespace ManhattanProject
{
	Tile::Tile(Game* game):
		MapObject(game)
	{
		this->game = game;
		this->Position = Vector2();
		this->Scale = Vector2();
		this->TintColor = Color();
	}

	Tile::Tile(Game* game, Texture2D* tex, Vector2 s, float rot, Vector2 pos, Color col):
		MapObject(game)
	{
		this->game = game;
		Texture = tex;
		Scale = s;
		Rotation = rot;
		Position = pos;
		TintColor = col;
	}

	void Tile::Draw(Camera camera)
	{
		//Draw this tile
		game->Render->Draw(Texture, Vector2(Position.X-camera.Position.X, Position.Y-camera.Position.Y), TintColor);
	}

	void Tile::Update()
	{

	}
}

