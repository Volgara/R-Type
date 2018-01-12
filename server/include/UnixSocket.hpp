//
// Created by Volgar on 09/01/2018.
// Contact: volgar.dev@gmail.com
//

#ifndef RTYPE_UNIXSOCKET_HPP
#define RTYPE_UNIXSOCKET_HPP

#if defined(linux) || defined(__APPLE__)

#include "ISocket.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>


namespace RType
{
    class UnixSocket : public ISocket{
    private:
        struct sockaddr_in serv_addr;
    public:
        UnixSocket(SocketType);

        ~UnixSocket() override;

        void init_socket() override;
        int connect_socket() override;
        void blind_Socket() override;
        void listen_Socket() override;
        unsigned int get_fd() const override;
    };
};

#endif // linux or apple

#endif //RTYPE_UNIXSOCKET_HPP
