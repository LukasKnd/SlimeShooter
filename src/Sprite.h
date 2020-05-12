#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include "./Anim.h"

namespace sg {
    /// Sprite class
    class Sprite {

            Anim anim;
            sf::RectangleShape sprite;
            sf::Vector2f size;
            sf::Vector2f position;
            float rotation;
            bool invertX;
            bool invertY;

            void SetCorrect();

        public:
            ///DO NOT USE
            Sprite();
            ///Constructor
            Sprite(sf::Texture* texture, sf::Vector2f size = sf::Vector2f(0,0), sf::Vector2f position = sf::Vector2f(0,0), float rotation = 0.0f, int timesToRun = -1);
            ///Constructor
            Sprite(const std::vector<sf::Texture*> &animationTextures, int animationSpeed, sf::Vector2f size = sf::Vector2f(0,0), sf::Vector2f position = sf::Vector2f(0,0), float rotation = 0.0f, int timesToRun = -1);
            ///Update function
            void Update(float deltaTime);
            ///Render function
            void Render(sf::RenderTarget &target);

            //GETTERS & SETTERS
            ///Getter for Invert X axis
            ///@returns true - if sprite is inverted, false - if sprite is not inverted
            bool GetInvertX() const;
            ///Getter for Invert Y axis
            ///@returns true - if sprite is inverted, false - if sprite is not inverted
            bool GetInvertY() const;
            ///Returns center position
            sf::Vector2f GetCenter() const;
            ///Return current position
            sf::Vector2f GetPosition() const;
            ///Returns current rotation in degrees
            float GetRotation() const;
            ///Sets invert along X axis
            void SetInvertX(bool value);
            ///Sets inver along Y axis
            void SetInvertY(bool value);
            ///Sets rotation in degrees
            void SetRotation(float rotation);
            ///Sets position of the sprite
            void SetPosition(sf::Vector2f position);
            ///Returns how many times the animation of the sprite has looped
            int CurrentLoopNumber() const;
            ///Sets the size of the sprite
            void SetSize(sf::Vector2f size);
            ///Resets sprite animation
            ///Starts animation from the beggining
            ///@param timesToRun can be used to set how many time the animation should loop, after the last loop the animation freezes on last animation texture, -1 means to loop animation infinitely
            void Reset(int timesToRun = -1);

    };

}

#endif // SPRITE_H_INCLUDED
