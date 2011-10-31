/*
 * This is the implementation file for the Item class.
 * Author: Jordan Ell
 * Date: 30/10/11
 */

#include "Item.h"

using namespace GameFramework;

namespace ManhattanProject
{
	Item::Item(Game* game)
	{
		this->game = game;
	}
	
	Item::Item(Game* game, Texture2D* Icon, Texture2D* Tile, float hp, float ep, float sp, float ap, float dp)
	{
		this->game = game;
		
		this->Icon = Icon;
		this->Tile = Tile;
		this->hp = hp;
		this->ep = ep;
		this->sp = sp;
		this->ap = ap;
		this->dp = dp;
	}
	
	Item::Item(Game* game, Texture2D* Icon, Texture2D* Tile, Vector2 Position,
			   float hp, float ep, float sp, float ap, float dp, string Name, string Description)
	{
		this->game = game;
		
		this->Icon = Icon;
		this->Tile = Tile;
		this->Position = Position;
		this->hp = hp;
		this->ep = ep;
		this->sp = sp;
		this->ap = ap;
		this->dp = dp;
		
		this->Name = Name;
		this->Description = Description;
	}
	
	void Item::Draw(Camera camera)
	{
		//Draw this tile
		game->Render->Draw(Tile, Vector2(Position.X+camera.Position.X, Position.Y+camera.Position.Y), Color(255,255,255,255));
	}
}
