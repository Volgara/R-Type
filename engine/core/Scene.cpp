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
#include <input/InputComponent.hpp>
#include "Scene.hpp"
#include "GameObject.hpp"
#include "projectile/BulletComponent.hpp"
#include "../../game/PlayerComponent.hpp"
#include "../network/NetworkComponent.hpp"


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
        case INPUT_GENERATE:
#ifdef GRAPHICS
            component = new engine::input::InputComponent();
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
        case GAME_PLAYER:
            component = new game::PlayerComponent();
            break;
        case NET:
            component = new engine::network::NetworkComponent();
            break;
        default:
            throw  std::runtime_error("Replace by Class based factory");
    }
    handlesComponents[type].push_back(component);
    components.push_back(component);
    return component;
}

void engine::core::Scene::RemoveComponent(engine::core::Component *c) {
    if (handlesComponents[c->id].size() == 0)
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
    Component *temp = nullptr;
    std::remove_if(components.begin(), components.end(), [&temp](Component *component) {
        if (component->ownerRef == nullptr) {
            temp = component;
            return true;
        }
        return false;
    });

    if (temp != nullptr) {
        RemoveComponent(temp);
        //delete(temp);
    }
}

engine::core::GameObject *engine::core::Scene::GetGameObject(engine::core::GameObjectID owner) {
    return this->objectsMap[owner];
}
