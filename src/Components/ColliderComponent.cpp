
#include "./ColliderComponent.h"
#include "../Entity.h"

using namespace sg;

ColliderComponent::ColliderComponent(std::string colliderTag, int posX, int posY, unsigned w, unsigned h, bool posRelToTransform) {

    this->colliderTag = colliderTag;
    this->posY = posY;
    this->posX = posX;
    this->w = w;
    this->h = h;
    this->posRelToTransform = posRelToTransform;
}

void ColliderComponent::Initialize() {
    if(posRelToTransform) {

        if(!owner->HasComponent<TransformComponent>()) {
            throw std::logic_error("TransformComponent not found");
        }

        transform = owner->GetComponent<TransformComponent>();
        colliderRect.left = transform->GetPosition().x + posX;
        colliderRect.top = transform->GetPosition().y + posY;
    } else {
        colliderRect.left = posX;
        colliderRect.top = posY;
    }
    colliderRect.width = w;
    colliderRect.height = h;
}

void ColliderComponent::Update(float deltaTime) {
    if(posRelToTransform) {
        colliderRect.left = transform->GetPosition().x + posX;
        colliderRect.top = transform->GetPosition().y + posY;
    }
}

void ColliderComponent::Render() {
    #ifdef DEBUG
    sf::RectangleShape t(sf::Vector2f(w, h));
    t.setPosition(colliderRect.left, colliderRect.top);
    t.setTexture(PlayState::assetManager->GetTexture("collision-texture"));
    PlayState::window->draw(t);
    #endif // DEBUG
}

//GETTERS & SETTERS

sf::FloatRect ColliderComponent::GetColliderRect() {
    return colliderRect;
}

std::string ColliderComponent::GetColliderTag() {
    return colliderTag;
}

void ColliderComponent::SetWidth(int width) {
    w = width;
    colliderRect.width = w;
}

void ColliderComponent::SetHeight(int height) {
    h = height;
    colliderRect.height = h;
}





