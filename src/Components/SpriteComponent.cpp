
#include "./SpriteComponent.h"

using namespace sg;

SpriteComponent::SpriteComponent(std::vector<std::vector<std::string>> animationIds, std::vector<std::string> animationNames, unsigned animationSpeed, std::string currentAnimationName, float rotation) {

    if(animationIds.size() != animationNames.size()) {
        throw std::logic_error("animationIds.size() != animationNames.size()");
    }

    for(int i = 0; i < animationIds.size(); i++) {
        std::vector<sf::Texture*> textures;
        for(int j = 0; j < animationIds[i].size(); j++) {
            textures.emplace_back(PlayState::assetManager->GetTexture(animationIds[i][j]));
        }
        Sprite spr(textures, animationSpeed);
        spr.SetRotation(rotation);
        animations.emplace(animationNames[i], spr);
    }
    this->currentAnimationName = currentAnimationName;
}

void SpriteComponent::Initialize() {

    if(!owner->HasComponent<TransformComponent>()) {
        throw std::logic_error("TransformComponent not found");
    }

    transform = owner->GetComponent<TransformComponent>();

    for(auto& p : animations) {
        p.second.SetSize(sf::Vector2f(transform->GetWidth(), transform->GetHeight()));
    }
    currentSprite = &(*animations.begin()).second;
}

void SpriteComponent::Update(float deltaTime) {

    auto it = animations.find(currentAnimationName);
    if(it == animations.end()) {
        throw std::logic_error("animation not found");
    }
    currentSprite = &it->second;
    currentSprite->Update(deltaTime);
    currentSprite->SetPosition(transform->GetPosition());

    //std::cout << currentSprite->CurrentLoopNumber() << std::endl;
}

void SpriteComponent::Render() {
    currentSprite->Render(*PlayState::window);
}

//GETTERS & SETTERS

void SpriteComponent::SetAnimationName(std::string name, int timesToRun) {
    currentAnimationName = name;
    auto it = animations.find(currentAnimationName);
    if(it == animations.end()) {
        throw std::logic_error("animation not found");
    }

    if(timesToRun != -1) {
        animations[currentAnimationName].Reset(timesToRun);
    }

}

Sprite* SpriteComponent::GetCurrentSprite() {
    return currentSprite;
}
