#ifndef ASSETMANAGER_H_INCLUDED
#define ASSETMANAGER_H_INCLUDED

#include "./EntityManager.h"
#include <SFML/Graphics.hpp>

namespace sg {

    class AssetManager {
        private:
            std::map<std::string, sf::Texture> textures;
        public:
            AssetManager();
            ~AssetManager();
            void ClearData();
            void AddTexture(const std::string &textureId, const std::string &filePath);
            sf::Texture* GetTexture(const std::string &textureId);
    };

}

#endif // ASSETMANAGER_H_INCLUDED
