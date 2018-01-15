//
// Created by Volgar on 11/01/2018.
// Contact: volgar.dev@gmail.com
//

#include <iostream>
#include <cstring>
#include <Socket.hpp>
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

void GameManager::listRoom() {
    for (auto it : _room)
    {
        std::cout << it->getName() << std::endl;
    }
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
