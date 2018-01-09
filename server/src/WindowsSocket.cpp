//
// Created by Volgar on 09/01/2018.
// Contact: volgar.dev@gmail.com
//

#ifdef _WIN32

#include "WindowsSocket.hpp"

RType::WindowsSocket::WindowsSocket(SocketType type) {
    _socketType = type;
}

RType::WindowsSocket::~WindowsSocket() {

}

void RType::WindowsSocket::init_socket() {
    int wsaret = WSAStartup(0x101, &wsaData);
    if (wsaret != 0)
        std::cout << "WSAStartup failed" << std::endl;
    local.sin_family = AF_INET;
    local.sin_addr.s_addr = INADDR_ANY;
    local.sin_port = htons(4242);

    if (_socketType == Tcp)
        fd = socket(AF_INET, SOCK_STREAM, 0);
    else if (_socketType == Udp)
        fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd == INVALID_SOCKET)
        std::cout << "Socket creation failed" << std::endl;
}

int RType::WindowsSocket::connect_socket() {
    return 0;
}

void RType::WindowsSocket::blind_Socket() {
    if (bind(fd,(sockaddr*)&local, sizeof(local)) != 0)
        std::cout << "Bind failed" << std::endl;
}

void RType::WindowsSocket::listen_Socket() {
    if (_socketType == Tcp)
    {
        if (listen(fd, 10) != 0)
            std::cout << "Liston failed" << std::endl;
    }
}

int RType::WindowsSocket::get_fd() const {
    return fd;
}

#endif