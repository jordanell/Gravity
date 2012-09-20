/*
 * This is the implementation file for the MapLoader class.
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#include "MapLoader.h"

using namespace framework;

namespace gravity
{

    MapLoader::MapLoader(Game* game)
    {
        this->game = game;
    }

    float MapLoader::StringToNumber(const string &Text)
    {
        stringstream ss(Text);
        float result;
        return ss >> result ? result : 0;
    }

    // Loading methods

    TileMap* MapLoader::LoadMap(const std::string &fileName, Scene* scene)
    {
        // Get the path to the map to load
        string file = GetCurrentDir(game->Content->RootDirectory, sizeof (game->Content->RootDirectory));
        file += "/../content/";
        file += fileName;
        const char* RealFileName = file.c_str();

        // Try and load the XML file here
        TiXmlDocument doc(RealFileName);
        bool loadOkay = doc.LoadFile();
        if (loadOkay)
            return ParseMap(&doc, scene);
        else
        {
            cout << "Failed to load map\n";
            return NULL;
        }
    }

    TileMap* MapLoader::ParseMap(TiXmlNode* parent, Scene* scene)
    {
        if (!parent)
            return NULL;

        TiXmlNode* childNode;
        TiXmlNode* layerNode;

        // Get all of the map elements.
        for (childNode = parent->FirstChild(); childNode != 0; childNode = childNode->NextSibling())
        {
            string value = childNode->Value();
            // Go into the map
            if (!value.compare("TileMap"))
                childNode = childNode->FirstChild();
                // Find the layers XML node
            else if (!value.compare("Layers"))
            {
                layerNode = childNode;
                break;
            }
        }

        TileMap* map = new TileMap(game, scene);

        // Now parse the layers in the layers node
        map = ParseLayers(map, layerNode);

        return map;
    }

    TileMap* MapLoader::ParseLayers(TileMap* map, TiXmlNode* parent)
    {
        if (!parent)
            return NULL;

        TiXmlNode* childNode;

        /* Temporary variables for the layers*/
        string temp;

        // Get all of the layer elements.
        for (childNode = parent->FirstChild(); childNode != 0; childNode = childNode->NextSibling())
        {
            string value = childNode->Value();
            // Add any new layer to the map
            if (!value.compare("TileLayer"))
            {
                map->AddTileLayer();
                TileLayer* LayerAdded = map->LastAddedLayer();
                ParseLayer(map, LayerAdded, childNode);
            }
        }

        return map;
    }

    void MapLoader::ParseLayer(TileMap* map, TileLayer* layer, TiXmlNode* parent)
    {
        TiXmlNode* childNode;

        // Get all of the layer's elements.
        for (childNode = parent->FirstChild(); childNode != 0; childNode = childNode->NextSibling())
        {
            string value = childNode->Value();
            if (!value.compare("Tiles"))
            {
                TiXmlNode* tile = childNode->FirstChild();
                for (tile; tile != 0; tile = tile->NextSibling())
                {
                    ParseTile(layer, tile);
                }
            } else if (!value.compare("ScrollSpeed"))
            {
                TiXmlNode* scrollspeed = childNode->FirstChild();
                // Get the X
                value = scrollspeed->ToElement()->GetText();
                float x = StringToNumber(value);
                // Get the Y
                scrollspeed = scrollspeed->NextSibling();
                value = scrollspeed->ToElement()->GetText();
                float y = StringToNumber(value);

                layer->ScrollSpeed = Vector2(x, y);
            }
        }

    }

    void MapLoader::ParseTile(TileLayer* layer, TiXmlNode* parent)
    {
        TiXmlNode* childNode;
        
        // Temp variables for tile creation
        Vector2 Position;
        Vector2 Scale;
        float Rotation;
        Color TintColor = Color();
        bool Physics;
        Texture2D* Texture;

        // Get all of the tile's elements.
        for (childNode = parent->FirstChild(); childNode != 0; childNode = childNode->NextSibling())
        {
            string value = childNode->Value();
            if(!value.compare("Position"))
            {
                TiXmlNode* position = childNode->FirstChild();
                // Get the X
                value = position->ToElement()->GetText();
                int x = StringToNumber(value);
                // Get the Y
                position = position->NextSibling();
                value = position->ToElement()->GetText();
                int y = StringToNumber(value);
                
                Position = Vector2(x,y);
            }
            else if(!value.compare("Scale"))
            {
                TiXmlNode* scale = childNode->FirstChild();
                // Get the X
                value = scale->ToElement()->GetText();
                float x = StringToNumber(value);
                // Get the Y
                scale = scale->NextSibling();
                value = scale->ToElement()->GetText();
                float y = StringToNumber(value);
                
                Scale = Vector2(x,y);
            }
            else if(!value.compare("Rotation"))
            {
                value = childNode->ToElement()->GetText();
                Rotation = StringToNumber(value);
            }
            else if(!value.compare("Physics"))
            {
                value = childNode->ToElement()->GetText();
                if(!value.compare("false"))
                    Physics = false;
                else
                    Physics = true;
            }
            else if (!value.compare("TintColor"))
            {
                TiXmlNode* color = childNode->FirstChild();
                value = color->ToElement()->GetText();
                TintColor.Red = StringToNumber(value);
                color = color->NextSibling();
                value = color->ToElement()->GetText();
                TintColor.Green = StringToNumber(value);
                color = color->NextSibling();
                value = color->ToElement()->GetText();
                TintColor.Blue = StringToNumber(value);
                color = color->NextSibling();
                value = color->ToElement()->GetText();
                TintColor.Alpha = StringToNumber(value);
            } 
            else if (!value.compare("texture_filename"))
            {
                string name = childNode->ToElement()->GetText();
                name = replaceAll(name, "\\", "/");
                Texture = game->Content->LoadTexture(name);
            }
        }
        
        // Create the new tile
        Tile* tile = new Tile(this->game, layer, Texture, Position, Scale, Rotation, TintColor, Physics);

        // Add the tile to the layer
        layer->AddTile(tile);
    }

    string MapLoader::replaceAll(string str, string from, string to)
    {
        if (from.empty())
            return str;
        size_t start_pos = 0;
        while ((start_pos = str.find(from, start_pos)) != std::string::npos)
        {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
        }
        
        return str;
    }


}
