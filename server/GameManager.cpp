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
    _room.push_back(newRoom2);
    RType::Room *newRoom3 = new RType::Room("cara#~#{#[#");
    _room.push_back(newRoom3);
}

GameManager::~GameManager() {

}

bool GameManager::join(Player *p, std::string roomname) {
    if (p->getRoomStatus())
    {
        std::cout << "join error, player aleady in room" << std::endl;
        return (false);
    }


    roomname.erase(0, 5);
    if (roomname.length() == 0)
    {
        std::cout << "join error, bad room name" << std::endl;
        return (false);
    }

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
    std::cout << "join failed, unknow error" << std::endl;
    return (false);
}

void GameManager::listRoom(Player *p) {
    std::string data = "";
    int a = 0;
    for (auto it : _room)
    {
        if (!it->_gameStart)
        {
            if (a != 0)
                data += "|";
            data += it->getName();
            data += ",";
            data += std::to_string(it->getNbrPlayer());
            a += 1;
        }
    }
    std::cout << "Data send: " << data << std::endl;
    send(p->getFd(), data.c_str(), data.size() + 1, 0);
}

bool GameManager::start(Player *p) {
    for (auto it : _room)
    {
        if (strcmp(it->getName().c_str(), p->getRoomName().c_str()) == 0)
        {
            it->start(p);
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
            {
                return(it->leave(p));
            }
        }
    }
    return false;
}

void GameManager::inforoom(Player *p) {
    if (!p->getRoomStatus())
    {
        std::cout << "Error player not in a room" << std::endl;
        return;
    }

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
    std::cout << "No room found"<< std::endl;
}

