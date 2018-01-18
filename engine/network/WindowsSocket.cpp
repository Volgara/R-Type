//
// Created by Volgar on 09/01/2018.
// Contact: volgar.dev@gmail.com
//

#ifdef _WIN32

#include <io.h>
#include <winsock2.h>
#include <Ws2tcpip.h>
#include <stdio.h>
#include "WindowsSocket.hpp"
#include "networkException.hpp"

engine::Network::WindowsSocket::WindowsSocket(SocketType type) {
    _socketType = type;
}


engine::Network::WindowsSocket::~WindowsSocket() {

}

void engine::Network::WindowsSocket::init_socket() {
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
        throw NetworkException("WSAStartup failed");

    // init socket
    ZeroMemory(&local, sizeof(local));
    local.ai_family = AF_INET;
    if (_socketType == Tcp)
        local.ai_socktype = SOCK_STREAM;
    else if (_socketType == Udp)
        local.ai_socktype = SOCK_DGRAM;
    local.ai_protocol = IPPROTO_TCP;
    local.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    if (getaddrinfo(NULL, "4242", &local, &result) != 0)
        throw NetworkException("getaddrinfo failed");

    // Create socket
    fd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (fd  == INVALID_SOCKET) {
        freeaddrinfo(result);
        WSACleanup();
        throw NetworkException("Socket creation failed");
    }
}

int engine::Network::WindowsSocket::connect_socket(const std::string &ip, int port) {
    struct addrinfo *result = NULL, hints;

    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
        throw NetworkException("WSAStartup error");

    ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    int iResult = getaddrinfo(ip.c_str(), std::to_string(port).c_str(), &hints, &result);
    if ( iResult != 0 ) {
        WSACleanup();
        throw NetworkException("getaddrinfo error");
    }
    fd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (fd == INVALID_SOCKET) {
            WSACleanup();
            throw NetworkException("Socket creating failed");
        }

    iResult = connect(fd, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        closesocket(fd);
        fd = INVALID_SOCKET;
        throw NetworkException("Connect failed");
    }
    return(fd);
}

void engine::Network::WindowsSocket::blind_Socket() {
    if (bind(fd, result->ai_addr, (int)result->ai_addrlen) == SOCKET_ERROR) {
        freeaddrinfo(result);
        closesocket(fd);
        WSACleanup();
        throw NetworkException("Bind failed");
    }
}

void engine::Network::WindowsSocket::listen_Socket() {
    if (_socketType == Tcp)
    {
        if (listen(fd, 100) == SOCKET_ERROR) {
            closesocket(fd);
            WSACleanup();
            throw NetworkException("listen failed");
        }
    }
}

unsigned int engine::Network::WindowsSocket::get_fd() const {
    return fd;
}

void engine::Network::WindowsSocket::Init(void) {

}

void engine::Network::WindowsSocket::onNotify(engine::core::Message message) {

}

void engine::Network::WindowsSocket::Update(float dt) {

}

void engine::Network::WindowsSocket::write_socket(std::string data) {
    send(fd, data.c_str(), strlen(data) + 1, 0);
}

std::string engine::Network::WindowsSocket::read_socket() {
    std::string res;
    char data[512];
    recv(fd, data, 512, 0);
    res = data;
    return(res);
}

#endif