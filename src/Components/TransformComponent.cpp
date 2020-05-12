#include "./TransformComponent.h"

using namespace sg;

TransformComponent::TransformComponent(int posX, int posY, int velX, int velY, unsigned w, unsigned h) {
    position = sf::Vector2f(posX, posY);
    prevPos = position;
    velocity = sf::Vector2f(velX, velY);
    width = w;
    height = h;
}

void TransformComponent::Initialize() {

}

void TransformComponent::Update(float deltaTime) {
    prevPos = position;
    position.x += velocity.x * deltaTime;
    position.y += velocity.y * deltaTime;
}

//GETTERS & SETTERS

sf::Vector2f TransformComponent::GetPosition() {
    return position;
}

sf::Vector2f TransformComponent::GetPrevPos() {
    return prevPos;
}

sf::Vector2f TransformComponent::GetCenter() {
    return sf::Vector2f(position.x + width/2, position.y + height/2);
}

int TransformComponent::GetWidth() {
    return width;
}

int TransformComponent::GetHeight() {
    return height;
}

void TransformComponent::SetPosition(sf::Vector2f position) {
    this->position = position;
}

void TransformComponent::SetPrevPos(sf::Vector2f position) {
    this->prevPos = position;
}

void TransformComponent::SetVelocityX(float xVelocity) {
    velocity.x = xVelocity;
}

void TransformComponent::SetVelocityY(float yVelocity) {
    velocity.y = yVelocity;
}

sf::Vector2f TransformComponent::GetVelocity() {
    return velocity;
}
