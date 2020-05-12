#include "./SlimeSpawnControlComponent.h"
#include <algorithm>

using namespace sg;

SlimeSpawnControlComponent::SlimeSpawnControlComponent(unsigned slimesToSpawn, Entity* playerEntity) {
    this->slimesLeftToSpawn = slimesToSpawn;
    this->delayBetweenSpawns = delayBetweenSpawns;

    if(playerEntity == NULL) {
        throw std::logic_error("playerEntity == NULL");
    }

    this->playerEntity = playerEntity;
}

void SlimeSpawnControlComponent::Initialize() {

    if(!owner->HasComponent<TransformComponent>()) {
        throw std::logic_error("TransformComponent not found");
    }

    if(!owner->HasComponent<SpriteComponent>()) {
        throw std::logic_error("SpriteComponent not found");
    }

    spriteComponent = owner->GetComponent<SpriteComponent>();
    transform = owner->GetComponent<TransformComponent>();
    spriteComponent->SetAnimationName("SPAWN", 1);
}

void SlimeSpawnControlComponent::Update(float deltaTime) {
    if(spawnAniFinished) {
        if(slimesLeftToSpawn > 0) {
            if(spriteComponent->GetCurrentSprite()->CurrentLoopNumber() >= 1) {
                //ADD NEW SLIME
                Entity& slime = PlayState::manager->AddEntity("slime", ENEMIES_LAYER);
                slime.AddComponent<TransformComponent>(transform->GetPosition().x + 50, transform->GetPosition().y + 34, 0, 0, 26, 26);
                slime.AddComponent<SpriteComponent>(
                    std::vector<std::vector<std::string>> {
                        {
                            "slime_move0",
                            "slime_move1",
                            "slime_move2",
                            "slime_move3",
                            "slime_move4",
                            "slime_move5"
                        },
                        {
                            "slime_death0",
                            "slime_death1",
                            "slime_death2",
                            "slime_death3",
                            "slime_death4",
                            "slime_death5",
                            "slime_death6",
                            "slime_death7",
                            "slime_death8",
                            "slime_death9",
                            "slime_death10",
                            "slime_death11",
                            "slime_death12",

                        }
                    },
                    std::vector<std::string> {
                        "MOVE",
                        "DEATH"
                    },
                    10,
                    "MOVE"
                );
                slime.AddComponent<ColliderComponent>("slime", 6, 9, 13, 10);
                slime.AddComponent<SlimeControlComponent>(playerEntity, 25);

                slimesLeftToSpawn--;
                if(slimesLeftToSpawn != 0) {
                    spriteComponent->SetAnimationName("SPAWNSLIME", 1);
                }
            }

        } else {
            if(owner->HasComponent<DelAftAniFin>() == false) {
                sf::Vector2f pos = transform->GetPosition();
                owner->AddComponent<DelAftAniFin>("UNSPAWN", [pos]()->void{
                    PlayState::slimeSpwnManager->addPostionAvailable(pos);
                });
            }
        }

    } else {
        if(spriteComponent->GetCurrentSprite()->CurrentLoopNumber() >= 1) {
            spawnAniFinished = true;
            //TODO:
            //add collider component?

            spriteComponent->SetAnimationName("SPAWNSLIME", 1);
        }
    }

}
