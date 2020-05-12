#include <iostream>
#include "./Entity.h"
#include "./Component.h"

using namespace sg;

Entity::Entity(EntityManager& manager) : manager(manager) {
    this->isActive = true;
}

Entity::Entity(EntityManager& manager, const std::string name, LayerType layer) : manager(manager), name(name), layer(layer) {
    this->isActive = true;
}

Entity::~Entity() {
    DeleteAllComponents();
}

void Entity::Update(float deltaTime) {
    for(auto& component: components) {
        component->Update(deltaTime);
    }


}

void Entity::Render() {
    for(auto& component: components) {
        component->Render();
    }
}

void Entity::Destroy() {
    this->isActive = false;
}

bool Entity::IsActive() const {
    return this->isActive;
}

void Entity::DeleteAllComponents() {
    for(auto& component: components) {
        delete component;
    }
}

void Entity::ListAllComponents() const {
    for(auto& p: componentTypeMap) {
        std::cout << "   " << p.first->name() << std::endl;
    }
}

