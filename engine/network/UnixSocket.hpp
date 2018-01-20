//
// Created by Volgar on 09/01/2018.
// Contact: volgar.dev@gmail.com
//

#ifndef RTYPE_UNIXSOCKET_HPP
#define RTYPE_UNIXSOCKET_HPP

#if defined(linux) || defined(__APPLE__)

#include "ISocket.hpp"
#include <netdb.h>
#include <netinet/in.h>

namespace engine {
    namespace Network{
        class UnixSocket : public ISocket{
        private:
            struct sockaddr_in serv_addr;
        public:
            explicit UnixSocket(SocketType);

            ~UnixSocket() override;

            void init_socket(int port) override;
            int connect_socket(const std::string &ip, int port) override;
            void blind_Socket() override;
            void listen_Socket() override;
            unsigned int get_fd() const override;
            void Init(void) override;
            void onNotify(core::Message message) override;
            void Update(float dt) override;
            void write_socket(std::string) override;
            std::string read_socket() override;
        };
    }
}

#endif // linux or apple

#endif //RTYPE_UNIXSOCKET_HPP
