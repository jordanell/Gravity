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
	}
	
	Tile::Tile(Game* game, Texture2D* tex, float s, float rot, Vector2 pos, Color col):
		MapObject(game)
	{
		this->game = game;
		texture = tex;
		scale = s;
		rotation = rot;
		position = pos;
		color = col;
	}
	
	void Tile::Draw(Camera camera)
	{
		//Draw this tile
		cout << camera.Position.X << "\n";
		game->Render->Draw(texture, Vector2(position.X-camera.Position.X, position.Y-camera.Position.Y), color);
	}
	
	void Tile::Update()
	{
		
	}
}

