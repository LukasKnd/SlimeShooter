

#include "./GunComponent.h"

using namespace sg;

GunComponent::GunComponent(std::string textureId, int posRelX, int posRelY, int barrelPosRelX, int barrelPosRelY, unsigned w, unsigned h, float shootDelay) {

    sprite = Sprite(PlayState::assetManager->GetTexture(textureId));
    posRelativeToTransform = sf::Vector2f(posRelX, posRelY);
    barrelPosRel = sf::Vector2f(barrelPosRelX, barrelPosRelY);
    sprite.SetSize(sf::Vector2f(w, h));
    this->shootDelay = shootDelay;
    this->timeSinceLastShot = shootDelay;
}

void GunComponent::Initialize() {

    if(!owner->HasComponent<TransformComponent>()) {
        throw std::logic_error("TransformComponent not found");
    }

    if(!owner->HasComponent<SpriteComponent>()) {
        throw std::logic_error("SpriteComponent not found");
    }

    transform = owner->GetComponent<TransformComponent>();
    spriteComponent = owner->GetComponent<SpriteComponent>();
}

void GunComponent::Update(float deltaTime) {

    timeSinceLastShot += deltaTime;

    sprite.SetPosition(sf::Vector2f(posRelativeToTransform + sf::Vector2f(transform->GetPosition().x, transform->GetPosition().y)));

    sf::Vector2i pixelPos = sf::Mouse::getPosition(*PlayState::window);
    sf::Vector2f worldPos = PlayState::window->mapPixelToCoords(pixelPos);

    float rotation = (atan2((float)sprite.GetCenter().y - worldPos.y, (float)sprite.GetCenter().x - worldPos.x)) * 180 / 3.141f + 180.0f;

    sf::Transform transfrm;
    transfrm.rotate(rotation, sprite.GetCenter().x, sprite.GetCenter().y);

    barrelPos = transfrm.transformPoint(sf::Vector2f(sprite.GetCenter().x + barrelPosRel.x, sprite.GetCenter().y + barrelPosRel.y));

    //std::cout << rotation << std::endl;
    if(rotation > 90 && rotation < 270) {
        spriteComponent->GetCurrentSprite()->SetInvertX(true);
        sprite.SetInvertY(true);
    } else {
        spriteComponent->GetCurrentSprite()->SetInvertX(false);
        sprite.SetInvertY(false);
    }

    sprite.SetRotation(rotation);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        Shoot(rotation, 150);
    }


}

void GunComponent::Render() {
    sprite.Render(*PlayState::window);
    #ifdef DEBUG
    sf::RectangleShape t(sf::Vector2f(2,2));
    t.setPosition(barrelPos);
    PlayState::window->draw(t);
    #endif // DEBUG
}

void GunComponent::Shoot(float rotation, float bulletSpeed) {
    if(timeSinceLastShot <= shootDelay) {
        return;
    }

    Entity& bullet = PlayState::manager->AddEntity("projectile", PROJECTILE_LAYER);

    int velX = bulletSpeed * cos(rotation*3.14/180.0f);
    int velY = bulletSpeed * sin(rotation*3.14/180.0f);

    bullet.AddComponent<TransformComponent>(barrelPos.x - 7, barrelPos.y - 7, velX, velY, 15, 15);

    bullet.AddComponent<SpriteComponent>(
        std::vector<std::vector<std::string>> {
            {
                "projectile",
            },
            {
                "projectileOnHit0",
                "projectileOnHit1",
                "projectileOnHit2",
            }
        },
        std::vector<std::string> {
            "PROJECTILE",
            "DEATH"
        },
        10,
        "PROJECTILE",
        rotation
    );
    bullet.AddComponent<ColliderComponent>("projectile", 4, 4, 7, 7);

    Entity& muzzleFlash = PlayState::manager->AddEntity("muzzleFlash", PROJECTILE_LAYER);
    muzzleFlash.AddComponent<TransformComponent>(barrelPos.x - 12, barrelPos.y - 12, 0, 0, 24, 24);
    muzzleFlash.AddComponent<SpriteComponent>(
        std::vector<std::vector<std::string>> {
            {
                "muzzleFlash",
            }
        },
        std::vector<std::string> {
            "MUZZLEFLASH",
        },
        50,
        "MUZZLEFLASH"
    );
    muzzleFlash.AddComponent<DelAftAniFin>("MUZZLEFLASH");

    timeSinceLastShot = 0.0f;
}

