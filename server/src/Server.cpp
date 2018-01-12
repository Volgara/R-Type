//
// Created by Volgar on 11/01/2018.
// Contact: volgar.dev@gmail.com
//

#include <WinSock2.h>
#include "Server.hpp"

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")


/* TODO
 * gerer la déconnection des joueurs
 * gerer le changement de salons
*/

RType::Server::Server() {

}

RType::Server::~Server() {
    delete _socket;
}

void RType::Server::configure() {
    _socket = new RType::Socket(RType::SocketType::Tcp);
    _socket->init_socket();
    _socket->connect_socket();
    _socket->blind_Socket();
    _socket->listen_Socket();
    _nbrPlayer = 0;
    _gameManager = new GameManager();
}

DWORD __stdcall startMethodInThread( LPVOID arg )
{
    if(!arg)
        return 0;
    RType::Server *yc_ptr = (RType::Server*)arg;
    yc_ptr->ThreadFunc();
    return 1;
}

DWORD RType::Server::ThreadFunc() {
    Player* player = _connectedUser.back();
    std::cout << "New player connected with id: " << player->getId() << std::endl;
    int a = 1;
    char buffer[256];

    while (a > 0)
    {
        ZeroMemory(&buffer, 256);
        a = recv(player->getFd(), buffer, 256, 0);
        if (a <= 0)
            std::cout << "[" << player->getId() << "]: Disconnected" << std::endl;
        else
            std::cout << "[" << player->getId() << "]: " << buffer << std::endl;
        if (strncmp(buffer, "list", 4) == 0)
            _gameManager->listRoom();
        if (strncmp(buffer, "join", 4) == 0)
            if (!_gameManager->join(player, buffer))
                std::cout << "Failed to " << buffer << std::endl;

    }
    return(1);
}

void RType::Server::run() {
    int fd;
    Player *newPlayer;

    std::cout << "Server started" << std::endl;
    while (true)
    {
        fd = accept(_socket->get_fd(), NULL, NULL);
        if (fd == -23245678)
            return;
        if (fd > 0)
        {
            newPlayer = new Player(fd, _nbrPlayer);
            _connectedUser.push_back(newPlayer);
            _nbrPlayer += 1;
            CreateThread(NULL, 0, startMethodInThread, this, 0, NULL);
        }
    }
}

