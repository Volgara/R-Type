/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include <iostream>
#include "Connection.hpp"
#include "../engine/network/Socket.hpp"
#include "../engine/network/networkException.hpp"

Connection::Connection(const std::string &ip, int port) {
    std::cout << "Registering Connection to " << ip << ":" << port << std::endl;

    this->_ip   = ip;
    this->_port = port;
    sok = new engine::Network::Socket(engine::Network::Tcp);

}
Connection::~Connection() {
}

bool Connection::connect() {
    std::cout << "Connecting to " << this->_ip << ":" << this->_port << std::endl;
    try {
        sok->connect_socket(this->_ip, this->_port);
        std::cout << "Success!" << std::endl;
        return true;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return false;
    }
}
std::string Connection::getList() {
    sok->write_socket("list");
    std::string res = sok->read_socket();
    return res;
}

std::string Connection::createAndJoin(const std::string &str) {
    sok->write_socket("join " + str);
    std::string res = sok->read_socket();
    return res;
}
