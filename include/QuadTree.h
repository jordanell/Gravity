/*
 * This is the header for the QuadTree class.
 * This class is a template for any kind of Quad Tree xstructure
 * Author: Jordan Ell
 * Date: 17/10/11
 */

#ifndef QUADTREE_H
#define QUADTREE_H

#include "GameFramework.h"
#include <list>

using namespace GameFramework;

namespace ManhattanProject
{
	template <class T> class QuadNode
	{
		public:
			list<QuadNode> Children;
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
			QuadTree(T type, int height, int width, int x, int y, int size);
			
			void InsertElement(T element, int x, int y);
		
		protected:
			QuadNode<T> Root;
			
			void BuildTree(QuadNode<T> root);
			QuadNode<T>* RecursiveInsert(QuadNode<T> root, int x, int y);
			bool PointInNode(int x, int y, QuadNode<T> node);
	};
}

#endif