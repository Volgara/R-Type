#include <iostream>

#include "network/Socket.hpp"

int main() {
    RType::Socket *socket = new RType::Socket();

    socket->init_socket();
    socket->connect_socket();
    socket->blind_Socket();
    socket->get_fd();
    return(0);
}