/*
 * This is the implementation file for the Container class.
 * Author: Jordan Ell
 * Date: 30/10/11
 */

#include "Container.h"

using namespace GameFramework;

namespace ManhattanProject
{
	Container::Container(Game* game):
		MapObject(game)
	{
		this->game = game;
	}
	
	Container::Container(Game* game, Texture2D* Tile, Vector2 Position):
		MapObject(game)
	{
		this->game = game;
		this->Tile = Tile;
		this->Position = Position;
	}
	
	Container::Container(Game* game, Texture2D* Tile, Vector2 Position, list<Item> Items, string Name, string Description):
		MapObject(game)
	{
		this->game = game;
		this->Tile = Tile;
		this->Position = Position;	
		this->Items = Items;
		this->Name = Name;
		this->Description = Description;																					
	}
	
	void Container::Draw(Camera camera)
	{
		//Draw this tile
		game->Render->Draw(Tile, Vector2(Position.X+camera.Position.X, Position.Y+camera.Position.Y), Color(255,255,255,255));
	}
}


