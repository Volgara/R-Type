//
// Created by Volgar on 11/01/2018.
// Contact: volgar.dev@gmail.com
//

#ifndef RTYPE_SERVER_HPP
#define RTYPE_SERVER_HPP

#include "GameManager.hpp"
#ifdef _WIN32
#include <Windows.h>
#endif
#include <iostream>
#include <network/Socket.hpp>


namespace RTypeServer {
    class Server{
    private:
        engine::Network::Socket *_socket;
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
        #if defined(linux) || defined(__APPLE__)
        void ThreadFunct();
        #endif
    };
};

#endif //RTYPE_SERVER_HPP
