//
// Created by Volgar on 08/01/2018.
// Contact: volgar.dev@gmail.com
//

#ifndef RTYPE_SOCKET_HPP
#define RTYPE_SOCKET_HPP

#include "ISocket.hpp"
#include "core/MessageBus.hpp"

namespace engine {
    namespace Network {
        class Socket : public ISocket {
        public:
            ISocket *_socket;
        public:
            Socket(SocketType);
            ~Socket() override;
            void init_socket() override;
            int connect_socket(const  std::string &ip, int port) override;
            void blind_Socket() override;
            void listen_Socket() override;
            unsigned int get_fd() const override;
            void send_data(char *);
            void Init(void) override;
            void onNotify(core::Message message) override;
            void Update(float dt) override;
        };
    }
}

#endif //RTYPE_SOCKET_HPP
