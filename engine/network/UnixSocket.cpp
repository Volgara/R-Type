//
// Created by Volgar on 09/01/2018.
// Contact: volgar.dev@gmail.com
//

#if defined(linux) || defined(__APPLE__)

#include "UnixSocket.hpp"
#include "networkException.hpp"

engine::Network::UnixSocket::UnixSocket(engine::Network::SocketType type) {
    _socketType = type;
}


engine::Network::UnixSocket::~UnixSocket() {

}

void engine::Network::UnixSocket::init_socket() {
    if (_socketType == Tcp)
        fd = socket(AF_INET, SOCK_STREAM, 0);
    else if (_socketType == Udp)
        fd =  socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (fd < 0) {
        throw NetworkException("Socket creation failed");
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(4242);
}

int engine::Network::UnixSocket::connect_socket() {
    return 0;
}

void engine::Network::UnixSocket::blind_Socket() {
    if (bind(fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        throw NetworkException("Bind failed");
    }
}

void engine::Network::UnixSocket::listen_Socket() {
    if (_socketType == Tcp)
    {
        if (listen(fd, 10) != 0)
            throw NetworkException("Liston failed");
    }
}

unsigned int engine::Network::UnixSocket::get_fd() const {
    return fd;
}


void engine::Network::UnixSocket::Init(void) {

}

void engine::Network::UnixSocket::onNotify(engine::core::Message message) {

}

void engine::Network::UnixSocket::Update(float dt) {

}

#endif // linux and apple

