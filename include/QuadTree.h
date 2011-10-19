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
#include <list>

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
			Rectangle Position;
			
			QuadNode();
			QuadNode(Rectangle rec);
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
			list<T*> GetElements(Camera camera);
		
		protected:
			QuadNode<T> Root;
			
			void BuildTree(QuadNode<T>* root);
			
			QuadNode<T>* RecursiveInsert(QuadNode<T>* root, int x, int y);
			
			list<T*> RecursiveGetElements(Camera camera, QuadNode<T>* root);
			list<T*> AddElements(QuadNode<T>* root);
			
			bool PointInNode(int x, int y, QuadNode<T> node);
	};
	
	/*
	 * Quad Node Implementation
	 */
	
	template <class T> QuadNode<T>::QuadNode()
	{
		
	}
	
	template <class T> QuadNode<T>::QuadNode(Rectangle rec)
	{
		this->Position.Height = rec.Height;
		this->Position.Width = rec.Width;
		this->Position.X = rec.X;
		this->Position.Y = rec.Y;
	}
	
	/*
	 * Quad Tree implementation
	 */
	
	template <class T> QuadTree<T>::QuadTree()
	{
		
	}
	
	template <class T> QuadTree<T>::QuadTree(int height, int width, int x, int y, int size)
	{
		this->Height = height;
		this->Width = width;
		this->X = x;
		this->Y = y;
		this->MinSize = size;
		
		//Initialize the root node
		this->Root = QuadNode<T>(Rectangle(this->X, this->Y, this->Height, this->Width));
		BuildTree(&this->Root);
	}
	
	template <class T> void QuadTree<T>::BuildTree(QuadNode<T>* root)
	{
		// Recursive build
		if(root->Position.Width * root->Position.Height > this->MinSize)
		{
			//Top left recursion
			root->TopLeft = new QuadNode<T>(Rectangle(root->Position.X, root->Position.Y, root->Position.Height/2, root->Position.Width/2));
			BuildTree(root->TopLeft);
			
			//Top right recursion
			root->TopRight = new QuadNode<T>(Rectangle(root->Position.X+root->Position.Width/2, root->Position.Y, root->Position.Height/2, root->Position.Width/2));
			BuildTree(root->TopRight);
			
			//Bottom right recursion
			root->BottomRight = new QuadNode<T>(Rectangle(root->Position.X+root->Position.Width/2, root->Position.Y+root->Position.Height/2, root->Position.Height/2, root->Position.Width/2));
			BuildTree(root->BottomRight);
			
			//Bottom left recursion
			root->BottomRight = new QuadNode<T>(Rectangle(root->Position.X, root->Position.Y+root->Position.Height/2, root->Position.Height/2, root->Position.Width/2));
			BuildTree(root->BottomLeft);
		}
		
		return;
	}
	
	template <class T> void QuadTree<T>::InsertElement(T element, int x, int y)
	{
		QuadNode<T>* node = RecursiveInsert(&this->Root, x, y);
		
		node->Collection.push_back(element);
	}
	
	template <class T> QuadNode<T>* QuadTree<T>::RecursiveInsert(QuadNode<T>* root, int x, int y)
	{		
		if(PointInNode(x, y, *root))
		{			
			//Then it must have no children and it is a leaf
			if(root->TopLeft == NULL)
				return root;
				
			else if(PointInNode(x, y, *(root->TopLeft)))
			   return RecursiveInsert(root->TopLeft, x, y);
			   
			else if(PointInNode(x, y, *(root->TopRight)))
				return RecursiveInsert(root->TopRight, x, y);
				
			else if(PointInNode(x, y, *(root->BottomRight)))
				return RecursiveInsert(root->BottomRight, x, y);
				
			else if(PointInNode(x, y, *(root->BottomLeft)))
				return RecursiveInsert(root->BottomLeft, x, y);
		}
		
		return NULL;
	}
	
	template <class T> bool QuadTree<T>::PointInNode(int x, int y, QuadNode<T> node)
	{
		if((x >= node.Position.X && x <= node.Position.Width) &&
		   (y >= node.Position.Y && y <= node.Position.Height))
			return true;
		else
			return false;
	}
	
	template <class T> list<T*> QuadTree<T>::GetElements(Camera camera)
	{
		list<T*> components;
		
		return components;
	}
	
	template <class T> list<T*> QuadTree<T>::RecursiveGetElements(Camera camera, QuadNode<T>* root)
	{
		list<T*> components;
		
		if(camera.GetRectangle().Intersects(root->Position))
		{
			if(root->TopLeft == NULL)
			{
				components = AddElements(root);
				return components;
			}
			
			else if(camera.GetRectangle().Intersects(root->TopLeft->Position))
			{
				components += RecursiveGetElements(camera, root->TopLeft);
				return components;
			}
			
			else if(camera.GetRectangle().Intersects(root->TopRight->Position))
			{
				components += RecursiveGetElements(camera, root->TopRight);
				return components;
			}
			
			else if(camera.GetRectangle().Intersects(root->BottomRight->Position))
			{
				components += RecursiveGetElements(camera, root->BottomRight);
				return components;
			}
			
			else if(camera.GetRectangle().Intersects(root->BottomLeft->Position))
			{
				components += RecursiveGetElements(camera, root->BottomLeft);
				return components;
			}
		}
		
		return components;
	}
	
	template <class T> list<T*> QuadTree<T>::AddElements(QuadNode<T>* root)
	{
		list<T*> components;
		
		typename list<T>::const_iterator it = root->Collection.begin();
		
		for(it; it != root->Collection.end(); it++)
			components.push_back(&it);
			
		return components;
	}
}

#endif