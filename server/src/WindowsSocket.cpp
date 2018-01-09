//
// Created by Volgar on 09/01/2018.
// Contact: volgar.dev@gmail.com
//

#include "../include/WindowsSocket.hpp"

RType::WindowsSocket::WindowsSocket(SocketType type) {
    _socketType = type;
}

RType::WindowsSocket::~WindowsSocket() {

}

void RType::WindowsSocket::init_socket() {

}

int RType::WindowsSocket::connect_socket() {
    return 0;
}

int RType::WindowsSocket::blind_Socket() {
    return 0;
}

int RType::WindowsSocket::listen_Socket() {
    return 0;
}

int RType::WindowsSocket::get_fd() const {
    return 0;
}
