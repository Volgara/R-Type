//
// Created by Volgar on 09/01/2018.
// Contact: volgar.dev@gmail.com
//

#ifndef RTYPE_WINDOWSSOCKET_HPP
#define RTYPE_WINDOWSSOCKET_HPP

#ifdef _WIN32

#include <winsock2.h>
#include "Socket.hpp"

#pragma comment (lib, "Ws2_32.lib")

namespace RType
{
    class WindowsSocket : public ISocket {
    private:
        WSADATA wsaData;
        sockaddr_in local;

    public:
        WindowsSocket(SocketType);

        ~WindowsSocket() override;

        void init_socket() override;
        int connect_socket() override;
        void blind_Socket() override;
        void listen_Socket() override;
        int get_fd() const override;
    };
};

#endif

#endif //RTYPE_WINDOWSSOCKET_HPP
