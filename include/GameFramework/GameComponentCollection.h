/*
 * This is the header for the GameComponentCollection class.
 * Author: Jordan Ell
 * Date: 25/09/11
 */

#ifndef GAMECOMPONENTCOLLECTION_H
#define GAMECOMPONENTCOLLECTION_H

#include "GameComponent.h"
#include "Exception.h"
#include <cstddef>

namespace GameFramework
{
	class Node
	{
		public:
			Node* Next;
			GameComponent* Component;

			Node(GameComponent* Component);
	};

	class GameComponentCollection
	{
		public:
			int Count;
			Node* Head;
			Node* Tail;

			GameComponentCollection();

			void Add(GameComponent* Component);
			bool Contains(GameComponent* Component);
			void Remove(GameComponent* Component);
			void Insert(GameComponent* Component, int Index);			
	};
}

#endif
