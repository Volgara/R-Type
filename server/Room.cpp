//
// Created by Volgar on 12/01/2018.
// Contact: volgar.dev@gmail.com
//

#include <iostream>
#include <network/Socket.hpp>
#ifdef _WIN32
#include <winsock2.h>
#include <Ws2tcpip.h>

#endif
#if defined(linux) || defined(__APPLE__)
#include <sys/socket.h>

#endif

#include "Room.hpp"

RTypeServer::Room::Room(std::string name) {
    _name = name;
    _gameStart = false;
}

bool RTypeServer::Room::join(Player *p) {
    if (_player.size() >= 4 || _gameStart)
    {
        std::cout << "join error, too much player or game already started" << std::endl;
        return false;
    }

    std::cout << "[" << p->getId() << "]: " << "joined " << _name << std::endl;
    _player.push_back(p);
    return (true);
}

void RTypeServer::Room::start(Player *p) {
    p->isReady = true;
    for (auto it : _player)
    {
        if (!it->isReady)
        {
            return;
        }
    }
    std::cout << "All player are ready, code the game here" << std::endl;
    _gameStart = true;
    engine::Network::Socket *udpSocket = new engine::Network::Socket(engine::Network::SocketType::Udp);
    udpSocket->init_socket(4243 + p->getId());
    udpSocket->blind_Socket();
    std::string initMessage;
    initMessage += std::to_string(4243 + p->getId());
    for (auto it : _player)
    {
        send(it->getFd(), initMessage.c_str(), initMessage.size() + 1, 0);
    }
    std::cout << "message send" << std::endl;
}

std::string RTypeServer::Room::getName() const {
    return _name;
}

int RTypeServer::Room::getNbrPlayer() const {
    return _player.size();
}

bool RTypeServer::Room::leave(Player *p) {
    int pos = 0;

    for (auto it : _player)
    {
        if (p->getId() == it->getId())
        {
            _player.erase(_player.begin() + pos);
            p->cleanRoom();
            p->isReady = false;
            send(p->getFd(), "ok", 3, 0);
            return (true);
        }
        pos += 1;
    }
    send(p->getFd(), "Ko", 3, 0);
    std::cout << "Leave failed, player not found in the room" << std::endl;
    return false;
}
