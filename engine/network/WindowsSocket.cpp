//
// Created by Volgar on 09/01/2018.
// Contact: volgar.dev@gmail.com
//

#ifdef _WIN32

#include "WindowsSocket.hpp"
#include "Exception.hpp"

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

int engine::Network::WindowsSocket::connect_socket() {
    return 0;
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

#endif