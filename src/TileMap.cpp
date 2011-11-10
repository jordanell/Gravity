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

	TileMap::TileMap(Game* game, Camera camera, GameFramework::Rectangle Size):
		DrawableGameComponent(game)
	{
		this->game = game;
		this->camera = camera;
		this->Size = Size;
	}
	
	TileMap::~TileMap()
	{
		for(list<TileLayer*>::iterator it = layers.begin(); it != layers.end(); it++)
		{
			TileLayer* ptr = *it;
			delete ptr;
		}
	}

	void TileMap::Initialize()
	{

	}

	/* Tile Layer stuff */
	void TileMap::AddTileLayer()
	{
			TileLayer* newTileLayer = new TileLayer(game, Size);
			layers.push_back(newTileLayer);
	}

	void TileMap::AddTileLayer(TileLayer* layer)
	{
		layers.push_back(layer);
	}

	void TileMap::PrintLayers()
	{
		for(list<TileLayer*>::iterator it = layers.begin(); it != layers.end(); it++)
		{
			TileLayer* ptr = *it;
			ptr->Print();
		}
	}

	void TileMap::Debugging()
	{
		debugging = !debugging;
		for(list<TileLayer*>::iterator it = layers.begin(); it != layers.end(); it++)
		{
			TileLayer* ptr = *it;
			ptr->Debugging();
		}
	}

	void TileMap::Draw()
	{
		//Iterator over list of tiles and draw them
		for(list<TileLayer*>::iterator it = layers.begin(); it != layers.end(); it++)
		{
			TileLayer* ptr = *it;
			ptr->Draw(camera);
		}
	}

	void TileMap::Update()
	{

	}
}

