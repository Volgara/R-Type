//
// Created by Volgar on 08/01/2018.
// Contact: volgar.dev@gmail.com
//

#include "Socket.hpp"
#include "WindowsSocket.hpp"
#include "UnixSocket.hpp"

RType::Socket::Socket(SocketType type) {
    _socket = NULL;
#ifdef _WIN32
    std::cout << "Running on windows" << std::endl;
    _socket = (ISocket *) new WindowsSocket(type);
#endif

#ifdef linux
    std::cout << "Running on linux" << std::endl;
    _socket = (ISocket *) new UnixSocket(type);
#endif

#ifdef __APPLE__
    std::cout << "Runnin on Macos" << std::endl;
    _socket = (ISocket *) new UnixSocket(type);
#endif
}

RType::Socket::~Socket() {

}

void RType::Socket::init_socket() {
    _socket->init_socket();
}

int RType::Socket::connect_socket() {
    return (_socket->connect_socket());
}

void RType::Socket::blind_Socket() {
    _socket->blind_Socket();
}

void RType::Socket::listen_Socket() {
    _socket->listen_Socket();
}

unsigned int RType::Socket::get_fd() const {
    return (_socket->get_fd());
}
