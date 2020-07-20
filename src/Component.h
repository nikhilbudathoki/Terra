#ifndef COMPONENT_H
#define COMPONENT_H

class Entity;

class Component {
   private:
    /* data */
   public:
    Entity* owner;
    virtual ~Component() {}
    virtual void Initialize() {}
    virtual void Update(float deltaTime) {}
    virtual void Render() {}
};

Component::Component(/* args */) {
}

Component::~Component() {
}

#endif