//
//-----------------------------------------------------------------------------
//Filename:    GameObject.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/10/18.
//-----------------------------------------------------------------------------
//

#include "GameObject.hpp"

engine::core::GameObject::GameObject() = default;

engine::core::GameObject::~GameObject() = default;

engine::core::GameObjectID engine::core::GameObject::getId() const {
    return _id;
}

/**
 * Set the GameObjectID
 * @param id
 */
void engine::core::GameObject::setId(engine::core::GameObjectID id) {
    _id = id;
}

/**
 * Check one entry with Component ID
 * @param id
 * @return
 */
bool engine::core::GameObject::hasComponent(engine::core::ComponentID id) const {
    return false;
}

/**
 * Return the component with the Component ID
 * @param id the ComponentID
 * @return nullptr if not found
 */
engine::core::Component *engine::core::GameObject::getComponent(engine::core::ComponentID id) {
    return _components[id];
}

/**
 * Update each component of the GameObject
 * @param dt
 */
void engine::core::GameObject::Update(float dt) {

}

/**
 * Add a new component
 * @param id
 * @param component
 */
void engine::core::GameObject::addComponent(engine::core::ComponentID id, engine::core::Component *component) {
    _components[id] = component;
}

/**
 * Broadcast message foreach component
 * @param msg
 */
void engine::core::GameObject::SendMessage(Message *msg) {
    for (auto component : _components) {

    }
}

/**
 * Get's the GameObject state
 * @return true if active
 */
bool engine::core::GameObject::active(void) const {
    return _active;
}
