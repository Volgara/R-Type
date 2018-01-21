//
// Created by Hamza Hammouche on 21/01/2018.
//

#include "GameServer.hpp"

game::GameServer::GameServer(std::vector<RTypeServer::Player *> players) : _players(players) {}

game::GameServer::~GameServer() {}

void game::GameServer::startGameServer() {
    auto *eg = engine::core::Engine::GetInstance();
    engine::Network::Socket *udp = this->initSocketSytem();
    engine::physics::PhysicsSystem *physicsSystem = new engine::physics::PhysicsSystem(800, 800);
    game::GameLogicSystem *gameLogicSystem = new game::GameLogicSystem(800, 800);

    eg->addSystem("socketUdp", udp);
    eg->addSystem("physics", physicsSystem);
    eg->addSystem("gameLogic", gameLogicSystem);
}

engine::Network::Socket *game::GameServer::initSocketSytem() {
    engine::Network::Socket *udp = new engine::Network::Socket(engine::Network::SocketType::Udp);

    RTypeServer::Player *p = this->_players[0];
    udp->init_socket(4243 + p->getId());
    udp->bind_Socket();
    std::string initMessage;
    initMessage += std::to_string(4243 + p->getId());
    for (auto it : this->_players) {
        send(it->getFd(), initMessage.c_str(), initMessage.size() + 1, 0);
    }
    return (udp);
}

