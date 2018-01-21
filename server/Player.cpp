//
// Created by Volgar on 11/01/2018.
// Contact: volgar.dev@gmail.com
//

#include "Player.hpp"

RTypeServer::Player::Player(int fd, int id) {
    _fd = fd;
    _id = id;
    _inRoom = false;
    isReady = false;
    _roomName = "";
}

int RTypeServer::Player::getId() const {
    return _id;
}

int RTypeServer::Player::getFd() const {
    return _fd;
}

bool RTypeServer::Player::getRoomStatus() const {
    return _inRoom;
}

std::string RTypeServer::Player::getRoomName() const {
    return _roomName;
}



void RTypeServer::Player::setRoom(std::string roomName) {
    if (!_inRoom)
    {
        _inRoom = true;
        _roomName = roomName;
    }
}

void RTypeServer::Player::cleanRoom() {
    _inRoom = false;
    _roomName = "";
    isReady = false;
}
