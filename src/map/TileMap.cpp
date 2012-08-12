/*
 * This is the implementation file for the TileMap class.
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#include "TileMap.h"

using namespace framework;

namespace gravity
{
	TileMap::TileMap(Game* game):
		DrawableGameComponent(game)
	{
		this->game = game;
	}

	TileMap::TileMap(Game* game, Scene* scene):
		DrawableGameComponent(game)
	{
		this->game = game;
                this->scene = scene;
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
			TileLayer* newTileLayer = new TileLayer(game);
			layers.push_back(newTileLayer);
	}

	void TileMap::AddTileLayer(TileLayer* layer)
	{
		layers.push_back(layer);
	}

	TileLayer* TileMap::LastAddedLayer()
	{
		return layers.back();
	}

	void TileMap::Draw(Camera* camera)
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

