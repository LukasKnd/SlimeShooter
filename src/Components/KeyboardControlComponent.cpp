#include "./KeyboardControlComponent.h"

using namespace sg;

KeyboardControlComponent::KeyboardControlComponent() {

}

void KeyboardControlComponent::Initialize() {

    if(!owner->HasComponent<TransformComponent>()) {
        throw std::logic_error("TransformComponent not found");
    }

    if(!owner->HasComponent<SpriteComponent>()) {
        throw std::logic_error("SpriteComponent not found");
    }

    transform = owner->GetComponent<TransformComponent>();
    sprite = owner->GetComponent<SpriteComponent>();
}

void KeyboardControlComponent::Update(float deltaTime) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        transform->SetVelocityX(50);

    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        transform->SetVelocityX(-50);
    } else {
        transform->SetVelocityX(0);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        transform->SetVelocityY(-50);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        transform->SetVelocityY(50);
    } else {
        transform->SetVelocityY(0);
    }

    if(transform->GetVelocity().x == 0 && transform->GetVelocity().y == 0) {
        sprite->SetAnimationName("IDLE");
    } else {
        sprite->SetAnimationName("RUN");
    }

}
