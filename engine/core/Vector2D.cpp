//
// Created by Hamza Hammouche on 12/01/2018.
//

#include "Vector2D.hpp"

engine::core::Vector2d::Vector2d(int x, int y) : _x(x), _y(y) {}

engine::core::Vector2d::~Vector2d() {

}

int engine::core::Vector2d::getX() const {
    return _x;
}

void engine::core::Vector2d::setX(int x) {
    this->_x = x;
}

int engine::core::Vector2d::getY() const {
    return _y;
}

void engine::core::Vector2d::setY(int y) {
    this->_y = y;
}
