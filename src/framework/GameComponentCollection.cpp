/*
 * This is the definition for the GameComponentCollection class.
 * Author: Jordan Ell
 * Date: 25/09/11
 */

#include "GameComponentCollection.h"

namespace framework
{
	GameComponentCollection::GameComponentCollection()
	{
		Count = 0;
	}

	void GameComponentCollection::Add(GameComponent* Component)
	{
		items.push_back(Component);
		Count++;
	}

	void GameComponentCollection::Remove(GameComponent* Component)
	{
		items.remove(Component);
		Count = items.size();
	}
	
	void GameComponentCollection::Update()
	{
		list<GameComponent*>::iterator it;
		GameComponent* component;
		
		for(it=items.begin(); it!=items.end(); it++)
		{
			component = *it;
			component->Update();
		}
	}
	
	void GameComponentCollection::Draw()
	{
		list<GameComponent*>::iterator it;
		GameComponent* component;
		DrawableGameComponent* drawable;
		
		for(it=items.begin(); it!=items.end(); it++)
		{
			component = *it;
			drawable = dynamic_cast<DrawableGameComponent*>(component);
			if(drawable)
				drawable->Draw();
		}
	}
}
