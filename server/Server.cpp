//
// Created by Volgar on 11/01/2018.
// Contact: volgar.dev@gmail.com
//
#ifdef _WIN32
#include <WinSock2.h>
#endif

#include <thread>
#if defined(linux) || defined(__APPLE__)
#include <sys/socket.h>
#endif
#include <cstring>
#include "Server.hpp"

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")


RTypeServer::Server::Server() {

}

RTypeServer::Server::~Server() {
    delete _socket;
}

void RTypeServer::Server::configure() {
    _socket = new engine::Network::Socket(engine::Network::SocketType::Tcp);
    _socket->init_socket(4242);
    _socket->bind_Socket();
    _socket->listen_Socket();
    _nbrPlayer = 0;
    _gameManager = new GameManager();
}

#ifdef _WIN32
DWORD __stdcall startMethodInThread( LPVOID arg )
{
    if(!arg)
        return 0;
    RTypeServer::Server *yc_ptr = (RTypeServer::Server*)arg;
    yc_ptr->ThreadFunc();
    return 1;
}

DWORD RTypeServer::Server::ThreadFunc() {
Player* player = _connectedUser.back();
    std::cout << "New player connected with id: " << player->getId() << std::endl;
    int a = 1;
    char buffer[256];

    while (a > 0)
    {
        ZeroMemory(&buffer, 256);
        a = recv(player->getFd(), buffer, 256, 0);
        if (a <= 0)
        {
            std::cout << "[" << player->getId() << "]: Disconnected" << std::endl;
            if (player->getRoomStatus())
                _gameManager->leave(player);
        }
        else
            std::cout << "[" << player->getId() << "]: " << buffer << std::endl;
        if (strncmp(buffer, "list", 4) == 0)
            _gameManager->listRoom(player);
        else if (strncmp(buffer, "join", 4) == 0)
        {
            if (!_gameManager->join(player, buffer))
            {
                std::cout << "Failed to " << buffer << std::endl;
                send(player->getFd(), "ko", 3, 0);
            }
            else
                send(player->getFd(), "ok", 3, 0);
        }
        else if (strncmp(buffer, "roominfo", 8) == 0){
            _gameManager->inforoom(player);
        }
        else if (strncmp(buffer, "leave", 5) == 0){
            _gameManager->leave(player);
        }
        else if (strncmp(buffer, "start", 5) == 0){
            _gameManager->start(player);
        }
    }
    return(1);
}
#endif

#if defined(linux) || defined(__APPLE__)
void threadLinux(void *data)
{
    if(!data)
        return;
    RTypeServer::Server *yc_ptr = (RTypeServer::Server*)data;
    yc_ptr->ThreadFunct();
    return;
}

void RTypeServer::Server::ThreadFunct() {
    Player* player = _connectedUser.back();
    std::cout << "New player connected with id: " << player->getId() << std::endl;
    int a = 1;
    char buffer[256];

    while (a > 0)
    {
        memset(&buffer, 0, 256);
        a = recv(player->getFd(), buffer, 256, 0);
        if (a <= 0)
        {
            std::cout << "[" << player->getId() << "]: Disconnected" << std::endl;
            if (player->getRoomStatus())
                _gameManager->leave(player);
        }
        else
            std::cout << "[" << player->getId() << "]: " << buffer << std::endl;
        if (strncmp(buffer, "list", 4) == 0)
            _gameManager->listRoom(player);
        else if (strncmp(buffer, "join", 4) == 0)
        {
            if (!_gameManager->join(player, buffer))
            {
                std::cout << "Failed to " << buffer << std::endl;
                send(player->getFd(), "ko", 3, 0);
            }
            else
                send(player->getFd(), "ok", 3, 0);
        }
        else if (strncmp(buffer, "roominfo", 8) == 0){
            _gameManager->inforoom(player);
        }
        else if (strncmp(buffer, "leave", 5) == 0){
            _gameManager->leave(player);
        }
        else if (strncmp(buffer, "start", 5) == 0){
            _gameManager->start(player);
        }
    }
}
#endif

void RTypeServer::Server::run() {
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
            #ifdef _WIN32
            CreateThread(NULL, 0, startMethodInThread, this, 0, NULL);
            #endif
            #if defined(linux) || defined(__APPLE__)
            std::thread t1 = std::thread(threadLinux, this);
            t1.detach();
            #endif
        }
    }
}


