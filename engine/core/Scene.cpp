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
#include "Scene.hpp"
#include "GameObject.hpp"
#include "Component.hpp"

engine::core::Component *engine::core::Scene::CreateComponent(engine::core::ComponentID type) {
    // TODO : Replace by Class based factory
    Component *component;
    switch (type) {
        case GRA_SPRITE:
#ifdef GRAPHICS
            component = new graphics::GraphicsComponent();
#else
            throw  std::runtime_error("Replace by Class based factory");
#endif
            break;
        case PHY_RIGIDBODY:
            throw  std::runtime_error("Replace by Class based factory");
            break;
    }
    handlesComponents[type].push_back(component);
    return component;
}

void engine::core::Scene::RemoveComponent(engine::core::Component *) {

}

void engine::core::Scene::RemoveComponent(engine::core::GameObjectID) {

}

engine::core::GameObject *engine::core::Scene::CreateEmptyObject() {
    return nullptr;
}

void engine::core::Scene::RemoveGameObject(engine::core::GameObject *) {

}

void engine::core::Scene::RemoveGameObject(engine::core::GameObjectID) {

}

engine::core::Component *
engine::core::Scene::GetComponent(engine::core::ComponentID type, engine::core::GameObjectID owner) {
    return objectsMap[owner]->GetComponent(type);
}
