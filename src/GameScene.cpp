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
    
    GameScene::GameScene(Game* game, SceneManager* sm):
        Scene(game)
	{
		this->game = game;
        this->sm = sm;
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
		// Initialize the map here
		Map = LoadMap("Maps/Sandbox.xml");
		
		// Initialize the entities here
		player = new Player(game, this, &Map->camera);
		entityManager = new EntityManager(game, Map);
		
		// Initialize the path finding system here
		pathFinder = new PathfindingManager(game);
		
		// Initialize the UI Components here
		

		Scene::Initialize();
	}
	
	int GameScene::StringToNumber(const string &Text)
	{
		stringstream ss(Text);
		int result;
		return ss >> result ? result : 0;
	}
	
	void GameScene::ParseMapObject(TiXmlNode* pParent, TileMap* TileMap)
	{
		if(!pParent)
			return;
		
		TiXmlAttribute* pAttrib=pParent->ToElement()->FirstAttribute();
		TiXmlNode* pChild;
		string temp;
		string value = pAttrib->Value();
		
		if(!value.compare("TileObject"))
		{
			int PositionX = 0;
			int PositionY = 0;
			float Rotation = 0;
			int Scale = 0;
			int R = 0;
			int G = 0;
			int B = 0;
			int A = 0;
			string FileName;			
			
			for ( pChild = pParent->FirstChild(); pChild != 0; pChild = pChild->NextSibling())
			{
				string value = pChild->Value();
				
				//Handle the position
				if(!value.compare("Position"))
				{
					TiXmlNode* pPosition = pChild->FirstChild();
					temp = pPosition->ToElement()->GetText();
					PositionX = StringToNumber(temp);
					pPosition = pPosition->NextSibling();
					temp = pPosition->ToElement()->GetText();
					PositionY = StringToNumber(temp);
				}
				
				else if(!value.compare("Rotation"))
				{
					temp = pChild->ToElement()->GetText();
					Rotation = StringToNumber(temp);
				}
				
				else if(!value.compare("Scale"))
				{
					TiXmlNode* pPosition = pChild->FirstChild();
					temp = pPosition->ToElement()->GetText();
					Scale = StringToNumber(temp);
					pPosition = pPosition->NextSibling();
				}
				
				else if(!value.compare("TintColor"))
				{
					TiXmlNode* pPosition = pChild->FirstChild();
					temp = pPosition->ToElement()->GetText();
					R = StringToNumber(temp);
					pPosition = pPosition->NextSibling();
					temp = pPosition->ToElement()->GetText();
					G = StringToNumber(temp);
					pPosition = pPosition->NextSibling();
					temp = pPosition->ToElement()->GetText();
					B = StringToNumber(temp);
					pPosition = pPosition->NextSibling();
					temp = pPosition->ToElement()->GetText();
					A = StringToNumber(temp);
				}
				
				else if(!value.compare("texture_filename"))
				{
					temp = pChild->ToElement()->GetText();
					FileName = temp;
				}
			}
			//Load the texture
			Texture2D* texture = game->Content->LoadTexture(FileName);
			TileLayer* LayerToAdd = TileMap->LastAddedLayer();
			LayerToAdd->AddTile(texture, Scale, Rotation, Vector2(PositionX,PositionY), Color(R,G,B,A));
			
		}
		else if(!value.compare("CollisionRectangle"))
		{
			int PositionX = 0;
			int PositionY = 0;
			int Height = 0;
			int Width = 0;
			float Rotation = 0;
			
			for ( pChild = pParent->FirstChild(); pChild != 0; pChild = pChild->NextSibling())
			{
				string value = pChild->Value();
				
				//Handle the position
				if(!value.compare("Position"))
				{
					TiXmlNode* pPosition = pChild->FirstChild();
					temp = pPosition->ToElement()->GetText();
					PositionX = StringToNumber(temp);
					pPosition = pPosition->NextSibling();
					temp = pPosition->ToElement()->GetText();
					PositionY = StringToNumber(temp);
				}
				
				else if(!value.compare("Width"))
				{
					temp = pChild->ToElement()->GetText();
					Width = StringToNumber(temp);
				}
				
				else if(!value.compare("Height"))
				{
					temp = pChild->ToElement()->GetText();
					Height = StringToNumber(temp);
				}
			}
			
			//Create the collision object
			CollisionLayer* layer = TileMap->GetCollisionLayer();
			layer->AddCollision(PositionX, PositionY, Width, Height, Rotation);
		}
		
		return;
	}
	
	void GameScene::CreateMap(TiXmlNode* pParent, TileMap* TileMap)
	{
		if (!pParent)
			return;
		
		TiXmlNode* pChild;
		TiXmlText* pText;
		int t = pParent->Type();
		string value = pParent->Value();
		
		switch ( t )
		{
			case TiXmlNode::TINYXML_DOCUMENT:
				// Do something for whole document
				break;
				
			case TiXmlNode::TINYXML_ELEMENT:
				if(!value.compare("Layer"))
					TileMap->AddTileLayer();
				else if(!value.compare("MapObject"))
					ParseMapObject(pParent->ToElement(), TileMap);
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
			CreateMap(pChild, TileMap);
	}
	
	TileMap* GameScene::LoadMap(string fileName)
	{
		TileMap* LoadedMap = new TileMap(game, this, Camera(Vector2(0, 0), Vector2(400, 600)), GameFramework::Rectangle(-2000,-2000,4000,4000));;
		
		string file = GetCurrentDir(RootDirectory, sizeof(RootDirectory));
		file += "/../content/";
		file += fileName;
		const char* RealFileName = file.c_str();
		
		TiXmlDocument doc(RealFileName);
		bool loadOkay = doc.LoadFile();
		if(loadOkay)
			CreateMap(&doc, LoadedMap);
		else
			cout << "Failed to load map\n";
			
		return LoadedMap;
	}

	void GameScene::Draw()
	{
		Map->Draw();
		
		player->Draw();

		Scene::Draw();
	}

	void GameScene::Update()
	{
		// Call the update on the map
		Map->Update();
		
		// Update the path finder information
		pathFinder->SetCollisions(Map->GetCollisionLayer()->GetCollisions());
		pathFinder->SetEntities(entityManager->GetActiveEntities());
		pathFinder->Update();

		Scene::Update();
	}
}

