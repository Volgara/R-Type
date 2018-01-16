//
// Created by Hamza Hammouche on 13/01/2018.
//

#include <iostream>
#include "Box.hpp"

engine::physics::Box::Box(engine::core::Vector2d position, engine::core::Vector2d size)
{
    this->_top = position.getY();
    this->_left = position.getX();
    this->_right = position.getX() + size.getX();
    this->_bottom = position.getY() + size.getY();
}

void engine::physics::Box::updatePosition(const engine::core::Vector2d &position,
                                          const engine::core::Vector2d &size) {
    this->_top = position.getY();
    this->_left = position.getX();
    this->_right = position.getX() + size.getX();
    this->_bottom = position.getY() + size.getY();
}

bool engine::physics::Box::intersectBox(Box *box){
    return !(box->getLeft() > this->_right
            || box->getRight() < this->_left
            || box->getTop() > this->_bottom
            || box->getBottom() < this->_top);
}

int engine::physics::Box::getLeft() const {
    return _left;
}

int engine::physics::Box::getRight() const {
    return _right;
}

int engine::physics::Box::getTop() const {
    return _top;
}

int engine::physics::Box::getBottom() const {
    return _bottom;
}
