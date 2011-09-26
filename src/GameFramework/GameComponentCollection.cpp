/*
 * This is the definition for the GameComponentCollection class.
 * Author: Jordan Ell
 * Date: 25/09/11
 */

#include "GameComponentCollection.h"

namespace Game_Framework
{

	Node::Node(GameComponent* Component)
	{
		this->Component = Component;
		this->Next = NULL;
	}

	GameComponentCollection::GameComponentCollection()
	{
		Count = 0;
		Head = NULL;
		Tail = NULL;
	}

	void GameComponentCollection::Add(GameComponent* Component)
	{
		Node* node = new Node(Component);
		Count++;
		
		if(this->Head == NULL)
		{
			this->Head = node;
			this->Tail = node;
			return;
		}

		this->Tail->Next = node;
		this->Tail = node;
		return;
	}

	bool GameComponentCollection::Contains(GameComponent* Component)
	{
		Node* iterator;
		for(iterator = Head; iterator != NULL; iterator = iterator->Next)
		{
			if(iterator->Component == Component)
				return true;
		}
		
		return false;
	}

	void GameComponentCollection::Remove(GameComponent* Component)
	{
		Node* ptr;
		if(this->Head->Component == Component)
		{
			ptr = this->Head->Next;
			delete this->Head;
			this->Head = ptr;
			this->Count--;
			return;
		}
		else
		{
			Node* iterator;
			for(iterator = Head; iterator != NULL; iterator = iterator->Next)
			{
				if(iterator->Next->Component == Component)
				{
					ptr = iterator->Next;
					if(iterator->Next != NULL)
						iterator->Next = iterator->Next->Next;
					else
						this->Tail = iterator;
					delete ptr;
					this->Count--;
					return;
				}
			}
		}

		throw Exception("Element does not exist", 1, __FILE__, __LINE__);
	}

	void GameComponentCollection::Insert(GameComponent* Component, int Index)
	{
		if(Index > this->Count || Index < 0)
			throw Exception("Array out of bounds", 2, __FILE__, __LINE__);

		Node* node = new Node(Component);
		Count++;
		Node* ptr;

		if(Index == 0)
		{
			if(this->Head == NULL)
			{
				this->Head = node;
				this->Tail = node;
				return;
			}
			else
			{
				ptr = this->Head;
				this->Head = node;
				this->Head->Next = ptr;
				return;
			}
		}
		else
		{
			Node* iterator;
			int i =0;
			for(iterator = Head; iterator != NULL; iterator = iterator->Next)
			{
				if(i+1 == Index)
				{
					ptr = iterator->Next;
					iterator->Next = node;
					node->Next = ptr;
					if(ptr == NULL)
						this->Tail = node;
					return;
				}
				i++;
			}
			return;
		}
	}
}
