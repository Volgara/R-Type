//
// Created by Volgar on 11/01/2018.
// Contact: volgar.dev@gmail.com
//

#include "Player.hpp"

Player::Player(int fd, int id) {
    _fd = fd;
    _id = id;
}

int Player::getId() const {
    return _id;
}

int Player::getFd() const {
    return _fd;
}
