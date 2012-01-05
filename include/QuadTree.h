/*
 * This is the header for the QuadTree class.
 * This class is a template for any kind of Quad Tree xstructure
 * Author: Jordan Ell
 * Date: 17/10/11
 */

#ifndef QUADTREE_H
#define QUADTREE_H

#include "GameFramework.h"
#include "Camera.h"
#include "GameDefines.h"
#include <list>
#include <iostream>

using namespace GameFramework;

namespace ManhattanProject
{
	template <class T> class QuadNode
	{
		public:
			QuadNode<T>* TopLeft;
			QuadNode<T>* TopRight;
			QuadNode<T>* BottomRight;
			QuadNode<T>* BottomLeft;
			list<T> Collection;
			GameFramework::Rectangle Position;

			QuadNode();
			QuadNode(GameFramework::Rectangle rec);

			~QuadNode();
	};

	template <class T> class QuadTree
	{
		public:
			int Height;
			int Width;
			int MinSize;
			int X;
			int Y;

			QuadTree();
			QuadTree(int height, int width, int x, int y, int size);

			void InsertElement(T element, int x, int y);
			list<T> GetElements(GameFramework::Rectangle rec);

			void PrintTree();
			
			~QuadTree();

		protected:
			QuadNode<T>* Root;

			void BuildTree(QuadNode<T>* root);

			QuadNode<T>* RecursiveInsert(QuadNode<T>* root, int x, int y);

			list<T> RecursiveGetElements(GameFramework::Rectangle rec, QuadNode<T>* root);
			list<T> AddElements(QuadNode<T>* root);

			bool PointInNode(int x, int y, QuadNode<T>* node);

			void RecursivePrint(QuadNode<T>* root);
	};

	/*
	 * Quad Node Implementation
	 */

	template <class T> QuadNode<T>::QuadNode()
	{
		TopLeft = NULL;
		TopRight = NULL;
		BottomRight = NULL;
		BottomLeft = NULL;
	}

	template <class T> QuadNode<T>::QuadNode(GameFramework::Rectangle rec)
	{
		this->Position.Height = rec.Height;
		this->Position.Width = rec.Width;
		this->Position.X = rec.X;
		this->Position.Y = rec.Y;

		TopLeft = NULL;
		TopRight = NULL;
		BottomRight = NULL;
		BottomLeft = NULL;
	}

	template <class T> QuadNode<T>::~QuadNode()
	{
		delete TopLeft;
		delete TopRight;
		delete BottomRight;
		delete BottomLeft;	
	}

	/*
	 * Quad Tree implementation
	 */

	template <class T> QuadTree<T>::QuadTree()
	{
		Root = new QuadNode<T>(GameFramework::Rectangle(0,0,400,600));
	}

	template <class T> QuadTree<T>::QuadTree(int height, int width, int x, int y, int size)
	{
		this->Height = height;
		this->Width = width;
		this->X = x;
		this->Y = y;
		this->MinSize = size;

		//Initialize the root node
		this->Root = new QuadNode<T>(GameFramework::Rectangle(this->X, this->Y, this->Height, this->Width));
		BuildTree(this->Root);
	}
	
	/* Destructor */
	template <class T> QuadTree<T>::~QuadTree()
	{
		delete Root;
	}

	template <class T> void QuadTree<T>::BuildTree(QuadNode<T>* root)
	{
		// Recursive build
		if(root->Position.Width * root->Position.Height > this->MinSize)
		{
			//Top left recursion
			root->TopLeft = new QuadNode<T>(GameFramework::Rectangle(root->Position.X, root->Position.Y, root->Position.Height/2, root->Position.Width/2));
			BuildTree(root->TopLeft);

			//Top right recursion
			root->TopRight = new QuadNode<T>(GameFramework::Rectangle(root->Position.X+root->Position.Width/2, root->Position.Y, root->Position.Height/2, root->Position.Width/2));
			BuildTree(root->TopRight);

			//Bottom right recursion
			root->BottomRight = new QuadNode<T>(GameFramework::Rectangle(root->Position.X+root->Position.Width/2, root->Position.Y+root->Position.Height/2, root->Position.Height/2, root->Position.Width/2));
			BuildTree(root->BottomRight);

			//Bottom left recursion
			root->BottomLeft = new QuadNode<T>(GameFramework::Rectangle(root->Position.X, root->Position.Y+root->Position.Height/2, root->Position.Height/2, root->Position.Width/2));
			BuildTree(root->BottomLeft);
		}
		return;
	}

	template <class T> void QuadTree<T>::InsertElement(T element, int x, int y)
	{
		QuadNode<T>* node = RecursiveInsert(this->Root, x, y);
		
		node->Collection.push_back(element);
	}

	template <class T> void QuadTree<T>::PrintTree()
	{
		RecursivePrint(this->Root);
	}

	template <class T> void QuadTree<T>::RecursivePrint(QuadNode<T>* root)
	{
		cout << "Node X: " << root->Position.X << " Y: " << root->Position.Y << " Height: " << root->Position.Height
			<< " Width: " << root->Position.Width << endl;
		typename list<T>::iterator it;
		int x = 0;
		for(it = root->Collection.begin(); it != root->Collection.end(); it++)
		{
			cout << "Item: " << x << endl;
			x++;
		}

		if(root->Position.Width * root->Position.Height > this->MinSize)
		{
			RecursivePrint(root->TopLeft);
			RecursivePrint(root->TopRight);
			RecursivePrint(root->BottomRight);
			RecursivePrint(root->BottomLeft);
		}
	}

	template <class T> QuadNode<T>* QuadTree<T>::RecursiveInsert(QuadNode<T>* root, int x, int y)
	{
		if(PointInNode(x, y, root))
		{
			//Then it must have no children and it is a leaf
			if(root->Position.Width * root->Position.Height <= this->MinSize)
				return root;

			else if(PointInNode(x, y, root->TopLeft))
			   return RecursiveInsert(root->TopLeft, x, y);

			else if(PointInNode(x, y, root->TopRight))
				return RecursiveInsert(root->TopRight, x, y);

			else if(PointInNode(x, y, root->BottomRight))
				return RecursiveInsert(root->BottomRight, x, y);

			else if(PointInNode(x, y, root->BottomLeft))
				return RecursiveInsert(root->BottomLeft, x, y);
		}

		return NULL;
	}

	template <class T> bool QuadTree<T>::PointInNode(int x, int y, QuadNode<T>* node)
	{
		if((x >= node->Position.X && x <= node->Position.X+node->Position.Width) &&
		   (y >= node->Position.Y && y <= node->Position.Y+node->Position.Height))
			return true;
		else
			return false;
	}

	template <class T> list<T> QuadTree<T>::GetElements(GameFramework::Rectangle rec)
	{
		list<T> components = RecursiveGetElements(GameFramework::Rectangle(rec.X-MAX_TILE_WIDTH, rec.Y-MAX_TILE_HEIGHT, rec.Height+MAX_TILE_HEIGHT, rec.Width+MAX_TILE_WIDTH), this->Root);

		return components;
	}

	template <class T> list<T> QuadTree<T>::RecursiveGetElements(GameFramework::Rectangle rec, QuadNode<T>* root)
	{
		list<T> components;
		list<T> recursiveComponents;

		if(rec.Intersects(&root->Position))
		{
			if(root->Position.Width * root->Position.Height <= this->MinSize)
			{
				components = AddElements(root);
				return components;
			}

			if(rec.Intersects(&root->TopLeft->Position))
			{
				recursiveComponents = RecursiveGetElements(rec, root->TopLeft);
				components.merge(recursiveComponents);
			}

			if(rec.Intersects(&root->TopRight->Position))
			{
				recursiveComponents = RecursiveGetElements(rec, root->TopRight);
				components.merge(recursiveComponents);
			}

			if(rec.Intersects(&root->BottomRight->Position))
			{
				recursiveComponents = RecursiveGetElements(rec, root->BottomRight);
				components.merge(recursiveComponents);
			}

			if(rec.Intersects(&root->BottomLeft->Position))
			{
				recursiveComponents = RecursiveGetElements(rec, root->BottomLeft);
				components.merge(recursiveComponents);
			}
		}

		return components;
	}

	template <class T> list<T> QuadTree<T>::AddElements(QuadNode<T>* root)
	{
		list<T> components;

		typename list<T>::iterator it;

		for(it = root->Collection.begin(); it != root->Collection.end(); it++)
			components.push_back(*it);

		return components;
	}
}

#endif
