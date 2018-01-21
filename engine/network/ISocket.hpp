//
// Created by Volgar on 09/01/2018.
// Contact: volgar.dev@gmail.com
//

#ifndef RTYPE_ISOCKET_HPP
#define RTYPE_ISOCKET_HPP

#include <iostream>
#include <core/ASystem.hpp>


namespace engine {
    namespace Network{
        enum SocketType {Tcp, Udp};

        class ISocket  : public core::ASystem {

        protected:
            int     fd;
            SocketType  _socketType;

        public:
            enum OsType {Windows, Linux};
            virtual ~ISocket() {};

        public:
            virtual void init_socket(int port) = 0;
            virtual int connect_socket(const std::string &ip, int port) = 0;
            virtual void bind_Socket() = 0;
            virtual void listen_Socket() = 0;
            virtual unsigned int get_fd() const = 0;
            virtual void write_socket(std::string) = 0;
            virtual void write_socket_size(const char *, size_t);
            virtual std::string read_socket() = 0;

        };
    }
}

#endif //RTYPE_ISOCKET_HPP
