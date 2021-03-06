//
// Created by Hamza Hammouche on 21/01/2018.
//

#ifndef RTYPE_GAMESERVER_HPP
#define RTYPE_GAMESERVER_HPP

#include "../server/Room.hpp"
#include <network/Socket.hpp>
#if defined(linux) || defined(__APPLE__)
#include <sys/socket.h>
#endif
#include <physics/PhysicsSystem.hpp>
#include "GameLogicSystem.hpp"

namespace game {
    class GameServer {
    private:
        std::vector<RTypeServer::Player *> _players;

        engine::Network::Socket *initSocketSystem();

        void createPlayer(engine::core::Scene *);
    public:
        GameServer(std::vector<RTypeServer::Player *> players);

        virtual ~GameServer();

        void startGameServer();
    };
}


#endif //RTYPE_GAMESERVER_HPP
