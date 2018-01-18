//
//-----------------------------------------------------------------------------
//Filename:    Scene.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/15/18.
//-----------------------------------------------------------------------------
//

#ifdef GRAPHICS
#include <graphics/GraphicsComponent.hpp>
#endif

#include <physics/RigidBodyComponent.hpp>
#include "Scene.hpp"
#include "GameObject.hpp"
#include "../../game/BulletComponent.hpp"

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
        case BULLET:
            component = new game::BulletComponent();
            break;
        default:
            throw  std::runtime_error("Replace by Class based factory");
    }
    handlesComponents[type].push_back(component);
    return component;
}

void engine::core::Scene::RemoveComponent(engine::core::Component *c) {
    (void) c;
}

void engine::core::Scene::RemoveComponent(engine::core::GameObjectID handle) {
    (void) handle;
}

engine::core::GameObject *engine::core::Scene::CreateEmptyObject(void) {
    auto *go = new engine::core::GameObject;
    go->guid = guid++;
    return go;
}

void engine::core::Scene::RemoveGameObject(engine::core::GameObject *o) {
    (void) o;
}

void engine::core::Scene::RemoveGameObject(engine::core::GameObjectID handle) {
    (void) handle;
}

engine::core::Component *
engine::core::Scene::GetComponent(engine::core::ComponentID type, engine::core::GameObjectID owner) {
    return objectsMap[owner]->GetComponent(type);
}