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
