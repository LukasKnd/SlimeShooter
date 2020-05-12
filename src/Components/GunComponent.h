#ifndef GUNCOMPONENT_H_INCLUDED
#define GUNCOMPONENT_H_INCLUDED

#include "./ColliderComponent.h"
#include "./DelAftAniFin.h"

namespace sg {

    class GunComponent: public Component {
        private:
            TransformComponent* transform;
            SpriteComponent* spriteComponent;
            sf::Vector2f posRelativeToTransform;
            sf::Vector2f barrelPosRel;
            sf::Vector2f barrelPos;
            float shootDelay;
            float timeSinceLastShot;
            sg::Sprite sprite;


        public:

            GunComponent(const GunComponent &other) = delete;
            GunComponent& operator=(const GunComponent &other) = delete;


            GunComponent(std::string textureId, int posRelX, int posRelY, int barrelPosRelX, int barrelPosRelY, unsigned w, unsigned h, float shootDelay);

            void Initialize() override;

            void Update(float deltaTime) override;

            void Render() override;

            void Shoot(float rotation, float bulletSpeed);

    };

}

#endif // GUNCOMPONENT_H_INCLUDED

