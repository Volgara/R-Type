//
//-----------------------------------------------------------------------------
//Filename:    AScene.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/15/18.
//-----------------------------------------------------------------------------
//

#ifdef GRAPHICS
#include <graphics/GraphicsComponent.hpp>
#endif

#include <physics/RigidBodyComponent.hpp>
#include <algorithm>
#include <cassert>
#include "Scene.hpp"
#include "GameObject.hpp"
#include "projectile/BulletComponent.hpp"
#include "Component.hpp"

engine::core::Component *engine::core::Scene::CreateComponent(engine::core::ComponentID type) {
    // TODO : Replace by Class based factory
    Component *component;
    switch (type) {
        case GRA_SPRITE:
#ifdef GRAPHICS
            component = new engine::graphics::GraphicsComponent();
#else
            throw  std::runtime_error("Replace by Class based factory");
#endif
            break;
        case PHY_RIGIDBODY:
            component = new engine::physics::RigidBodyComponent();
            break;
        case PRO_BULLET:
            component = new engine::projectile::BulletComponent();
            break;
        default:
            throw  std::runtime_error("Replace by Class based factory");
    }
    handlesComponents[type].push_back(component);
    components.push_back(component);
    return component;
}

void engine::core::Scene::RemoveComponent(engine::core::Component *c) {
    if (handlesComponents->size() == 0)
        return;
    for (auto it = handlesComponents[c->id].begin(); it != handlesComponents[c->id].end(); ++it) {
        if (*it == c) {
            handlesComponents[c->id].erase(it);
            break;
        }
    }
}

engine::core::GameObject *engine::core::Scene::CreateEmptyObject(void) {
    auto *go = new engine::core::GameObject;
    go->guid = guid++;
    go->detachComponents();
    objectsMap[go->guid] = go;
    return go;
}

void engine::core::Scene::RemoveGameObject(engine::core::GameObject *o) {
    // TODO : make improvement object management
    auto *go = objectsMap[o->guid];
    assert(o->guid == go->guid);
    go->detachComponents();
    objectsMap.erase(go->guid);
    delete(go);
}

void engine::core::Scene::RemoveGameObject(engine::core::GameObjectID handle) {
    // TODO: replace the throw exception
    if (objectsMap.find(handle) == objectsMap.end())
        throw std::exception();
    RemoveGameObject(objectsMap[handle]);
}

engine::core::Component *
engine::core::Scene::GetComponent(engine::core::ComponentID type, engine::core::GameObjectID owner) {
    return objectsMap[owner]->GetComponent(type);
}

/**
 * Clean detached component
 */
void engine::core::Scene::cleanUp() {
    /*
    for (auto it = components.begin(); it != components.end(); it++) {
        Component *component = *it;

        if (component == nullptr)
            continue;

        RemoveComponent(component);

        if (component->owner == static_cast<unsigned int>(-1)) {
            // component detached
            components.erase(it);
            delete component;
        }
    }
     */
}
