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
        Socket();
        ~Socket() override;

        void init_socket();
        int connect_socket();
        int blind_Socket();
        int listen_Socket();
        int get_fd() const;
    };
};


#endif //RTYPE_SOCKET_HPP
