//
// Created by Volgar on 11/01/2018.
// Contact: volgar.dev@gmail.com
//

#ifndef RTYPE_PLAYER_HPP
#define RTYPE_PLAYER_HPP

class Player {
public:
    Player(int fd, int id);
    int getId() const;
    int getFd() const;

private:
    int _fd;
    int _id;

};


#endif //RTYPE_PLAYER_HPP
