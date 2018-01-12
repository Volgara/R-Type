/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 12/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include "Position.hpp"

RType::Position::Position() {
    this->x = 0;
    this->y = 0;
}

RType::Position::~Position() {

}

RType::Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
}
