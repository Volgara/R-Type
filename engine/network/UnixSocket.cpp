//
// Created by Volgar on 09/01/2018.
// Contact: volgar.dev@gmail.com
//

#if defined(linux) || defined(__APPLE__)

#include <memory.h>
#include <zconf.h>
#include "UnixSocket.hpp"
#include "networkException.hpp"

engine::Network::UnixSocket::UnixSocket(engine::Network::SocketType type) {
    _socketType = type;
}


engine::Network::UnixSocket::~UnixSocket() {

}

void engine::Network::UnixSocket::init_socket(int port) {
    if (_socketType == Tcp)
        fd = socket(AF_INET, SOCK_STREAM, 0);
    else if (_socketType == Udp)
        fd =  socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (fd < 0) {
        throw NetworkException("Socket creation failed");
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
}

int engine::Network::UnixSocket::connect_socket(const std::string &ip, int port) {
    struct hostent *server;

    if (_socketType == Tcp)
        fd = socket(AF_INET, SOCK_STREAM, 0);
    else
        throw NetworkException("UDP connect not implemented yet");
    server = gethostbyname(ip.c_str());
    if (server == NULL) {
        throw NetworkException("No host found");
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, static_cast<size_t>(server->h_length));
    serv_addr.sin_port = htons(port);
    if (connect(fd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        throw NetworkException("Connect error");
    return (0);
}

void engine::Network::UnixSocket::bind_Socket() {
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
    return static_cast<unsigned int>(fd);
}


void engine::Network::UnixSocket::Init(void) {

}

void engine::Network::UnixSocket::onNotify(engine::core::Message *) {

}

void engine::Network::UnixSocket::Update(float) {

}

void engine::Network::UnixSocket::write_socket(std::string data) {
    write(fd, data.c_str(), data.size() + 1);

}

std::string engine::Network::UnixSocket::read_socket() {
    std::string res;
    char data[512];
    read(fd, data, 512);
    res = data;
    return(res);
}

#endif // linux and apple

