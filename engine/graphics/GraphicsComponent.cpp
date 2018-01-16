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
#include <core/GameObject.hpp>
#include <iostream>
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

void engine::graphics::GraphicsComponent::addAnimation(engine::graphics::Animation *animation) {
    this->_animations.push_back(*animation);
}

/**
 * Start playing an animation from the begining
 * @param str Animation name
 */
void engine::graphics::GraphicsComponent::play(std::string str) {
    for (auto &animation : this->_animations) {
        if (animation.getName() == str)
        {
            animation.setCurrentFrame(0);
            this->_sprite = animation.getCurrentSprite();
        }
    }
}

sf::Sprite engine::graphics::GraphicsComponent::getDrawable() {
    return this->_sprite;
}

/**
 * Update current frame of all animation
 * TODO check for animation that overflow
 */
void engine::graphics::GraphicsComponent::update() {
    for (auto &animation : _animations) {
        animation.setCurrentFrame(animation.getCurrenFrame() + 1);
        this->_sprite = animation.getCurrentSprite();
    }

    engine::core::Vector2d pos = this->ownerRef->pos;
    this->_sprite.setPosition(pos.getX(), pos.getY());
}

const std::vector<engine::graphics::Animation> &engine::graphics::GraphicsComponent::getAnimations() const {
    return _animations;
}

