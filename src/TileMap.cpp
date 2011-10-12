/*
 * This is the implementation file for the TileMap class.
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#include "TileMap.h"

using namespace GameFramework;

namespace ManhattanProject
{
	TileMap::TileMap(Game* game):
		DrawableGameComponent(game)
	{
		this->game = game;
	}
	
	void TileMap::Initialize()
	{
	
	}
	
	void TileMap::AddLayer()
	{
		TileLayer newTileLayer(game);
		layers.push_back(newTileLayer);
	}
	
	void TileMap::Draw()
	{
		//Iterator over list of tiles and draw them
		for(list<TileLayer>::iterator it = layers.begin(); it != layers.end(); it++)
			it->Draw();
	}
	
	void TileMap::Update()
	{
		
	}
}

