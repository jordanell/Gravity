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
	
	TileMap::TileMap(Game* game, Camera camera, Rectangle Size):
		DrawableGameComponent(game)
	{
		this->game = game;
		this->camera = camera;
		this->Size = Size;
	}
	
	void TileMap::Initialize()
	{
	
	}
	
	/* Tile Layer stuff */
	void TileMap::AddTileLayer()
	{
		TileLayer newTileLayer(game, Size);
		layers.push_back(newTileLayer);
	}
	
	void TileMap::AddTileLayer(TileLayer layer)
	{
		layers.push_back(layer);
	}
	
	/* Collision Layer stuff */
	void TileMap::AddCollisionLayer()
	{
		CollisionLayer newCollisionLayer(game, Size);
		collision.push_back(newCollisionLayer);
	}
	
	void TileMap::AddCollisionLayer(CollisionLayer layer)
	{
		collision.push_back(layer);
	}
	
	void TileMap::PrintLayers()
	{
		for(list<TileLayer>::iterator it = layers.begin(); it != layers.end(); it++)
			it->Print();
	}
	
	void TileMap::Debugging()
	{
		debugging = !debugging;
		for(list<TileLayer>::iterator it = layers.begin(); it != layers.end(); it++)
			it->Debugging();
	}
	
	void TileMap::Draw()
	{
		//Iterator over list of tiles and draw them
		for(list<TileLayer>::iterator it = layers.begin(); it != layers.end(); it++)
			it->Draw(camera);
	}
	
	void TileMap::Update()
	{
		
	}
}

