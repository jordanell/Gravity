/*
 * This is the implementation file for the TileLayer class.
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#include "TileLayer.h"

using namespace GameFramework;

namespace ManhattanProject
{
	TileLayer::TileLayer(Game* game, Camera camera, Rectangle size)
	{
		this->game = game;
		this->camera = camera;
		this->Size = size;
		
		//Instantiate the QuadTree
		TileTree = QuadTree<Tile>(Size.Height, Size.Width, Size.X, Size.Y, DEFAULT_QUADTREE_RECT);
	}
	
	void TileLayer::AddTile(Texture2D* tex, float alpha, float scale, float rotation, Vector2 position, Color color)
	{
		Tile newTile(game, tex, alpha, scale, rotation, position, color);
		
		TileTree.InsertElement(newTile, position.X, position.Y);
	}
	
	void TileLayer::Draw()
	{
		//Get List of tiles to draw
		DrawingTiles = TileTree.GetElements(camera.GetRectangle());
		
		//Iterate over list and draw tiles
		for(list<Tile*>::iterator it = DrawingTiles.begin(); it != DrawingTiles.end(); it++)
		{
			Tile* ptr = *it;
			ptr->Draw();
		}
	}
	
	void TileLayer::Update()
	{
		
	}
}

