/*
 * This is the implementation file for the LauncherScene class.
 * Author: Jordan Ell
 * Date: 09/10/11
 */

#include "GameScene.h"

using namespace GameFramework;

namespace ManhattanProject
{
	GameScene::GameScene(Game* game):
		Scene(game)
	{
		this->game = game;

		this->Initialize();
		
		GetCurrentDir(RootDirectory, sizeof(RootDirectory));
		RootDirectory[sizeof(RootDirectory) -1] = '\0';
	}

	GameScene::~GameScene()
	{
		delete Map;
	}

	void GameScene::Initialize()
	{
		// Create Tile Map
		Map = new TileMap(game, Camera(Vector2(0, 0), Vector2(400, 600)), GameFramework::Rectangle(-1000,-1000,2000,2000));

		Map->AddTileLayer();
<<<<<<< HEAD

		Map->PrintLayers();

		delete Map;
=======
		
		Map = LoadMap("testing");
>>>>>>> Parser skeleton is in place

		Scene::Initialize();
	}
	
	void GameScene::CreateMap(TiXmlNode* pParent, TileMap* Map)
	{
		if (!pParent)
			return;
		
		TiXmlNode* pChild;
		TiXmlText* pText;
		int t = pParent->Type();
		
		switch ( t )
		{
			case TiXmlNode::TINYXML_DOCUMENT:
				// Do something for whole document
				break;
				
			case TiXmlNode::TINYXML_ELEMENT:
				// Do something with attributes
				break;
				
			case TiXmlNode::TINYXML_COMMENT:
				// Do nothing with a comment!
				break;
				
			case TiXmlNode::TINYXML_UNKNOWN:
				// Some unknown shit was in the file
				break;
				
			case TiXmlNode::TINYXML_TEXT:
				pText = pParent->ToText();
				// Do something with the text
				break;
				
			case TiXmlNode::TINYXML_DECLARATION:
				// Do something with the declaration
				break;
			default:
				break;
		}
		
		// For each child in the current node recurse.
		for ( pChild = pParent->FirstChild(); pChild != 0; pChild = pChild->NextSibling()) 
			CreateMap(pChild, Map);
	}
	
	TileMap* GameScene::LoadMap(const string &fileName)
	{
		TileMap* Map;
		
		string file = GetCurrentDir(RootDirectory, sizeof(RootDirectory));
		file += "/../content/";
		file += fileName;
		
		TiXmlDocument doc("../content/Maps/TestMap.xml");
		bool loadOkay = doc.LoadFile();
		if(loadOkay)
			CreateMap(&doc, Map);
		else
			cout << "Failed to load file\n";
			
		return Map;
	}

	void GameScene::Draw()
	{


		Scene::Draw();
	}

	void GameScene::Update()
	{

		Scene::Update();
	}
}

