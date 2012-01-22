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
		this->collisionLayer = new CollisionLayer(game, Size);
		debugging = false;
	}

	TileMap::TileMap(Game* game, Scene* scene, Camera camera, GameFramework::Rectangle Size):
		DrawableGameComponent(game)
	{
		this->game = game;
		this->camera = camera;
		this->Size = Size;
		this->collisionLayer = new CollisionLayer(game, Size);
		
		list<Uint8> listeners;
		listeners.push_back(SDL_KEYUP);
		scene->AddListener(this, listeners);
		
		debugging = false;
	}
	
	TileMap::~TileMap()
	{
		for(list<TileLayer*>::iterator it = layers.begin(); it != layers.end(); it++)
		{
			TileLayer* ptr = *it;
			delete ptr;
		}
		delete collisionLayer;
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
	
	TileLayer* TileMap::LastAddedLayer()
	{
		return layers.back();
	}
	
	CollisionLayer* TileMap::GetCollisionLayer()
	{
		return collisionLayer;
	}
	
	void TileMap::SetSize(GameFramework::Rectangle Size)
	{
		this->Size = Size;
	}

	void TileMap::Draw()
	{
		//Iterator over list of tiles and draw them
		for(list<TileLayer*>::iterator it = layers.begin(); it != layers.end(); it++)
		{
			TileLayer* ptr = *it;
			ptr->Draw(camera);
		}
		
		//If debugging then draw collisions
		if(debugging)
		{
			collisionLayer->Draw(camera);
		}
	}

	void TileMap::Update()
	{
		
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
	
	void TileMap::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
	{
		if(sym == SDLK_F2)
		{
			
			this->Debugging();
		}
	}
}

