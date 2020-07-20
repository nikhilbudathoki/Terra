#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include <string>
#include <vector>

#include "Component.h"
#include "EntityManager.h"

class EntityManager;
class Component;

class Entity {
   private:
    EntityManager& manager;
    bool isActive;
    std::vector<Component*> components;

   public:
    std::string name;
    Entity(EntityManager& manager);
    Entity(EntityManager& manager, std::string name);
    void Update(float deltaTime);
    void Render();
    void Destroy();
    bool IsActive() const;
    std::vector<Component*> getComponents();

    template <typename T, typename... TArgs>
    T& AddComponent(TArgs&&... args) {
        T* newComponent(new T(std::forward<TArgs>(args)...));
        newComponent->owner = this;
        components.emplace_back(newComponent);
        newComponent->Initialize();
        return *newComponent;
    }
};


#endif
