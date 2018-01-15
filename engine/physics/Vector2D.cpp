//
// Created by Hamza Hammouche on 12/01/2018.
//

#include "Vector2D.hpp"

engine::physics::Vector2d::Vector2d(int x, int y) : _x(x), _y(y) {}

engine::physics::Vector2d::~Vector2d() {

}

int engine::physics::Vector2d::getX() const {
    return _x;
}

void engine::physics::Vector2d::setX(int x) {
    this->_x = x;
}

int engine::physics::Vector2d::getY() const {
    return _y;
}

void engine::physics::Vector2d::setY(int y) {
    this->_y = y;
}
