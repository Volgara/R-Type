//
// Created by Volgar on 11/01/2018.
// Contact: volgar.dev@gmail.com
//

#include <iostream>
#include <cstring>
#include <network/Socket.hpp>
#include <sys/socket.h>
#include "GameManager.hpp"

GameManager::GameManager() {

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
    for (auto it : _room)
    {
        data += it->getName();
        data += ",";
        data += it->getNbrPlayer();
        data += "|";
        std::cout << it->getName() << std::endl;
    }
    std::cout << "Data send: " << data << std::endl;
    send(p->getFd(), data.c_str(), data.size(), 0);
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
