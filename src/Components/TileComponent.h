#ifndef TILECOMPONENT_H_INCLUDED
#define TILECOMPONENT_H_INCLUDED

#include "../Component.h"
#include <SFML/Graphics.hpp>
#include "../PlayState.h"

namespace sg {

    class TileComponent: public Component {
        private:

            sf::Texture *texture;
            sf::IntRect textureRect;
            sf::Vector2f position;
            sf::Sprite sprite;

        public:

            TileComponent(const TileComponent &other) = delete;
            TileComponent& operator=(const TileComponent &other) = delete;

            TileComponent(unsigned sourceRectX, unsigned sourceRectY, int x, int y, unsigned tileSize, std::string assetTextureId);

            ~TileComponent();

            void Initialize() override;

            void Render() override;

    };

}

#endif // TILECOMPONENT_H_INCLUDED
