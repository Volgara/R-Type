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

void engine::graphics::GraphicsComponent::SendMessage(engine::core::Message *message) {
    (void) message;
}

void engine::graphics::GraphicsComponent::Init(void) {
    //owner = static_cast<core::GameObjectID>(-1);
}

void engine::graphics::GraphicsComponent::ShutDown(void) {

}

void engine::graphics::GraphicsComponent::Update(float dt) {
    (void) dt;
}

engine::graphics::GraphicsComponent::GraphicsComponent() : Component(engine::core::ComponentID::GRA_SPRITE) {
    this->_currentAnimation = 0;
    this->_dtCounter = 0;
}

/**
 * Add an animation to the component
 * @param animation
 */
void engine::graphics::GraphicsComponent::addAnimation(engine::graphics::Animation *anim) {
    int i = 0;
    for (auto &animation : this->_animations) {
        if (animation->getName() == anim->getName()) {
            throw std::runtime_error("Cannot add two animations with the same name!");
        }
        i++;
    }
    this->_animations.push_back(anim);
}

/**
 * Start playing an animation from the begining
 * @param str Animation name
 */
void engine::graphics::GraphicsComponent::play(const std::string &str) {
    int i = 0;
    for (auto &animation : this->_animations) {
        if (animation->getName() == str) {
            this->_currentAnimation = i;
        }
        i++;
    }
    this->_sprite = _animations[this->_currentAnimation]->getFrames()[_animations[this->_currentAnimation]->getCurrenFrame()];
}

/**
 * Get the current sprite of the current animation
 * @return
 */
sf::Sprite &engine::graphics::GraphicsComponent::getDrawable() {
    auto *eg = engine::core::Engine::GetInstance();
    eg->getWindow().draw(this->_sprite);

    return this->_sprite;
}

/**
 * Update current frame of all animation
 */
void engine::graphics::GraphicsComponent::update(float dt) {
    if (_animations[this->_currentAnimation]->getCurrenFrame() >=
        _animations[this->_currentAnimation]->getFrames().size() - 1 && _dtCounter >= 1) {
        _animations[this->_currentAnimation]->setCurrentFrame(0);
        _dtCounter = 0;
    } else if (_dtCounter >= 1) {
        _dtCounter = 0;
        _animations[this->_currentAnimation]->setCurrentFrame(_animations[this->_currentAnimation]->getCurrenFrame() + 1);
    }

    this->_sprite = _animations[this->_currentAnimation]->getFrames()[_animations[this->_currentAnimation]->getCurrenFrame()];
    _dtCounter += dt * (_animations[this->_currentAnimation]->getSpeed());

    engine::core::Vector2d pos = this->ownerRef->pos;
    this->_sprite.setPosition((float) pos.getX(), (float) pos.getY());
}

const std::vector<engine::graphics::Animation *> &engine::graphics::GraphicsComponent::getAnimations() const {
    return _animations;
}

void engine::graphics::GraphicsComponent::setPosition(int x, int y) {
    this->_sprite.setPosition((float) x, (float) y);
}

int engine::graphics::GraphicsComponent::getCurrentAnimationIndex() const {
    return _currentAnimation;
}

void engine::graphics::GraphicsComponent::setCurrentAnimation(int currentAnimation) {
    GraphicsComponent::_currentAnimation = currentAnimation;
}

engine::graphics::Animation *const & engine::graphics::GraphicsComponent::getCurrentAnimation() const {
    return this->getAnimations()[_currentAnimation];
}

