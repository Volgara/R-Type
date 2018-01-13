//
// Created by Hamza Hammouche on 12/01/2018.
//

#include "Vector2D.hpp"

engine::physics::Vector2d::Vector2d(int x, int y) : x(x), y(y) {}

engine::physics::Vector2d::~Vector2d() {

}

int engine::physics::Vector2d::getX() const {
    return x;
}

void engine::physics::Vector2d::setX(int x) {
    Vector2d::x = x;
}

int engine::physics::Vector2d::getY() const {
    return y;
}

void engine::physics::Vector2d::setY(int y) {
    Vector2d::y = y;
}
