//
//-----------------------------------------------------------------------------
//Filename:    Scene.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/15/18.
//-----------------------------------------------------------------------------
//

#include <graphics/SpriteComponent.hpp>
#include "Scene.hpp"
#include "GameObject.hpp"
#include "Component.hpp"

engine::core::Component *engine::core::Scene::CreateComponent(engine::core::ComponentID type) {
    // TODO : Replace by Class based factory
    Component *component;
    switch (type) {

        case GRA_SPRITE:
            component = new graphics::SpriteComponent();
            break;
        case PHY_RIGIDBODY:
            throw  std::runtime_error("Replace by Class based factory");
            break;
    }
    handlesComponents[type].push_back(component);
    return component;
}

void engine::core::Scene::RemoveComponent(engine::core::Component *c) {

}

void engine::core::Scene::RemoveComponent(engine::core::GameObjectID handle) {

}

engine::core::GameObject *engine::core::Scene::CreateEmptyObject(void) {

}

void engine::core::Scene::RemoveGameObject(engine::core::GameObject *o) {

}

void engine::core::Scene::RemoveGameObject(engine::core::GameObjectID handle) {

}

engine::core::Component *
engine::core::Scene::GetComponent(engine::core::ComponentID type, engine::core::GameObjectID owner) {
    return objectsMap[owner]->GetComponent(type);
}
