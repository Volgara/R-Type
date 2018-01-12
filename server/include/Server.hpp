//
// Created by Volgar on 11/01/2018.
// Contact: volgar.dev@gmail.com
//

#ifndef RTYPE_SERVER_HPP
#define RTYPE_SERVER_HPP

#include <Socket.hpp>
#include "GameManager.hpp"
#include <Windows.h>
#include <iostream>


namespace RType{
    class Server{
    private:
        Socket *_socket;
        int _nbrPlayer;
        GameManager *_gameManager;
        std::vector<Player *> _connectedUser;
    public:
        Server();
        ~Server();
        void configure();
        void run();
        DWORD ThreadFunc();
    };
};

#endif //RTYPE_SERVER_HPP
