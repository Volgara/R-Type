//
// Created by Volgar on 08/01/2018.
// Contact: volgar.dev@gmail.com
//

#ifndef RTYPE_SOCKET_HPP
#define RTYPE_SOCKET_HPP

#include "ISocket.hpp"

namespace RType
{

    class Socket : public ISocket {
    public:
        ISocket *_socket;

    public:
        Socket(SocketType);
        ~Socket() override;

        void init_socket() override;
        int connect_socket() override;
        int blind_Socket() override;
        int listen_Socket() override;
        int get_fd() const override;
    };
};


#endif //RTYPE_SOCKET_HPP
