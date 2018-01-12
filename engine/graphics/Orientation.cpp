/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 12/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include "Orientation.hpp"

RType::Orientation::Orientation() {}

RType::Orientation::~Orientation() {

}

int RType::Orientation::getAngle() const {
    return angle;
}

void RType::Orientation::setAngle(int angle) {
    Orientation::angle = angle;
}
