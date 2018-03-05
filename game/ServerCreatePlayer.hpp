//
// Created by Hamza Hammouche on 22/01/2018.
//

#ifndef RTYPE_SERVERCREATEPLAYER_HPP
#define RTYPE_SERVERCREATEPLAYER_HPP

#include "../server/Room.hpp"
#include <network/Socket.hpp>
#if defined(linux) || defined(__APPLE__)
#include <sys/socket.h>
#endif
#include <physics/PhysicsSystem.hpp>
#include "GameLogicSystem.hpp"
#include <sys/poll.h>
#include <network/NetworkComponent.hpp>

namespace game {
    class ServerCreatePlayer {
    private:
        engine::Network::Socket *_udp;
        std::vector<RTypeServer::Player *> _players;

        std::string recvnblock(int fd);
        bool checkPlayer(std::vector<int> *, std::string);

    public:
        ServerCreatePlayer(engine::Network::Socket *_udp, const std::vector<RTypeServer::Player *> &_players);
        virtual ~ServerCreatePlayer();

        void registerPlayer();

        void createPlayer(engine::core::Scene *scene);
    };
}


#endif //RTYPE_SERVERCREATEPLAYER_HPP
