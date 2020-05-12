#include "./AssetManager.h"

using namespace sg;

AssetManager::AssetManager() {
}

AssetManager::~AssetManager() {
    ClearData();
}

void AssetManager::ClearData() {
    textures.clear();
}

void AssetManager::AddTexture(const std::string &textureId, const std::string &filePath) {
    auto& texture = textures[textureId];
    texture.loadFromFile(filePath);
}

sf::Texture* AssetManager::GetTexture(const std::string &textureId) {
    if(textures.find(textureId) == textures.end()) {
        throw std::logic_error("textureId not found");
    }

    return &textures[textureId];
}
