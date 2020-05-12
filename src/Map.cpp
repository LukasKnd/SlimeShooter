#include <fstream>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <sstream>

#include "./Map.h"


//extern EntityManager manager;
#include "./Entity.h"
#include "./PlayState.h"
#include "./Components/TileComponent.h"
#include "./Components/ColliderComponent.h"

using namespace sg;

Map::Map(const std::string &textureId, int tileSize, int numOfTilesInRow) {
    this->textureId = textureId;
    this->tileSize = tileSize;
    this->numOfTilesInRow = numOfTilesInRow;
}

Map::~Map() {

}

void Map::LoadMap(const std::string &filePath, int mapSizeX, int mapSizeY) {
    std::fstream mapFile;
    mapFile.open(filePath);


    std::string collisionString = filePath;
    collisionString.insert(collisionString.size() - 4, "C");
    std::fstream colMap;
    colMap.open(collisionString);

    for(int y = 0; y < mapSizeY; ++y) {
        for(int x = 0; x < mapSizeX; ++x) {
            int ch;
            mapFile >> ch;

            #ifdef DEBUG
            std::cout << ch;
            #endif // DEBUG

            ch -= 1;

            int sourceRectY = (ch / numOfTilesInRow) * tileSize;
            int sourceRectX = (ch % numOfTilesInRow) * tileSize;

            int col = 0;
            colMap >> col;

            #ifdef DEBUG
            std::cout << "(" << col << ") ";
            #endif // DEBUG

            AddTile(sourceRectX, sourceRectY, x * tileSize, y * tileSize, col);

            mapFile.ignore();
            colMap.ignore();
        }
        #ifdef DEBUG
        std::cout << std::endl;
        #endif // DEBUG
    }
    mapFile.close();

}

void Map::AddTile(int sourceRectX, int sourceRectY, int x, int y, bool collision) {
    Entity& newTile = PlayState::manager->AddEntity("Tile", TILEMAP_LAYER);
    newTile.AddComponent<TileComponent>(sourceRectX, sourceRectY, x, y, tileSize, textureId);
    if(collision) {
        newTile.AddComponent<ColliderComponent>("Tile", x, y, tileSize, tileSize, false);
    }
}

std::string Map::toString() {
    std::stringstream ss;
    ss << textureId << " " << tileSize << " " << numOfTilesInRow;

    return ss.str();
}


std::ostream& sg::operator<<(std::ostream &o, const Map& m) {
    o << m.textureId << " " << m.tileSize << " " << m.numOfTilesInRow;
    return o;
}

std::istream& sg::operator>>(std::istream &i, Map &s) {
    std::string textureId;
    int tileSize;
    int numOfTilesInRow;
    {
        i >> textureId;
        i >> tileSize;
        i >> numOfTilesInRow;

        if(i.fail()) {
            i.clear();
            i.ignore(256, '\n');
            throw std::ios_base::failure("Input error");
        }
    }
    s.textureId = textureId;
    s.tileSize = tileSize;
    s.numOfTilesInRow = numOfTilesInRow;
    return i;
}






