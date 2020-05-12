#include "./SlimeControlComponent.h"

using namespace sg;

SlimeControlComponent::SlimeControlComponent(Entity* player, unsigned speed) {
    if(player == NULL) {
        throw std::logic_error("Entity* player == NULL");
    }

    this->speed = (int)speed;

    if(!player->HasComponent<TransformComponent>()) {
        throw std::logic_error("player TransformComponent not found");
    }

    playerTransform = player->GetComponent<TransformComponent>();
    this->lastUpdate = 0.0f;
}

void SlimeControlComponent::Initialize() {

    if(!owner->HasComponent<TransformComponent>()) {
        throw std::logic_error("TransformComponent not found");
    }

    transform = owner->GetComponent<TransformComponent>();
}

void SlimeControlComponent::Update(float deltaTime) {
    lastUpdate += deltaTime;

    if(lastUpdate > 0.25f) {
        sf::Vector2f playerCenter = playerTransform->GetCenter();
        sf::Vector2f position = transform->GetPosition();

        float d = sqrt(pow(playerCenter.x - position.x, 2) + pow(playerCenter.y - position.y, 2));
        int velX = speed/d * (playerCenter.x - position.x) + (rand() % speed - speed/2) ;
        int velY = speed/d * (playerCenter.y - position.y) + (rand() % speed - speed/2) ;

        transform->SetVelocityX(velX);
        transform->SetVelocityY(velY);

        lastUpdate = 0.0f;
    }
}

