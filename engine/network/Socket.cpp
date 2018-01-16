//
// Created by Volgar on 08/01/2018.
// Contact: volgar.dev@gmail.com
//

#include "network/Socket.hpp"
#include "network/WindowsSocket.hpp"
#include "network/UnixSocket.hpp"

RType::Socket::Socket() {
    _socket = NULL;
#ifdef _WIN32
    std::cout << "Running on windows" << std::endl;
    _socket = (ISocket *) new WindowsSocket();
#endif

#ifdef linux
    std::cout << "Running on linux" << std::endl;
    _socket = (ISocket *) new UnixSocket();
#endif

#ifdef __APPLE__
    std::cout << "Runnin on Macos" << std::endl;
    std::cout << "Socket on macos not implemented yet" << std::endl;
#endif

    if (_socket == NULL)
        std::cout << "Socket type error" << std::endl;
    else
        std::cout << "Socket created" << std::endl;


}

RType::Socket::~Socket() {

}

void RType::Socket::init_socket() {
    _socket->init_socket();
}

int RType::Socket::connect_socket() {
    return (_socket->connect_socket());
}

int RType::Socket::blind_Socket() {
    return (_socket->blind_Socket());
}

int RType::Socket::listen_Socket() {
    return (_socket->listen_Socket());
}

int RType::Socket::get_fd() const {
    return (_socket->get_fd());
}
