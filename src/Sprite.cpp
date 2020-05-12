
#include "./Sprite.h"

using namespace sg;

Sprite::Sprite() {

}

Sprite::Sprite(sf::Texture* texture, sf::Vector2f, sf::Vector2f position, float rotation, int timesToRun) : Sprite(std::vector<sf::Texture*>(1, texture), 0, size, position, rotation, timesToRun) {

}

Sprite::Sprite(const std::vector<sf::Texture*> &animationTextures, int animationSpeed, sf::Vector2f size, sf::Vector2f position, float rotation, int timesToRun) : anim(animationTextures, animationSpeed, timesToRun) {
    this->rotation = rotation;
    this->invertX = false;
    this->invertY = false;
    this->size = size;
    this->position = position;

    SetCorrect();
    Update(0.0f);

}

void Sprite::Update(float deltaTime) {
    anim.Update(deltaTime);
    sprite.setTexture(anim.GetCurrentTexture());
}

void Sprite::Render(sf::RenderTarget &target) {
    target.draw(sprite);
}

void Sprite::SetCorrect() {
    sprite.setSize(size);
    sprite.setOrigin(size.x/2, size.y/2);
    if(invertX) {
        sprite.setScale(sf::Vector2f(-1.0f, 1.0f));
    } else if(invertY) {
        sprite.setScale(sf::Vector2f(1.0f, -1.0f));
    } else {
        sprite.setScale(1.0f, 1.0f);
    }
    sprite.setPosition(position + sf::Vector2f(size.x/2, size.y/2));
    sprite.setRotation(rotation);
}

//GETTERS & SETTERS

bool Sprite::GetInvertX() const {
    return invertX;
}

bool Sprite::GetInvertY() const {
    return invertY;
}

sf::Vector2f Sprite::GetCenter() const {
    return position + sf::Vector2f(size.x/2, size.y/2);
}

sf::Vector2f Sprite::GetPosition() const {
    return position;
}

float Sprite::GetRotation() const {
    return rotation;
}

void Sprite::SetInvertX(bool value) {
    this->invertX = value;
    SetCorrect();
}

void Sprite::SetInvertY(bool value) {
    this->invertY = value;
    SetCorrect();
}

void Sprite::SetRotation(float rotation) {
    this->rotation = rotation;
    SetCorrect();
}

void Sprite::SetPosition(sf::Vector2f position) {
    this->position = position;
    SetCorrect();
}

int Sprite::CurrentLoopNumber() const {
    return anim.CurrentLoopNumber();
}

void Sprite::SetSize(sf::Vector2f size) {
    this->size = size;
    SetCorrect();
}

void Sprite::Reset(int timesToRun) {
    anim.Reset(timesToRun);
}
