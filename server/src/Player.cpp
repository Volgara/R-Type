//
// Created by Volgar on 11/01/2018.
// Contact: volgar.dev@gmail.com
//

#include "Player.hpp"

Player::Player(int fd, int id) {
    _fd = fd;
    _id = id;
    _inRoom = false;
    _roomName = "";
}

int Player::getId() const {
    return _id;
}

int Player::getFd() const {
    return _fd;
}

bool Player::getRoomStatus() const {
    return _inRoom;
}

std::string Player::getRoomName() const {
    return _roomName;
}

void Player::setRoom(std::string roomName) {
    if (!_inRoom)
    {
        _inRoom = true;
        _roomName = roomName;
    }
}
