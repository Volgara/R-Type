/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include <iostream>
#include <WinSock2.h>
#include "Connection.hpp"
#include "../engine/network/networkException.hpp"

Connection::Connection() {
    sok = new engine::Network::Socket(engine::Network::Tcp);

}

Connection::~Connection() {
}

bool Connection::connect(const std::string &ip, int port) {
    this->_ip = ip;
    this->_port = port;

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
    std::cout << "Joining " << str << " room." << std::endl;
    sok->write_socket("join " + str);
    std::string res = sok->read_socket();
    return res;
}

void Connection::addRoomFound(const std::string &name, int nbPlayers) {
    std::cout << "Adding room: " << name << ", " << nbPlayers << std::endl;
    Room r(name, nbPlayers);
    this->_roomsFound.push_back(r);
}

void Connection::emptyRoomsFound() {
    this->_roomsFound.clear();
}

std::vector<Room> Connection::getRoomsFound() {
    return this->_roomsFound;
}

std::string Connection::SetReady() {
    std::cout << "You are ready" << std::endl;
    sok->write_socket("start");

    struct pollfd *poll_fd;
    char buffer[256];
    poll_fd = (pollfd *) malloc(sizeof(struct pollfd) * 1);
    poll_fd[0].fd = sok->get_fd();
    poll_fd[0].events = POLLIN | POLLOUT;

    WSAPoll(poll_fd, 1, 500);
    if (poll_fd[0].revents & POLLIN)
        recv(this->sok->get_fd(), buffer, 256, 0);

    std::string res = sok->read_socket();
    return res;
}

std::string Connection::getPlayerNumber() {
    std::cout << "Requesting number of players in the current room" << std::endl;
    sok->write_socket("roominfo");
    std::string res = sok->read_socket();
    return res;
}
