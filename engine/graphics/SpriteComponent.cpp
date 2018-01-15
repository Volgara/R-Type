//
//-----------------------------------------------------------------------------
//Filename:    SpriteComponent.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/15/18.
//-----------------------------------------------------------------------------
//

#include <core/Engine.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "SpriteComponent.hpp"

void engine::graphics::SpriteComponent::SendMessage(Message *message) {

}

void engine::graphics::SpriteComponent::Init(void) {

}

void engine::graphics::SpriteComponent::ShutDown(void) {

}

bool engine::graphics::SpriteComponent::Active(void) const {
    return core::Component::Active();
}

int engine::graphics::SpriteComponent::getX() const {
    return _x;
}

int engine::graphics::SpriteComponent::getY() const {
    return _y;
}

void engine::graphics::SpriteComponent::Update(float dt) {

}

void engine::graphics::SpriteComponent::setX(int _x) {
    SpriteComponent::_x = _x;
}

void engine::graphics::SpriteComponent::setY(int _y) {
    SpriteComponent::_y = _y;
}