#ifndef KEYBOARDCONTROLCOMPONENT_H_INCLUDED
#define KEYBOARDCONTROLCOMPONENT_H_INCLUDED

#include "../Component.h"
#include "./TransformComponent.h"
#include "./SpriteComponent.h"

namespace sg {

    class KeyboardControlComponent: public Component {
        private:
            TransformComponent *transform;
            SpriteComponent *sprite;

        public:

            KeyboardControlComponent(const KeyboardControlComponent &other) = delete;
            KeyboardControlComponent& operator=(const KeyboardControlComponent &other) = delete;

            KeyboardControlComponent();

            void Initialize() override;

            void Update(float deltaTime) override;

    };

}

#endif // KEYBOARDCONTROLCOMPONENT_H_INCLUDED
