#ifndef SLIMESPAWNMANAGER_H_INCLUDED
#define SLIMESPAWNMANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "./Entity.h"

namespace sg {

    class SlimeSpawnManager {

            class Implementation;
            Implementation *impl;

        public:

            SlimeSpawnManager(Entity* playerEntity);

            SlimeSpawnManager(const SlimeSpawnManager& other);

            SlimeSpawnManager& operator=(const SlimeSpawnManager &other);

            ~SlimeSpawnManager();

            void CreateSpawner(int SlimesToSpawn);

            void addPostionAvailable(sf::Vector2f position);

            void Update(float deltaTime);

            SlimeSpawnManager& operator+=(sf::Vector2f position);

    };

}

#endif // SLIMESPAWNMANAGER_H_INCLUDED
