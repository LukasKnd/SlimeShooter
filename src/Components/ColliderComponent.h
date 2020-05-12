#ifndef COLLIDERCOMPONENT_H_INCLUDED
#define COLLIDERCOMPONENT_H_INCLUDED

#include "../Component.h"
#include "./TransformComponent.h"
#include "../Entity.h"

namespace sg {

    class ColliderComponent: public Component {

        private:
            TransformComponent *transform;
            std::string colliderTag;
            sf::FloatRect colliderRect;
            int posX;
            int posY;
            unsigned w;
            unsigned h;
            bool posRelToTransform;

        public:

            ColliderComponent(const ColliderComponent &other) = delete;
            ColliderComponent& operator=(const ColliderComponent &other) = delete;

            ColliderComponent(std::string colliderTag, int posX, int posY, unsigned w, unsigned h, bool posRelToTransform = true);

            void Initialize() override;

            void Update(float deltaTime) override;

            void Render() override;

            //GETTERS & SETTERS

            sf::FloatRect GetColliderRect();

            std::string GetColliderTag();

            void SetWidth(int width);

            void SetHeight(int height);

    };

}

#endif // COLLIDERCOMPONENT_H_INCLUDED
