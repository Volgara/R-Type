/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 12/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include "Animation.hpp"
#include "SpriteSheet.hpp"

engine::graphics::Animation::Animation(const std::string &name, engine::graphics::SpriteSheet *sheet) {
    this->_name = name;
    this->_loop = false;
    this->_currenFrame = 0;
    this->_reverse = false;
    this->_spriteSheet = sheet;
    this->_speed = 1;
}

engine::graphics::Animation::Animation(const engine::graphics::Animation &anim) {
    this->_reverse = anim._reverse;
    this->_name = anim._name;
    this->_spriteSheet = anim._spriteSheet;
    this->_frames = anim._frames;
    this->_currenFrame = anim._currenFrame;
    this->_loop = anim._loop;
    this->_reverse = anim._reverse;
    this->_speed = anim._speed;
}

void engine::graphics::Animation::setAnimationFrames(int, int) {

}

void engine::graphics::Animation::addFrame(int x, int y) {
    sf::Sprite sprite;
    sprite.setTexture(*this->_spriteSheet->getTexture());
    sprite.setTextureRect(sf::IntRect(y * this->_spriteSheet->getFrameWidth(), x * this->_spriteSheet->getFrameHeight(),
                                      this->_spriteSheet->getFrameWidth(), this->_spriteSheet->getFrameHeight()));

    this->_frames.push_back(sprite);
}

const std::string &engine::graphics::Animation::getName() const {
    return _name;
}

sf::Sprite engine::graphics::Animation::getCurrentSprite() {
    std::cout << "Frames available: " << this->_frames.size() << std::endl;
    std::cout << "Current frame : " << _currenFrame << std::endl;
    return this->_frames[_currenFrame];
}

int engine::graphics::Animation::getCurrenFrameIndex() const {
    return _currenFrame;
}

void engine::graphics::Animation::setCurrentFrameIndex(int currenFrame) {
    Animation::_currenFrame = currenFrame;
}

void engine::graphics::Animation::setLoop(bool loop) {
    this->_loop = loop;
}

void engine::graphics::Animation::setReverse(bool reverse) {
    this->_reverse = reverse;
}

const engine::graphics::SpriteSheet *engine::graphics::Animation::getSpriteSheet() const {
    return _spriteSheet;
}

const std::vector<sf::Sprite> &engine::graphics::Animation::getFrames() const {
    return _frames;
}

void engine::graphics::Animation::setPingPong(bool pingpong) {
    this->_pingPong = pingpong;
}

void engine::graphics::Animation::setSpeed(int speed) {
    this->_speed = speed;
}

int engine::graphics::Animation::getSpeed() const {
    return _speed;
}

sf::Sprite engine::graphics::Animation::getCurrenFrame() const {
    return this->getFrames()[this->getCurrenFrameIndex()];
}
bool engine::graphics::Animation::isReverse() {
    return this->_reverse;
}
bool engine::graphics::Animation::isPingPong() {
    return this->_pingPong;
}

bool engine::graphics::Animation::isLoop() {
    return this->_loop;
}
