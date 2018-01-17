//
// Created by Hamza Hammouche on 13/01/2018.
//

#include <iostream>
#include "Box.hpp"

engine::physics::Box::Box(engine::core::Vector2d *position, engine::core::Vector2d *size)
{
    this->_pos = position;
    this->_size = size;
}

bool engine::physics::Box::intersectBox(Box *box){
    return !(box->getLeft() > this->getRight()
            || box->getRight() < this->getLeft()
            || box->getTop() > this->getBottom()
            || box->getBottom() < this->getTop());
}

int engine::physics::Box::getLeft() const {
    return this->_pos->getX();
}

int engine::physics::Box::getRight() const {
    return this->_pos->getX() + this->_size->getX();
}

int engine::physics::Box::getTop() const {
    return this->_pos->getY();
}

int engine::physics::Box::getBottom() const {
    return this->_pos->getY() + this->_size->getY();
}
