#include <iostream>

#include "Socket.hpp"

int main() {
    RType::Socket *socket = new RType::Socket(RType::SocketType::Tcp);

    socket->init_socket();
    socket->connect_socket();
    socket->blind_Socket();
    std::cout << "Sokcet fd: " << socket->get_fd() << std::endl;
    delete socket;
    return(0);
}