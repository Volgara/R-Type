//
// Created by Hamza Hammouche on 21/01/2018.
//

#include <projectile/BulletSystem.hpp>

#ifdef _WIN32
#include <WinSock2.h>
#endif

#include <network/NetworkComponent.hpp>
#include <sys/poll.h>
#include <cstring>
#include "GameServer.hpp"

game::GameServer::GameServer(std::vector<RTypeServer::Player *> players) : _players(players) {}

game::GameServer::~GameServer() {}

void game::GameServer::startGameServer() {
    auto *eg = engine::core::Engine::GetInstance();
    engine::Network::Socket *udp = this->initSocketSystem();
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

std::string recvnblock(int fd)
{
#if defined(linux) || defined(__APPLE__)
    std::cout << "recvnbock called" << std::endl;
    std::string res = "";
    struct pollfd *poll_fd;
    poll_fd = (pollfd * )malloc(sizeof(struct pollfd) * 1);
    poll_fd[0].fd = fd;
    poll_fd[0].events = POLLIN | POLLOUT;
    char buffer[256];
    poll(poll_fd, 1, 500);
    if (poll_fd[0].revents & POLLIN)
    {
        recv(fd, buffer, 256, 0);
        res = buffer;
        free(poll_fd);
        return (res);
    }
    free(poll_fd);
    return (res);
#endif
}


engine::Network::Socket *game::GameServer::initSocketSystem() {
    engine::Network::Socket *udp = new engine::Network::Socket(engine::Network::SocketType::Udp);

    RTypeServer::Player *p = this->_players[0];

    udp->init_socket(4243 + p->getId());
    udp->bind_Socket();
    std::string initMessage;
    initMessage += std::to_string(4243 + p->getId());
    for (auto it : this->_players) {
        send(it->getFd(), initMessage.c_str(), initMessage.size() + 1, 0);
    }

    std::cout << "BEFORE RECV" << std::endl;
    std::string res;
    res = recvnblock(udp->get_fd());
    while (strcmp(res.c_str(), "") == 0)
    {
        res = recvnblock(udp->get_fd());
    }
    std::cout << "DATA RECV"<< res << std::endl;
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
        player->attachComponent(playerComponent);
        player->attachComponent(networkComponent);
        player->attachComponent(rigidBodyComponent);
        rigidBodyComponent->Init();
    }
}
