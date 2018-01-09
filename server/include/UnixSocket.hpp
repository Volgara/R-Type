//
// Created by Volgar on 09/01/2018.
// Contact: volgar.dev@gmail.com
//

#ifndef RTYPE_UNIXSOCKET_HPP
#define RTYPE_UNIXSOCKET_HPP

#include "ISocket.hpp"

namespace RType
{
    class UnixSocket : public ISocket{
    public:
        UnixSocket(SocketType);

        ~UnixSocket() override;

        void init_socket() override;
        int connect_socket() override;
        int blind_Socket() override;
        int listen_Socket() override;
        int get_fd() const override;
    };
};



#endif //RTYPE_UNIXSOCKET_HPP
