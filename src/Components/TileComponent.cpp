#include "./TileComponent.h"

using namespace sg;

TileComponent::TileComponent(unsigned sourceRectX, unsigned sourceRectY, int x, int y, unsigned tileSize, std::string assetTextureId) {
    texture = PlayState::assetManager->GetTexture(assetTextureId);

    textureRect.left = sourceRectX;
    textureRect.top = sourceRectY;
    textureRect.width = tileSize;
    textureRect.height = tileSize;

    position.x = x;
    position.y = y;


}

TileComponent::~TileComponent() {

}

void TileComponent::Initialize() {
    sprite.setTextureRect(textureRect);
    sprite.setPosition(position);
    sprite.setTexture(*texture);
}

void TileComponent::Render() {
    PlayState::window->draw(sprite);
}
