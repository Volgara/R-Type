//
// Created by Hamza Hammouche on 20/01/2018.
//

#include "SpaceShip.hpp"

game::SpaceShip::SpaceShip(int _life, int _damage, int speed, const engine::core::Vector2d &size) : _life(_life), _damage(_damage), _speed(speed), _size(size) {}

int game::SpaceShip::getLife() const {
    return _life;
}

int game::SpaceShip::getDamage() const {
    return _damage;
}

const engine::core::Vector2d &game::SpaceShip::getSize() const {
    return _size;
}

void game::SpaceShip::takeDamage(int damage) {
    this->_life -= damage;
}

int game::SpaceShip::getSpeed() const {
    return _speed;
}
