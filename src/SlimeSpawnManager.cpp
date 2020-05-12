#include "SlimeSpawnManager.h"
#include "./PlayState.h"
#include "./Components/TransformComponent.h"
#include "./Components/SpriteComponent.h"
#include "./Components/SlimeSpawnControlComponent.h"

using namespace sg;

class SlimeSpawnManager::Implementation {

    private:

        std::vector<sf::Vector2f> positionsAvailable;
        Entity* playerEntity;
        float lastSpawnerTime = 2.0f;
        int slimeSpeed = 25;

        friend class SlimeSpawnManager;

    public:

        Implementation(Entity *playerEntity) {
            this->playerEntity = playerEntity;
        }


};


SlimeSpawnManager::SlimeSpawnManager(Entity* playerEntity) : impl(new Implementation(playerEntity)) {

}

SlimeSpawnManager::SlimeSpawnManager(const SlimeSpawnManager& other) : impl(new Implementation(*other.impl)) {

}

SlimeSpawnManager& SlimeSpawnManager::operator=(const SlimeSpawnManager &other) {
    *this->impl = *other.impl;
    return *this;
}


SlimeSpawnManager::~SlimeSpawnManager() {
    delete impl;
}


SlimeSpawnManager& SlimeSpawnManager::operator+=(sf::Vector2f position) {

    impl->positionsAvailable.push_back(position);

    return *this;
}

void SlimeSpawnManager::CreateSpawner(int SlimesToSpawn) {

    if(impl->positionsAvailable.size() == 0)
        return;

    //select random from positions available
    int randomPos = rand() % impl->positionsAvailable.size();
    sf::Vector2f selectedPos = impl->positionsAvailable[randomPos];
    impl->positionsAvailable.erase(impl->positionsAvailable.begin() + randomPos);

    Entity& portal = PlayState::manager->AddEntity("portal", VEGETATION_LAYER);
    portal.AddComponent<TransformComponent>(selectedPos.x, selectedPos.y, 0, 0, 126, 71);
    portal.AddComponent<SpriteComponent>(
        std::vector<std::vector<std::string>> {
            {
                "portalSpawner0",
                "portalSpawner1",
                "portalSpawner2",
                "portalSpawner3",
                "portalSpawner5",
                "portalSpawner6",
                "portalSpawner7",
                "portalSpawner8",
                "portalSpawner9",
                "portalSpawner10",
                "portalSpawner11",
                "portalSpawner12",
                "portalSpawner13",
                "portalSpawner14",
                "portalSpawner15",
                "portalSpawner16",
                "portalSpawner17",
                "portalSpawner18",
                "portalSpawner19",
                "portalSpawner20",
                "portalSpawner21",
                "portalSpawner22",
            },
            {
                "portalSpawner22",
                "portalSpawner23",
                "portalSpawner24",
                "portalSpawner25",
                "portalSpawner26",
                "portalSpawner27",
                "portalSpawner28",
                "portalSpawner29",
                "portalSpawner30",
                "portalSpawner31",
            },
            {
                "portalSpawner22",
                "portalSpawner21",
                "portalSpawner20",
                "portalSpawner19",
                "portalSpawner18",
                "portalSpawner17",
                "portalSpawner16",
                "portalSpawner15",
                "portalSpawner14",
                "portalSpawner13",
                "portalSpawner12",
                "portalSpawner11",
                "portalSpawner10",
                "portalSpawner9",
                "portalSpawner8",
                "portalSpawner7",
                "portalSpawner6",
                "portalSpawner5",
                "portalSpawner4",
                "portalSpawner3",
                "portalSpawner2",
                "portalSpawner1",
                "portalSpawner0",
            }
        },
        std::vector<std::string> {
            "SPAWN",
            "SPAWNSLIME",
            "UNSPAWN"
        },
        10,
        "SPAWN"
    );
    portal.AddComponent<SlimeSpawnControlComponent>(SlimesToSpawn, impl->playerEntity);

}

void SlimeSpawnManager::addPostionAvailable(sf::Vector2f position) {
    impl->positionsAvailable.push_back(position);
}

void SlimeSpawnManager::Update(float deltaTime) {
    impl->lastSpawnerTime += deltaTime;
    if(impl->lastSpawnerTime > std::max(1.2f, 2.5f-PlayState::timeRunning/100)) {
        CreateSpawner(rand()% 4 + 3);
        impl->lastSpawnerTime = 0.0f;
    }
}


