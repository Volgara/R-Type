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
    this->currentAnimation = 0;
}

void engine::graphics::GraphicsComponent::addAnimation(engine::graphics::Animation *animation) {
    this->_animations.push_back(animation);
}

/**
 * Start playing an animation from the begining
 * @param str Animation name
 */
void engine::graphics::GraphicsComponent::play(const std::string &str) {
    int i = 0;
    for (auto &animation : this->_animations) {
        if (animation->getName() == str) {
            this->currentAnimation = i;
        }
        i++;
    }
    _animations[this->currentAnimation]->setCurrentFrame(0);

    this->_sprite = _animations[this->currentAnimation]->getFrames()[_animations[this->currentAnimation]->getCurrenFrame()];

    std::cout << "play: " <<_animations[0]->getFrames()[0].getTexture() << std::endl;
}

sf::Sprite &engine::graphics::GraphicsComponent::getDrawable() {
    auto *eg = engine::core::Engine::GetInstance();
    eg->getWindow().draw(this->_sprite);

    return this->_sprite;
}

/**
 * Update current frame of all animation
 */
void engine::graphics::GraphicsComponent::update(float dt) {
    if (_animations[this->currentAnimation]->getCurrenFrame() >=
        _animations[this->currentAnimation]->getFrames().size() - 1)
        _animations[this->currentAnimation]->setCurrentFrame(0);
    else
        _animations[this->currentAnimation]->setCurrentFrame(_animations[this->currentAnimation]->getCurrenFrame() + (dt / 30));

    this->_sprite = _animations[this->currentAnimation]->getFrames()[_animations[this->currentAnimation]->getCurrenFrame()];

    std::cout << "update: " << _animations[0]->getFrames()[0].getTexture() << std::endl;


/*    engine::core::Vector2d pos = this->ownerRef->pos;
    this->_sprite.setPosition(pos.getX(), pos.getY());*/
}

const std::vector<engine::graphics::Animation *> &engine::graphics::GraphicsComponent::getAnimations() const {
    return _animations;
}

void engine::graphics::GraphicsComponent::setPosition(int x, int y) {
    this->_sprite.setPosition(x, y);
}

