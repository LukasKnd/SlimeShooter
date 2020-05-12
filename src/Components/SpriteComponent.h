#ifndef SPRITECOMPONENT_H_INCLUDED
#define SPRITECOMPONENT_H_INCLUDED

#include "../Sprite.h"
#include "../PlayState.h"
#include "../Component.h"
#include "./TransformComponent.h"
#include <iostream>

namespace sg {

    class SpriteComponent: public Component {

            std::map<std::string, sg::Sprite> animations;
            std::string currentAnimationName;
            sg::Sprite* currentSprite;
            TransformComponent *transform;

        public:

            SpriteComponent(const SpriteComponent &other) = delete;
            SpriteComponent& operator=(const SpriteComponent &other) = delete;


            SpriteComponent(std::vector<std::vector<std::string>> animationIds, std::vector<std::string> animationNames, unsigned animationSpeed, std::string currentAnimationName, float rotation = 0.0f);

            void Initialize() override;
            void Update(float deltaTime) override;

            void Render() override;

            //GETTERS & SETTERS

            void SetAnimationName(std::string name, int timesToRun = -1);

            sg::Sprite* GetCurrentSprite();

    };

}

#endif // SPRITECOMPONENT_H_INCLUDED
