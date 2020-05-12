#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <map>
#include <typeinfo>
#include <vector>
#include "Constants.h"

namespace sg {

    class Component;
    class EntityManager;

    class Entity {
        private:
            EntityManager& manager;
            bool isActive;
            std::vector<Component*> components;
            std::map<const std::type_info*, Component*> componentTypeMap;
        public:

            Entity(const Entity &other) = delete;
            Entity& operator=(const Entity &other) = delete;

            std::string name;
            LayerType layer;
            Entity(EntityManager& manager);
            Entity(EntityManager& manager, const std::string name, LayerType layer);
            ~Entity();
            void Update(float deltaTime);
            void Render();
            void Destroy();
            bool IsActive() const;
            void DeleteAllComponents();
            void ListAllComponents() const;

            template <typename T>
            void DeleteComponent() {
                auto it = componentTypeMap.find(&typeid(T));
                for(int i = components.size() - 1; i >= 0; i--) {
                    if((*it).second == components[i]) {
                        components.erase(components.begin() + i);
                        break;
                    }
                }
                componentTypeMap.erase(it);
            }

            template <typename T, typename... TArgs>
            T& AddComponent(TArgs&&... args) {
                T* newComponent(new T(std::forward<TArgs>(args)...));
                newComponent->owner = this;
                components.emplace_back(newComponent);
                componentTypeMap[&typeid(*newComponent)] = newComponent;
                newComponent->Initialize();
                return *newComponent;
            }

            template <typename T>
            bool HasComponent() const {
                return componentTypeMap.count(&typeid(T));
            }

            template <typename T>
            T* GetComponent() {
                return static_cast<T*>(componentTypeMap[&typeid(T)]);
            }


    };

}

#endif // ENTITY_H_INCLUDED
