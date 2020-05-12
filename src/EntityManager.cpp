#include "./EntityManager.h"

#include <iostream>

#include "./Components/ColliderComponent.h"
#include "./Components/DelAftAniFin.h"
#include "./Components/SlimeControlComponent.h"

using namespace sg;


EntityManager::EntityManager() {

}

void EntityManager::ClearData() {
    for(auto& entity: entities) {
        delete entity;
    }
}

bool EntityManager::HasNoEntities() const {
    return entities.size() == 0;
}

void EntityManager::Update(float deltaTime) {
    for(int i = entities.size() - 1; i >= 0; i--) {
        if(entities[i]->IsActive()) {
            entities[i]->Update(deltaTime);
        } else {
            entities[i]->DeleteAllComponents();
            entities.erase(entities.begin() + i);
        }
    }

}

void EntityManager::Render() {

    for(int layerNumber = 0; layerNumber < NUM_LAYERS; ++layerNumber) {
        for(auto& entity: GetEntitiesByLayer(static_cast<LayerType>(layerNumber))) {
            if(entity->IsActive()) {
                entity->Render();
            }
        }
    }

}

Entity& EntityManager::AddEntity(const std::string &entityName, LayerType layer) {
    Entity *entity = new Entity(*this, entityName, layer);
    entities.emplace_back(entity);
    return *entity;
}

std::vector<Entity*> EntityManager::GetEntities() const {
    return entities;
}

std::vector<Entity*> EntityManager::GetEntitiesByLayer(LayerType layer) const {
    std::vector<Entity*> selectedEntities;
    for(auto& entity: entities) {
        if(entity->layer == layer) {
            selectedEntities.emplace_back(entity);
        }
    }

    return selectedEntities;
}

unsigned int EntityManager::GetEntityCount() const {
    return entities.size();
}

void EntityManager::ListAllEntities(bool showComponents) const {
    for(auto& entity: entities) {
        std::cout << entity->name << std::endl;
        if(showComponents) {
            entity->ListAllComponents();
        }
    }
}


Entity* EntityManager::GetEntity(const std::string &entityName) {

    for(auto& entity: entities) {
        if(entity->name == entityName) {
            return entity;
        }
    }

    return NULL;

}

void EntityManager::CheckCollisions() {
    std::vector<Entity*> entitiesWithCollider = GetEntitiesWithComponent<ColliderComponent>();

    for(int i = 0; i < entitiesWithCollider.size(); i++) {
        for(int j = i+1; j < entitiesWithCollider.size(); j++) {
            ColliderComponent *col1 = entitiesWithCollider[i]->GetComponent<ColliderComponent>();
            ColliderComponent *col2 = entitiesWithCollider[j]->GetComponent<ColliderComponent>();

            if(col1->GetColliderRect().intersects(col2->GetColliderRect())) {
                if(
                    (col1->GetColliderTag() == "player" || col2->GetColliderTag() == "player") &&
                    (col1->GetColliderTag() == "Tile" || col2->GetColliderTag() == "Tile")
                   )
                {

                    Entity* player = col1->GetColliderTag() == "player" ? entitiesWithCollider[i] : entitiesWithCollider[j];
                    TransformComponent* playerTransform = player->GetComponent<TransformComponent>();
                    playerTransform->SetPosition(playerTransform->GetPrevPos());
                }
                else if(
                  (col1->GetColliderTag() == "projectile" || col2->GetColliderTag() == "projectile") &&
                  (col1->GetColliderTag() == "Tile" || col2->GetColliderTag() == "Tile")
                )
                {
                    Entity* projectile = col1->GetColliderTag() == "projectile" ? entitiesWithCollider[i] : entitiesWithCollider[j];
                    if(!projectile->HasComponent<DelAftAniFin>()) {
                        projectile->GetComponent<TransformComponent>()->SetVelocityX(0);
                        projectile->GetComponent<TransformComponent>()->SetVelocityY(0);
                        projectile->AddComponent<DelAftAniFin>("DEATH");
                    }
                }
                else if(
                  (col1->GetColliderTag() == "projectile" || col2->GetColliderTag() == "projectile") &&
                  (col1->GetColliderTag() == "slime" || col2->GetColliderTag() == "slime")
                )
                {
                    Entity* projectile = col1->GetColliderTag() == "projectile" ? entitiesWithCollider[i] : entitiesWithCollider[j];
                    Entity* slime = col1->GetColliderTag() == "slime" ? entitiesWithCollider[i] : entitiesWithCollider[j];
                    if(!projectile->HasComponent<DelAftAniFin>()) {
                        projectile->GetComponent<TransformComponent>()->SetVelocityX(0);
                        projectile->GetComponent<TransformComponent>()->SetVelocityY(0);
                        projectile->AddComponent<DelAftAniFin>("DEATH");
                    }
                    if(!slime->HasComponent<DelAftAniFin>()) {
                        slime->GetComponent<TransformComponent>()->SetVelocityX(0);
                        slime->GetComponent<TransformComponent>()->SetVelocityY(0);
                        slime->DeleteComponent<SlimeControlComponent>();
                        slime->GetComponent<ColliderComponent>()->SetWidth(0);
                        slime->GetComponent<ColliderComponent>()->SetHeight(0);
                        slime->AddComponent<DelAftAniFin>("DEATH");
                    }
                }
                else if(
                  (col1->GetColliderTag() == "player" || col2->GetColliderTag() == "player") &&
                  (col1->GetColliderTag() == "slime" || col2->GetColliderTag() == "slime")
                )
                {
                    // GAME OVER;
                    std::cout <<"GAME OVER" << std::endl;


                }
            }

        }
    }


}









