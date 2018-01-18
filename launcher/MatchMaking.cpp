/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include <iostream>
#include "MatchMaking.hpp"
MatchMaking::MatchMaking() {}
MatchMaking::~MatchMaking() {

}
bool MatchMaking::connect(const std::string &ip) {
    std::cout << "Connecting to " << ip << ", please wait..." << std::endl;
    return false;
}
