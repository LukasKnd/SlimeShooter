#ifndef SLIMECONTROLCOMPONENT_H_INCLUDED
#define SLIMECONTROLCOMPONENT_H_INCLUDED

#include "../Component.h"
#include "./TransformComponent.h"
#include "../Entity.h"

namespace sg {

    class SlimeControlComponent: public Component {
        private:

            TransformComponent* playerTransform;
            TransformComponent* transform;
            int speed;
            float lastUpdate;


        public:

            SlimeControlComponent(const SlimeControlComponent &other) = delete;
            SlimeControlComponent& operator=(const SlimeControlComponent &other) = delete;

            SlimeControlComponent(Entity* player, unsigned speed);

            void Initialize() override;

            void Update(float deltaTime) override;



    };

}

#endif // SLIMECONTROLCOMPONENT_H_INCLUDED
