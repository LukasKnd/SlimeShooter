
#include "./Anim.h"

using namespace sg;

Anim::Anim() {
}

Anim::Anim(const std::vector<sf::Texture*> &textures, unsigned animSpeed, int timesToRun) {

    if(textures.size() == 0) {
        throw std::logic_error("no textures found");
    }

    if(timesToRun < -1) {
        throw std::logic_error("cannot run animation negative times");
    }

    this->timesToRun = timesToRun;

    this->animSpeed = animSpeed;
    timeRunning = 0.0f;

    this->textures = textures;

    currentTexture = textures[0];

}

sf::Texture* Anim::GetCurrentTexture() const {
    return currentTexture;
}

void Anim::Update(float deltaTime) {
    timeRunning += deltaTime;
    if(timesToRun == -1 || CurrentLoopNumber() < timesToRun) {
        currentTexture = textures[static_cast<int>(timeRunning * animSpeed) % textures.size()];
    }

}

int Anim::CurrentLoopNumber() const{
    return static_cast<int>(timeRunning * animSpeed) / textures.size();
}

void Anim::Reset(int timesToRun) {
    this->timesToRun = timesToRun;
    timeRunning = 0.0f;
    currentTexture = textures[0];
}
