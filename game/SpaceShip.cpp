//
// Created by Hamza Hammouche on 20/01/2018.
//

#include "SpaceShip.hpp"

game::SpaceShip::SpaceShip(int _life, int _damage, int _shield) : _life(_life), _damage(_damage), _shield(_shield) {}

int game::SpaceShip::getLife() const {
    return _life;
}

int game::SpaceShip::getDamage() const {
    return _damage;
}

int game::SpaceShip::getShield() const {
    return _shield;
}

void game::SpaceShip::takeDamage(int damage) {
    this->_life -= damage - this->_shield;
}
