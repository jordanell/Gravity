/*
 * This is the implementation file for the Serializer class.
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#include "Serializer.h"

using namespace framework;

namespace gravity
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
            // Go into the map
            if(!value.compare("TileMap"))
                childNode = childNode->FirstChild();
            // Find the layers XML node
            else if(!value.compare("Layers"))
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
                                   framework::Rectangle(Left-MAX_TEXTURE_WIDTH,Top-MAX_TEXTURE_HEIGHT,Right+MAX_TEXTURE_WIDTH,Bottom+MAX_TEXTURE_HEIGHT));

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
                ParseLayer(map, LayerToAdd, childNode);
            }
        }

        return map;
    }

    void Serializer::ParseLayer(TileMap* map, TileLayer* layer, TiXmlNode* parent)
    {
        TiXmlNode* childNode;

        // Get all of the layer's elements.
        for ( childNode = parent->FirstChild(); childNode != 0; childNode = childNode->NextSibling())
        {
            string value = childNode->Value();
            if(!value.compare("MapObjects"))
            {
                ParseMapObjects(map, layer, childNode);
            }
        }

    }

    void Serializer::ParseMapObjects(TileMap* map, TileLayer* layer, TiXmlNode* parent)
    {
        TiXmlNode* childNode;
        TiXmlAttribute* typeAttribute;

        // Get all of the map objects list elements.
        for ( childNode = parent->FirstChild(); childNode != 0; childNode = childNode->NextSibling())
        {
            typeAttribute=childNode->ToElement()->FirstAttribute();
            string value = typeAttribute->Value();
            if(!value.compare("Tile"))
                ParseTile(layer, childNode);
            else if(!value.compare("CollisionRectangle"))
                ParseCollisionRectangle(map, childNode);
        }

    }

    void Serializer::ParseTile(TileLayer* layer, TiXmlNode* parent)
    {
        TiXmlNode* childNode;

        // Create the new tile
        Tile* tile = new Tile(this->game);

        // Get all of the tile's elements.
        for ( childNode = parent->FirstChild(); childNode != 0; childNode = childNode->NextSibling())
        {
            string value = childNode->Value();
            if(!value.compare("Description"))
                tile->Description = childNode->ToElement()->GetText();
            else if(!value.compare("TopLeftPosition"))
            {
                TiXmlNode* position = childNode->FirstChild();
                value = position->ToElement()->GetText();
				tile->Position.X = StringToNumber(value);
				position = position->NextSibling();
				value = position->ToElement()->GetText();
				tile->Position.Y = StringToNumber(value);
            }
            else if(!value.compare("Rotation"))
                tile->Rotation = StringToNumber(childNode->ToElement()->GetText());
            else if(!value.compare("Scale"))
            {
                TiXmlNode* scale = childNode->FirstChild();
                value = scale->ToElement()->GetText();
				tile->Scale.X = StringToNumber(value);
				scale = scale->NextSibling();
				value = scale->ToElement()->GetText();
				tile->Scale.Y = StringToNumber(value);
            }
            else if(!value.compare("zindex"))
                tile->zindex = StringToNumber(childNode->ToElement()->GetText());
            else if(!value.compare("TintColor"))
            {
                TiXmlNode* color = childNode->FirstChild();
                value = color->ToElement()->GetText();
				tile->TintColor.Red = StringToNumber(value);
				color = color->NextSibling();
				value = color->ToElement()->GetText();
				tile->TintColor.Green = StringToNumber(value);
				color = color->NextSibling();
				value = color->ToElement()->GetText();
				tile->TintColor.Blue = StringToNumber(value);
				color = color->NextSibling();
				value = color->ToElement()->GetText();
				tile->TintColor.Alpha = StringToNumber(value);
            }
            else if(!value.compare("texture_filename"))
                tile->Texture = game->Content->LoadTexture(childNode->ToElement()->GetText());
        }

        // Add the tile to the layer
        layer->AddTile(tile);
    }

    void Serializer::ParseCollisionRectangle(TileMap* map, TiXmlNode* parent)
    {
        TiXmlNode* childNode;

        CollisionRectangle* collision = new CollisionRectangle(this->game);

        // Get all of the collision rectangle's elements.
        for ( childNode = parent->FirstChild(); childNode != 0; childNode = childNode->NextSibling())
        {
            string value = childNode->Value();
            if(!value.compare("TopLeftPosition"))
            {
                TiXmlNode* position = childNode->FirstChild();
                value = position->ToElement()->GetText();
				collision->Position.X = StringToNumber(value);
				position = position->NextSibling();
				value = position->ToElement()->GetText();
				collision->Position.Y = StringToNumber(value);
            }
            else if(!value.compare("Rotation"))
                collision->Rotation = StringToNumber(value);
            else if(!value.compare("Scale"))
            {
                TiXmlNode* scale = childNode->FirstChild();
                value = scale->ToElement()->GetText();
				collision->Scale.X = StringToNumber(value);
				scale = scale->NextSibling();
				value = scale->ToElement()->GetText();
				collision->Scale.Y = StringToNumber(value);
            }
            else if(!value.compare("Width"))
                collision->Width = StringToNumber(childNode->ToElement()->GetText());
            else if(!value.compare("Height"))
                collision->Width = StringToNumber(childNode->ToElement()->GetText());
        }

        map->GetCollisionLayer()->AddCollision(collision);
    }
}
