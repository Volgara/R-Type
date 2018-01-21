//
// Created by Volgar on 08/01/2018.
// Contact: volgar.dev@gmail.com
//

#include <cstring>
#if defined(linux) || defined(__APPLE__)
#include <sys/poll.h>
#include <sstream>

#endif
#include "Socket.hpp"
#include "WindowsSocket.hpp"
#include "UnixSocket.hpp"

engine::Network::Socket::Socket(engine::Network::SocketType type) {
    _socket = NULL;
#ifdef _WIN32
    std::cout << "Running on windows" << std::endl;
    _socket = (ISocket *) new WindowsSocket(type);
#endif

#ifdef linux
    std::cout << "Running on linux" << std::endl;
    _socket = (ISocket *) new UnixSocket(type);
    poll_fd = (pollfd * )malloc(sizeof(struct pollfd) * 1);
    poll_fd[0].fd = (int)this->get_fd();
    poll_fd[0].events = POLLIN | POLLOUT;

#endif

#ifdef __APPLE__
    std::cout << "Runnin on Macos" << std::endl;
    _socket = (ISocket *) new UnixSocket(type);
    poll_fd = (pollfd * )malloc(sizeof(struct pollfd) * 1);
    poll_fd[0].fd = this->get_fd();
    poll_fd[0].events = POLLIN | POLLOUT;
#endif
}

engine::Network::Socket::~Socket() {

}

void engine::Network::Socket::init_socket(int p) {
    _socket->init_socket(p);
}

int engine::Network::Socket::connect_socket(const std::string &ip, int port) {
    return (_socket->connect_socket(ip, port));
}

void engine::Network::Socket::blind_Socket() {
    _socket->blind_Socket();
}

void engine::Network::Socket::listen_Socket() {
    _socket->listen_Socket();
}

unsigned int engine::Network::Socket::get_fd() const {
    return (_socket->get_fd());
}

void engine::Network::Socket::send_data(char *data) {
//    send(_socket->fd, data, 512, 0);
}

void engine::Network::Socket::Init(void) {

}

void engine::Network::Socket::onNotify(engine::core::Message message) {
    std::stringstream Buffer(std::iostream::in | std::iostream::out);
    char null = '\0';

    Buffer.write((char*)&message, sizeof(message));
    Buffer.write(&null, 1);
    _queue.push_back(Buffer.str().c_str());
}


void engine::Network::Socket::Update(float dt) {

#if defined(linux) || defined(__APPLE__)
    char buffer[256];
    poll(poll_fd, 1, 500);
    if (poll_fd[0].revents & POLLIN)
    {
        recv((int)this->get_fd(), buffer, 256, 0);
        //engine::core::Message msg();

    }
    else if (_queue.size() > 0 && poll_fd[0].revents & POLLOUT)
    {
        const char *data = _queue.front();
        _queue.erase (_queue.begin());
        send((int)this->get_fd(), data, strlen(data), 0);
    }
#endif
#ifdef _Win32
    struct pollfd *poll_fd;
    char buffer[256];
    poll_fd = (pollfd * )malloc(sizeof(struct pollfd) * 1);
    poll_fd[0].fd = SOCKETFD;
    poll_fd[0].events = POLLIN | POLLOUT;

    poll(poll_fd, 1, 500);
    if (poll_fd[0].revents & POLLIN)
        recv(this->get_fd(), buffer, 256, 0);
    else if (_queue.size() > 0 && poll_fd[0].revents & POLLOUT)
    {
        const char *data = _queue.front();
        _queue.erase (_queue.begin());
        send((int)this->get_fd(), data, strlen(data), 0);
    }
#endif
    (void) dt;
}

void engine::Network::Socket::write_socket(std::string data) {
    _socket->write_socket(data);
}

std::string engine::Network::Socket::read_socket() {
    return(_socket->read_socket());
}

