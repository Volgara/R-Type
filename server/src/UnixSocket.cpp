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
    if (_socketType == Tcp)
        fd = socket(AF_INET, SOCK_STREAM, 0);
    else if (_socketType == Udp)
        fd =  socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (fd < 0) {
        std::cout << "Socket creation failed" << std::endl;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(4243);
}

int RType::UnixSocket::connect_socket() {
    return 0;
}

void RType::UnixSocket::blind_Socket() {
    if (bind(fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << "Bind failed" << std::endl;
    }
}

void RType::UnixSocket::listen_Socket() {
    if (_socketType == Tcp)
    {
        if (listen(fd, 10) != 0)
            std::cout << "Liston failed" << std::endl;
    }
}

int RType::UnixSocket::get_fd() const {
    return fd;
}