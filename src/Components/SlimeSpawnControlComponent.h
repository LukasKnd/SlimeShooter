#ifndef SLIMESPAWNCONTROLCOMPONENT_H_INCLUDED
#define SLIMESPAWNCONTROLCOMPONENT_H_INCLUDED


#include "./ColliderComponent.h"
#include "./SlimeControlComponent.h"
#include "./DelAftAniFin.h"

namespace sg {

    class SlimeSpawnControlComponent: public Component {

            SpriteComponent* spriteComponent;
            TransformComponent* transform;
            int slimesLeftToSpawn;
            int delayBetweenSpawns;
            bool spawnAniFinished = false;
            Entity* playerEntity;
        public:

            SlimeSpawnControlComponent(const SlimeSpawnControlComponent &other) = delete;
            SlimeSpawnControlComponent& operator=(const SlimeSpawnControlComponent &other) = delete;

            SlimeSpawnControlComponent(unsigned slimesToSpawn, Entity* playerEntity);

            void Initialize();

            void Update(float deltaTime);


    };

}

#endif // SLIMESPAWNCONTROLCOMPONENT_H_INCLUDED
