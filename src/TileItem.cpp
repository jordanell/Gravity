/*
 * This is the implementation file for the TileItem class.
 * Author: Jordan Ell
 * Date: 16/4/2012
 */

#include "TileItem.h"

using namespace GameFramework;

namespace ManhattanProject
{
	TileItem::TileItem(Game* game):
		MapObject(game)
	{
		this->game = game;
	}

	TileItem::TileItem(Game* game, Vector2 s, float rot, Vector2 pos, Color col):
		MapObject(game)
	{
		this->game = game;
		Scale = s;
		Rotation = rot;
		Position = pos;
		TintColor = col;
	}

	void TileItem::Draw(Camera camera)
	{
		//Draw this tile

	}

	void TileItem::Update()
	{

	}
}

