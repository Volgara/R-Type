//
// Created by Volgar on 11/01/2018.
// Contact: volgar.dev@gmail.com
//

#include <iostream>
#include <cstring>
#include <network/Socket.hpp>

#ifdef _WIN32
#include <winsock2.h>
#include <Ws2tcpip.h>

#endif
#if defined(linux) || defined(__APPLE__)
#include <sys/socket.h>

#endif

#include "GameManager.hpp"

GameManager::GameManager() {
    RType::Room *newRoom = new RType::Room("Room1");
    _room.push_back(newRoom);
    RType::Room *newRoom2 = new RType::Room("Room2");
    _room.push_back(newRoom);
    RType::Room *newRoom3 = new RType::Room("cara#~#{#[#|");
    _room.push_back(newRoom);
}

GameManager::~GameManager() {

}

bool GameManager::join(Player *p, std::string roomname) {
    if (p->getRoomStatus())
        return (false);

    roomname.erase(0, 5);
    if (roomname.length() == 0)
        return (false);
    for (auto it : _room)
    {
        if (strcmp(it->getName().c_str(), roomname.c_str()) == 0)
        {
            p->setRoom(it->getName());
            return(it->join(p));
        }
    }
    RType::Room *newRoom = new RType::Room(roomname);
    _room.push_back(newRoom);
    for (auto it : _room)
    {
        if (strcmp(it->getName().c_str(), roomname.c_str()) == 0)
        {
            p->setRoom(it->getName());
            return(it->join(p));
        }
    }
    return (false);
}

void GameManager::listRoom(Player *p) {
    std::string data = " ";
    int a = 0;
    for (auto it : _room)
    {
        if (a != 0)
            data += "|";
        data += it->getName();
        data += ",";
        data += std::to_string(it->getNbrPlayer());
        std::cout << it->getName() << std::endl;
        a += 1;
    }
    std::cout << "Data send: " << data << std::endl;
    send(p->getFd(), data.c_str(), data.size() + 1, 0);
}

bool GameManager::start(std::string roomName) {
    for (auto it : _room)
    {
        if (strcmp(it->getName().c_str(), roomName.c_str()))
        {
            it->start();
            return (true);
        }

    }
    return (false);
}

bool GameManager::leave(Player *p) {
    if (p->getRoomStatus())
    {
        for (auto it : _room)
        {
            if (it->getName() == p->getRoomName())
                return(it->leave(p));
        }
    }
    return false;
}

void GameManager::inforoom(Player *p) {
    if (!p->getRoomStatus())
        return;
    for (auto it : _room)
    {
        if (it->getName() == p->getRoomName())
        {
            std::string res;
            res += std::to_string(it->getNbrPlayer());
            send(p->getFd(), res.c_str(), res.size() + 1, 0);
            return;
        }
    }
    std::cout << "No romm found"<< std::endl;
}

