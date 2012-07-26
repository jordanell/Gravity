/*
 * This is the implementation file for the TileLayer class.
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#include "TileLayer.h"
#include <list>

using namespace GameFramework;

namespace ManhattanProject
{
	TileLayer::TileLayer(Game* game, GameFramework::Rectangle size)
	{
		this->game = game;
		this->Size = size;

		//Instantiate the QuadTree
		TileTree = new QuadTree<MapObject*>(Size.Height, Size.Width, Size.X, Size.Y, DEFAULT_QUADTREE_RECT);
	}

	TileLayer::~TileLayer()
	{
		delete TileTree;
	}

	/* Add a tile to the layer */
	void TileLayer::AddTile(Tile* tile)
	{
        	TileTree->InsertElement(tile, tile->Position.X, tile->Position.Y);
	}

	/* Add a tile to the layer */
	void TileLayer::AddTile(Texture2D* tex, Vector2 scale, float rotation, Vector2 position, Color color)
	{
		Tile* newTile = new Tile(game, tex, scale, rotation, position, color);

		TileTree->InsertElement(newTile, position.X, position.Y);
	}

	/* Add a container to the layer */
	void TileLayer::AddContainer(Game* game, Texture2D* Tile, Vector2 Position, list<Item> Items, string Name, string Description)
	{
		Container* newCont = new Container(game, Tile, Position, Items, Name, Description);

		TileTree->InsertElement(newCont, Position.X, Position.Y);
	}

	/* Add a item to the layer */
	void TileLayer::AddItem(Game* game, Texture2D* Icon, Texture2D* Tile, Vector2 Position, float hp, float ep, float sp,
							float ap, float dp, string Name, string Description)
	{
		Item* newItem = new Item(game, Icon, Tile, Position, hp, ep, sp, ap, dp, Name, Description);

		TileTree->InsertElement(newItem, Position.X, Position.Y);
	}

	void TileLayer::Print()
	{
		TileTree->PrintTree();
	}

	void TileLayer::Debugging()
	{
		debugging = !debugging;
	}

	void TileLayer::Draw(Camera camera)
	{
		//Get List of tiles to draw
		DrawingTiles = TileTree->GetElements(camera.GetRectangle());

		//Sort the list based on zindex
		DrawingTiles.sort();
		int i = 0;
		//Iterate over list and draw tiles
		for(list<MapObject*>::iterator it = DrawingTiles.begin(); it != DrawingTiles.end(); it++)
		{
			MapObject* ptr = *it;
			ptr->Draw(camera);
			i++;
		}
	}

	void TileLayer::Update()
	{

	}
}

