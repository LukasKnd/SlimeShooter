#ifndef TRANSFORMCOMPONENT_H_INCLUDED
#define TRANSFORMCOMPONENT_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "../Component.h"

namespace sg {

    class TransformComponent: public Component {

        private:
            sf::Vector2f prevPos;
            sf::Vector2f position;
            sf::Vector2f velocity;
            int width;
            int height;

        public:

            TransformComponent(const TransformComponent &other) = delete;
            TransformComponent& operator=(const TransformComponent &other) = delete;

            TransformComponent(int posX, int posY, int velX, int velY, unsigned w, unsigned h);

            void Initialize() override;

            void Update(float deltaTime) override;

            //GETTERS & SETTERS

            sf::Vector2f GetPosition();

            sf::Vector2f GetPrevPos();

            sf::Vector2f GetCenter();

            int GetWidth();

            int GetHeight();

            void SetPosition(sf::Vector2f position);

            void SetPrevPos(sf::Vector2f position);

            void SetVelocityX(float xVelocity);

            void SetVelocityY(float yVelocity);

            sf::Vector2f GetVelocity();

    };

}

#endif // TRANSFORMCOMPONENT_H_INCLUDED
