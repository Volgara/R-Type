//
// Created by Volgar on 12/01/2018.
// Contact: volgar.dev@gmail.com
//

#include <iostream>
#include "Room.hpp"

RType::Room::Room(std::string name) {
    _name = name;
}

bool RType::Room::join(Player *p) {
    if (_player.size() >= 4 || _gameStart)
        return false;
    std::cout << "[" << p->getId() << "]: " << "joined " << _name << std::endl;
    _player.push_back(p);
    return (true);
}

void RType::Room::start() {
    _gameStart = true;
    //game started
}

std::string RType::Room::getName() const {
    return _name;
}

int RType::Room::getNbrPlayer() const {
    return _player.size();
}

bool RType::Room::leave(Player *p) {
    int pos = 0;

    for (auto it : _player)
    {
        if (p->getId() == it->getId())
        {
            _player.erase(_player.begin() + pos);
            return (true);
        }
        pos += 1;
    }
    return false;
}
