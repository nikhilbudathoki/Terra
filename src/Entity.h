#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <vector>

#include "Component.h"
#include "Constants.h"
#include "EntityManager.h"

class EntityManager;
class Component;

class Entity {
   private:
    EntityManager& manager;
    bool isActive;
    std::vector<Component*> components;
    std::map<const std::type_info*, Component*> componentTypeMap;

   public:
    std::string name;
    LayerType layer;
    Entity(EntityManager& manager);
    Entity(EntityManager& manager, std::string name, LayerType layer);
    void Update(float deltaTime);
    void Render();
    void Destroy();
    bool IsActive() const;
    void ListAllComponents() const;

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
    T* GetComponent() {
        return static_cast<T*>(componentTypeMap[&typeid(T)]);
    }

    template <typename T>
    bool HasComponent() const {
        if (componentTypeMap.find(&typeid(T)) == componentTypeMap.end()) {
            return false;
        }
        return true;
    }
};

#endif
