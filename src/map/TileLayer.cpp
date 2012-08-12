/*
 * This is the implementation file for the TileLayer class.
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#include "TileLayer.h"
#include <list>

using namespace framework;

namespace gravity
{
	TileLayer::TileLayer(Game* game, framework::Rectangle size)
	{
		this->game = game;
		this->Size = size;
	}

	TileLayer::~TileLayer()
	{
		
	}

	/* Add a tile to the layer */
	void TileLayer::AddTile(Tile* tile)
	{
            
	}

	/* Add a tile to the layer */
	void TileLayer::AddTile(Texture2D* tex, Vector2 scale, float rotation, Vector2 position, Color color)
	{
		Tile* newTile = new Tile(game, tex, scale, rotation, position, color);
                this->Tiles.push_back(newTile);
	}

	void TileLayer::Draw(Camera camera)
	{
		//Iterate over list and draw tiles
		for(list<Tile*>::iterator it = Tiles.begin(); it != Tiles.end(); it++)
		{
			Tile* ptr = *it;
			ptr->Draw(camera);
		}
	}

	void TileLayer::Update()
	{

	}
}

