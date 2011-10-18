/*
 * This is the implementation file for the QuadTree class.
 * Author: Jordan Ell
 * Date: 17/10/11
 */

#include "QuadTree.h"
#include <iostream>

using namespace GameFramework;

namespace ManhattanProject
{
		
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
		
	template <class T> QuadTree<T>::QuadTree(T type, int height, int width, int x, int y, int size)
	{
		this->Height = height;
		this->Width = width;
		this->X = x;
		this-Y = y;
		this->MinSize = size;
		
		//Initialize the root node
		this->Root(Rectangle(X, Y, Height, Width));
	}
		
	template <class T> void QuadTree<T>::BuildTree(QuadNode<T> root)
	{
		// Recursive build
		if(root.Width * root.Height > this->MinSize)
		{
			//Top left recursion
			root.Children.push_back(QuadNode<T>(Rectangle(this->X, this->Y, root.height/2, root.width/2)));
			BuildTree(root.Children.back());
			
			//Top right recursion
			root.Children.push_back(QuadNode<T>(Rectangle(this->X+root.width/2, this->Y, root.height/2, root.width/2)));
			BuildTree(root.Children.back());
			
			//Bottom right recursion
			root.Children.push_back(QuadNode<T>(Rectangle(this->X+root.width/2, this->Y+root.height/2, root.height/2, root.width/2)));
			BuildTree(root.Children.back());
			
			//Bottom left recursion
			root.Children.push_back(QuadNode<T>(Rectangle(this->X, this->Y+root.height/2, root.height/2, root.width/2)));
			BuildTree(root.Children.back());
		}
		
		return;
	}
	
	template <class T> void QuadTree<T>::InsertElement(T element, int x, int y)
	{
		QuadNode<T>* node = RecursiveInsert(this->Root, x, y);
		
		node->Collection.push_back(element);
	}
	
	template <class T> QuadNode<T>* QuadTree<T>::RecursiveInsert(QuadNode<T> root, int x, int y)
	{		
		if(this->PointInNode(x, y, root))
		{
			if(root.Children.empty())
				return &root;
			
			typename list<T>::const_iterator it = root.Children.begin();
			
			for(it; it != root.Children.end(); it++)
			{
				if(this->PointInNode(x, y, it))
					return RecursiveInsert(it, x, y);
			}
		}
		
		return NULL;
	}
	
	template <class T> bool QuadTree<T>::PointInNode(int x, int y, QuadNode<T> node)
	{
		if((x >= node.X && x <= node.Width) &&
			(y >= node.Y && y <= node.Height))
			return true;
		else
			return false;
	}
}