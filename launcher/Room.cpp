/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 19/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include "Room.hpp"
Room::Room(const std::string &name, int nbPlayers) {
    this->_name = name;
    this->_nbPlayers = nbPlayers;
}

Room::~Room() {}
const std::string &Room::getName() const {
    return _name;
}
void Room::setName(const std::string &_name) {
    Room::_name = _name;
}
int Room::getNbPlayers() const {
    return _nbPlayers;
}
void Room::setNbPlayers(int _nbPlayers) {
    Room::_nbPlayers = _nbPlayers;
}
