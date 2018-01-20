//
// Created by Volgar on 12/01/2018.
// Contact: volgar.dev@gmail.com
//

#ifndef RTYPE_ROOM_HPP
#define RTYPE_ROOM_HPP

#include <string>
#include <vector>
#include "Player.hpp"


namespace RType
{
    class Room {
    private:
        bool _gameStart;
        std::string _name;
        std::vector<Player *> _player;
    public:
        Room(std::string name);
        std::string getName() const;
        bool join(Player *);
        bool leave(Player *);
        void start(Player *);
        int getNbrPlayer() const;
    };
}

#endif //RTYPE_ROOM_HPP
