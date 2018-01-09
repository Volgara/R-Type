//
// Created by Volgar on 09/01/2018.
// Contact: volgar.dev@gmail.com
//

#ifndef RTYPE_WINDOWSSOCKET_HPP
#define RTYPE_WINDOWSSOCKET_HPP

#include <winsock2.h>
#include "Socket.hpp"

namespace RType
{
    class WindowsSocket : public ISocket {
    public:
        WindowsSocket(SocketType);

        ~WindowsSocket() override;

        void init_socket() override;
        int connect_socket() override;
        int blind_Socket() override;
        int listen_Socket() override;
        int get_fd() const override;
    };
};

#endif //RTYPE_WINDOWSSOCKET_HPP
