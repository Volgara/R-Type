//
// Created by Volgar on 11/01/2018.
// Contact: volgar.dev@gmail.com
//

#ifndef RTYPE_GAMEMANAGER_HPP
#define RTYPE_GAMEMANAGER_HPP

#include <vector>
#include "Player.hpp"
#include "Room.hpp"


class GameManager {
    std::vector<RType::Room *> _room;
public:
    GameManager();
    ~GameManager();
    bool join(Player *, std::string);
    void listRoom(Player *);
    bool start(std::string roomName);
    bool leave(Player *);
    void inforoom(Player *);
};


#endif //RTYPE_GAMEMANAGER_HPP
