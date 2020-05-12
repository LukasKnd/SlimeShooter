#ifndef ENTITYMANAGER_H_INCLUDED
#define ENTITYMANAGER_H_INCLUDED

#include <vector>
#include <string>
#include "Constants.h"
#include "./Entity.h"


namespace sg {

    class EntityManager {
        private:
            std::vector<Entity*> entities;
        public:

            EntityManager();
            EntityManager(const EntityManager &other) = delete;
            EntityManager& operator=(const EntityManager &other) = delete;

            void ClearData();
            void Update(float deltaTime);
            void Render();
            bool HasNoEntities() const;
            Entity& AddEntity(const std::string &entityName, LayerType layer);
            Entity* GetEntity(const std::string &entityName);
            std::vector<Entity*> GetEntities() const;
            std::vector<Entity*> GetEntitiesByLayer(LayerType layer) const;
            unsigned int GetEntityCount() const;
            void CheckCollisions();
            void ListAllEntities(bool showComponents) const;

            template <typename T>
            std::vector<Entity*> GetEntitiesWithComponent() const{
                std::vector<Entity*> entitiesWithComponent;
                for(auto& entity: entities) {
                    if(entity->HasComponent<T>())
                        entitiesWithComponent.emplace_back(entity);
                }
                return entitiesWithComponent;
            }

    };

}

#endif // ENTITYMANAGER_H_INCLUDED
