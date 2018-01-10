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

unsigned int engine::core::GameObject::getId() const {
    return _id;
}

void engine::core::GameObject::setId(unsigned int id) {
    _id = id;
}
