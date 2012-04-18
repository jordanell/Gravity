/*
 * This is the implementation file for the Serializer class.
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#include "Serializer.h"

using namespace GameFramework;

namespace ManhattanProject
{
	Serializer::Serializer(Game* game)
	{
		this->game = game;
	}

    int Serializer::StringToNumber(const string &Text)
	{
		stringstream ss(Text);
		int result;
		return ss >> result ? result : 0;
	}

    // Deserializing methods
    TileMap* Serializer::LoadMap(Game* game, const std::string &fileName, Scene* scene)
    {
        // Get the path to the map to load
        string file = GetCurrentDir(game->Content->RootDirectory, sizeof(game->Content->RootDirectory));
		file += "/../content/";
		file += fileName;
		const char* RealFileName = file.c_str();

        // Try and load the XML file here
		TiXmlDocument doc(RealFileName);
		bool loadOkay = doc.LoadFile();
		if(loadOkay)
		    return ParseMap(game, &doc, scene);
		else
		{
		    cout << "Failed to load map\n";
		    return NULL;
		}
    }

    TileMap* Serializer::ParseMap(Game* game, TiXmlNode* parent, Scene* scene)
    {
        if(!parent)
            return NULL;

        TiXmlNode* childNode;
        TiXmlNode* layerNode;

        /* Temporary variables for the map*/
        int Top, Bottom, Right, Left = 0;
        string temp;

        // Get all of the map elements.
        for ( childNode = parent->FirstChild(); childNode != 0; childNode = childNode->NextSibling())
        {
            string value = childNode->Value();
            // Find the layers XML node
            if(!value.compare("Layers"))
                layerNode = childNode;
            else if(!value.compare("Top"))
            {
                temp = childNode->ToElement()->GetText();
                Top = StringToNumber(temp);
            }
            else if(!value.compare("Bottom"))
            {
                temp = childNode->ToElement()->GetText();
                Bottom = StringToNumber(temp);
            }
            else if(!value.compare("Right"))
            {
                temp = childNode->ToElement()->GetText();
                Right = StringToNumber(temp);
            }
            else if(!value.compare("Left"))
            {
                temp = childNode->ToElement()->GetText();
                Left = StringToNumber(temp);
            }
        }

        // Now that the variables are set we can create the map
        TileMap* map = new TileMap(game, scene, Camera(Vector2(0, 0), Vector2(game->Render->GetWidth(), game->Render->GetHeight())),
                                   GameFramework::Rectangle(Left-MAX_TEXTURE_WIDTH,Top-MAX_TEXTURE_HEIGHT,Bottom+MAX_TEXTURE_HEIGHT,Right+MAX_TEXTURE_WIDTH));

        // Now parse the layers in the layers node
        map = ParseLayers(map, layerNode);

        return map;
    }

    TileMap* Serializer::ParseLayers(TileMap* map, TiXmlNode* parent)
    {
        if(!parent)
            return NULL;

        TiXmlNode* childNode;

        /* Temporary variables for the layers*/
        string temp;

        // Get all of the layer elements.
        for ( childNode = parent->FirstChild(); childNode != 0; childNode = childNode->NextSibling())
        {
            string value = childNode->Value();
            // Add any new layer to the map
            if(!value.compare("TileLayer"))
            {
                map->AddTileLayer();
                TileLayer* LayerToAdd = map->LastAddedLayer();
                ParseLayer(LayerToAdd, childNode);
            }
        }

        return map;
    }

    void Serializer::ParseLayer(TileLayer* layer, TiXmlNode* parent)
    {
        TiXmlNode* childNode;

        // Get all of the layer's elements.
        for ( childNode = parent->FirstChild(); childNode != 0; childNode = childNode->NextSibling())
        {
            string value = childNode->Value();
            if(!value.compare("MapObjects"))
            {
                ParseMapObjects(layer, childNode);
            }
        }

    }

    void Serializer::ParseMapObjects(TileLayer* layer, TiXmlNode* parent)
    {
        TiXmlNode* childNode;
        TiXmlAttribute* typeAttribute;

        // Get all of the map objects list elements.
        for ( childNode = parent->FirstChild(); childNode != 0; childNode = childNode->NextSibling())
        {
            typeAttribute=parent->ToElement()->FirstAttribute();
            string value = typeAttribute->Value();
            if(!value.compare("Tile"))
                ParseTile(layer, childNode);
            else if(!value.compare("CollisionRectangle"))
                ParseCollisionRectangle(layer, childNode);
        }

    }

    void Serializer::ParseTile(TileLayer* layer, TiXmlNode* parent)
    {
        TiXmlNode* childNode;

        // Get all of the tile's elements.
        for ( childNode = parent->FirstChild(); childNode != 0; childNode = childNode->NextSibling())
        {
            string value = childNode->Value();
        }
    }

    void Serializer::ParseCollisionRectangle(TileLayer* layer, TiXmlNode* parent)
    {
        TiXmlNode* childNode;

        // Get all of the collision rectangle's elements.
        for ( childNode = parent->FirstChild(); childNode != 0; childNode = childNode->NextSibling())
        {
            string value = childNode->Value();
        }
    }
}
