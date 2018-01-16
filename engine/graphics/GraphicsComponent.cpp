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
#include "GraphicsComponent.hpp"

void engine::graphics::GraphicsComponent::SendMessage(Message *message) {
    (void) message;
}

void engine::graphics::GraphicsComponent::Init(void) {

}

void engine::graphics::GraphicsComponent::ShutDown(void) {

}

void engine::graphics::GraphicsComponent::Update(float dt) {
    (void) dt;
}

engine::graphics::GraphicsComponent::GraphicsComponent() : Component(engine::core::ComponentID::GRA_SPRITE) {

}

void engine::graphics::GraphicsComponent::addAnimation(engine::graphics::Animation animation) {
    (void) animation;
}

void engine::graphics::GraphicsComponent::play(std::string str, bool b) {
    (void) str;
    (void) b;
}
