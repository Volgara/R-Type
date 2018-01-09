//
// Created by Volgar on 09/01/2018.
// Contact: volgar.dev@gmail.com
//

#ifndef RTYPE_WINDOWSSOCKET_HPP
#define RTYPE_WINDOWSSOCKET_HPP

#include "Socket.hpp"

namespace RType
{
    class WindowsSocket : public ISocket {
    public:
        WindowsSocket();

        ~WindowsSocket() override;

        void init_socket();
        int connect_socket();
        int blind_Socket();
        int listen_Socket();
        int get_fd() const;
    };
};

#endif //RTYPE_WINDOWSSOCKET_HPP
