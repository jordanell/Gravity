/*
 * This is the implementation file for the TileLayer class.
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#include "TileLayer.h"

using namespace GameFramework;

namespace ManhattanProject
{
	TileLayer::TileLayer(Game* game)
	{
		this->game = game;
	}
	
	void TileLayer::AddTile(Texture2D* tex, float alpha, float scale, float rotation, Vector2 position, Color color)
	{
		Tile newTile(game, tex, alpha, scale, rotation, position, color);
		tiles.push_back(newTile);
	}
	
	void TileLayer::Draw()
	{
		//Iterator over list of tiles and draw them
		for(list<Tile>::iterator it = tiles.begin(); it != tiles.end(); it++)
			it->Draw();
	}
	
	void TileLayer::Update()
	{
		
	}
}

