/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include <iostream>
#include "Connection.hpp"
#include "../engine/network/Socket.hpp"

MatchMaking::MatchMaking() {}
MatchMaking::~MatchMaking() {

}
bool MatchMaking::connect(const std::string &ip, int port) {
    std::cout << "Connecting to " << ip << ":" << port << ", please wait..." << std::endl;

    engine::Network::Socket *sok = new engine::Network::Socket(engine::Network::Tcp);

    sok->connect_socket(ip, port);
    sok->write_socket("join room1");
    std::string res = sok->read_socket();
    std::cout << "RES: " << res << std::endl;
    sok->write_socket("list");
    res = sok->read_socket();
    std::cout << "RES: " << res << std::endl;
    return false;
}
