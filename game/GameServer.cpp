//
// Created by Hamza Hammouche on 21/01/2018.
//

#include <projectile/BulletSystem.hpp>
#include <network/NetworkComponent.hpp>
#include "GameServer.hpp"

game::GameServer::GameServer(std::vector<RTypeServer::Player *> players) : _players(players) {}

game::GameServer::~GameServer() {}

void game::GameServer::startGameServer() {
    auto *eg = engine::core::Engine::GetInstance();
    engine::Network::Socket *udp = this->initSocketSytem();
    engine::physics::PhysicsSystem *physicsSystem = new engine::physics::PhysicsSystem(800, 800);
    game::GameLogicSystem *gameLogicSystem = new game::GameLogicSystem(800, 800);
    engine::projectile::BulletSystem *bulletSystem = new engine::projectile::BulletSystem(800, 800);

    eg->addSystem("socketUdp", udp);
    eg->addSystem("physics", physicsSystem);
    eg->addSystem("gameLogic", gameLogicSystem);
    eg->addSystem("bullets", bulletSystem);

    eg->setScene(new core::Scene());
    this->createPlayer(eg->getScene());

    eg->Init();
    eg->MainLoop();
    eg->Shutdown();
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

void game::GameServer::createPlayer(engine::core::Scene *scene) {
    engine::core::Vector2d pos(10, 10);

    for (auto it : this->_players) {
        engine::core::GameObject *player = scene->CreateEmptyObject();
        player->pos.setX(pos.getX());
        player->pos.setY(pos.getY());
        pos.setY(pos.getY() + 10);
        PlayerComponent *playerComponent = static_cast<PlayerComponent *>(scene->CreateComponent(engine::core::ComponentID::GAME_PLAYER));
        engine::network::NetworkComponent *networkComponent = static_cast<engine::network::NetworkComponent *>(scene->CreateComponent(engine::core::ComponentID::NET));
        engine::physics::RigidBodyComponent *rigidBodyComponent = static_cast<engine::physics::RigidBodyComponent *>(scene->CreateComponent(engine::core::ComponentID::PHY_RIGIDBODY));
        networkComponent->setFd(it->getFd());
        networkComponent->setId(it->getId());
        networkComponent->setIsReady(it->getRoomStatus());
        networkComponent->setRoomName(it->getRoomName());
        rigidBodyComponent->setVelocity(engine::core::Vector2d(0, 0));
        rigidBodyComponent->setSize(playerComponent->getSize());
        rigidBodyComponent->Init();
        player->attachComponent(playerComponent);
        player->attachComponent(networkComponent);
        player->attachComponent(rigidBodyComponent);
    }
}

