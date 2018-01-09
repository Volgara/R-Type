//
// Created by Volgar on 09/01/2018.
// Contact: volgar.dev@gmail.com
//

#ifndef RTYPE_ISOCKET_HPP
#define RTYPE_ISOCKET_HPP

#include <iostream>

namespace RType
{
    enum SocketType {Tcp, Udp};

    class ISocket {

    protected:
        int         fd;
        SocketType  _socketType;

    public:
        enum OsType {Windows, Linux};
        virtual ~ISocket() {};

    public:
        virtual void init_socket() = 0;
        virtual int connect_socket() = 0;
        virtual int blind_Socket() = 0;
        virtual int listen_Socket() = 0;
        virtual int get_fd() const = 0;
    };
};

#endif //RTYPE_ISOCKET_HPP
