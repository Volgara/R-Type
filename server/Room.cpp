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

RType::Room::Room(std::string name) {
    _name = name;
    _gameStart = false;
}

bool RType::Room::join(Player *p) {
    if (_player.size() >= 4 || _gameStart)
        return false;
    std::cout << "[" << p->getId() << "]: " << "joined " << _name << std::endl;
    _player.push_back(p);
    return (true);
}

void RType::Room::start(Player *p) {
    _gameStart = true;

    p->isReady = true;
    for (auto it : this->_player)
    {
        if (!it->isReady)
        {
            std::cout << "Waiting for other player to be ready" << std::endl;
            return;
        }
    }
    std::cout << "All player are ready, code the game here" << std::endl;
    //game started
    engine::Network::Socket *udpSocket = new engine::Network::Socket(engine::Network::SocketType::Udp);
    udpSocket->init_socket(4242 + p->getId());
    udpSocket->blind_Socket();
    std::string initMessage;
    initMessage += "Game started with id: ";
    initMessage += (4242 + p->getId());
    for (auto it : _player)
    {
        send(it->getFd(), initMessage.c_str(), initMessage.size() + 1, 0);
    }
}

std::string RType::Room::getName() const {
    return _name;
}

int RType::Room::getNbrPlayer() const {
    return _player.size();
}

bool RType::Room::leave(Player *p) {
    int pos = 0;

    for (auto it : _player)
    {
        if (p->getId() == it->getId())
        {
            _player.erase(_player.begin() + pos);
            p->cleanRoom();
            send(p->getFd(), "ok", 3, 0);
            return (true);
        }
        pos += 1;
    }
    std::cout << "Leave failed, player not found in the room" << std::endl;
    return false;
}
