//
// Created by Volgar on 11/01/2018.
// Contact: volgar.dev@gmail.com
//

#ifndef RTYPE_PLAYER_HPP
#define RTYPE_PLAYER_HPP

#include <string>

class Player {
public:
    Player(int fd, int id);
    int getId() const;
    int getFd() const;
    bool getRoomStatus() const;
    std::string getRoomName() const;
    void setRoom(std::string roomName);
    void cleanRoom();

private:
    int _fd;
    int _id;
    bool _inRoom;
    std::string _roomName;

};


#endif //RTYPE_PLAYER_HPP
