//
//-----------------------------------------------------------------------------
//Filename:    Component.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/11/18.
//-----------------------------------------------------------------------------
//

#include "Component.hpp"
#include "GameObject.hpp"

engine::core::Component::Component(engine::core::ComponentID type) : id(type) {}

void engine::core::Component::detachGameObject() {
    owner = static_cast<GameObjectID>(-1);
    ownerRef = nullptr;
}

void engine::core::Component::attachGameObject(engine::core::GameObject *object) {
    owner = object->guid;
    ownerRef = object;
}
