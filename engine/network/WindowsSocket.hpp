//
// Created by Volgar on 09/01/2018.
// Contact: volgar.dev@gmail.com
//

#ifndef RTYPE_WINDOWSSOCKET_HPP
#define RTYPE_WINDOWSSOCKET_HPP

#ifdef _WIN32

#include <winsock2.h>
#include "Socket.hpp"
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>


#pragma comment (lib, "Ws2_32.lib")

namespace RType
{
    class WindowsSocket : public ISocket {
    private:
        WSADATA wsaData;
        struct addrinfo local;
        struct addrinfo *result = NULL;

    public:
        WindowsSocket(SocketType);

        ~WindowsSocket() override;

        void init_socket() override;
        int connect_socket() override;
        void blind_Socket() override;
        void listen_Socket() override;
        unsigned int get_fd() const override;
    };
};

#endif

#endif //RTYPE_WINDOWSSOCKET_HPP
