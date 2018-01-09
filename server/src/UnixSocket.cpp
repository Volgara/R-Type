//
// Created by Volgar on 09/01/2018.
// Contact: volgar.dev@gmail.com
//

#include "UnixSocket.hpp"

RType::UnixSocket::UnixSocket(SocketType type) {
    _socketType = type;
}


RType::UnixSocket::~UnixSocket() {

}

void RType::UnixSocket::init_socket() {

}

int RType::UnixSocket::connect_socket() {
    return 0;
}

void RType::UnixSocket::blind_Socket() {

}

void RType::UnixSocket::listen_Socket() {
}

int RType::UnixSocket::get_fd() const {
    return 0;
}

