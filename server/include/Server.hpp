//
// Created by Volgar on 11/01/2018.
// Contact: volgar.dev@gmail.com
//

#ifndef RTYPE_SERVER_HPP
#define RTYPE_SERVER_HPP

#include <Socket.hpp>
#include "GameManager.hpp"
#ifdef _WIN32
#include <Windows.h>
#endif
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
        #ifdef _WIN32
        DWORD ThreadFunc();
        #endif
    };
};

#endif //RTYPE_SERVER_HPP
