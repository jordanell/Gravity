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
	
	TileLayer* TileMap::LastAddedLayer()
	{
		return layers.back();
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
	}

	void TileMap::Update()
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_KEYDOWN)
			{
				if(event.key.keysym.sym == SDLK_LEFT)
					left = true;
				if(event.key.keysym.sym == SDLK_RIGHT)
					right = true;
				if(event.key.keysym.sym == SDLK_UP)
					up = true;
				if(event.key.keysym.sym == SDLK_DOWN)
					down = true;
			}
			if(event.type == SDL_KEYUP)
			{
				if(event.key.keysym.sym == SDLK_LEFT)
					left = false;
				if(event.key.keysym.sym == SDLK_RIGHT)
					right = false;
				if(event.key.keysym.sym == SDLK_UP)
					up = false;
				if(event.key.keysym.sym == SDLK_DOWN)
					down = false;
			}
		}
		if(left)
			this->camera.Position.X -= 4;
		if(right)
			this->camera.Position.X += 4;
		if(up)
			this->camera.Position.Y -= 4;
		if(down)
			this->camera.Position.Y += 4;
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
}

