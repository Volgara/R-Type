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
        UnixSocket();

        ~UnixSocket() override;

        void init_socket();
        int connect_socket();
        int blind_Socket();
        int listen_Socket();
        int get_fd() const;
    };
};



#endif //RTYPE_UNIXSOCKET_HPP
