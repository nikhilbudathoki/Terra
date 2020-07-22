#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <iostream>
#include <vector>

#include "Component.h"
#include "Entity.h"

class EntityManager {
   private:
    std::vector<Entity*> entities;

   public:
    void ClearData();
    void Update(float deltaTime);
    void Render();
    bool HasNoEntities();
    Entity& AddEntity(std::string entityName, LayerType layer);
    std::vector<Entity*> GetEntities() const;
    std::vector<Entity*> GetEntitiesByLayer(LayerType layer) const;
    unsigned int GetEntityCount();
    void ListAllEntities() const;
};

#endif
