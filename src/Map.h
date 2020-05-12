#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED


namespace sg {

    class Map {

        private:
            std::string textureId;
            int scale;
            int tileSize;
            int numOfTilesInRow;
        public:
            Map(const std::string &textureId, int tileSize, int numOfTilesInRow);
            ~Map();

            void LoadMap(const std::string &filePath, int mapSizeX, int mapSizeY);
            void AddTile(int sourceX, int sourceY, int x, int y, bool collision);
            std::string toString();

        friend std::ostream& operator<<(std::ostream &o, const Map& m);
        friend std::istream& operator>>(std::istream &i, Map &s);


    };

    std::ostream& operator<<(std::ostream &o, const Map& m);
    std::istream& operator>>(std::istream &i, Map &s);

}









#endif // MAP_H_INCLUDED
