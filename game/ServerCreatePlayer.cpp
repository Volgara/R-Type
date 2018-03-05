//
// Created by Hamza Hammouche on 22/01/2018.
//

#include "ServerCreatePlayer.hpp"

game::ServerCreatePlayer::ServerCreatePlayer(engine::Network::Socket *_udp,
                                             const std::vector<RTypeServer::Player *> &_players) : _udp(_udp),
                                                                                                   _players(_players) {}

game::ServerCreatePlayer::~ServerCreatePlayer() {

}

std::string game::ServerCreatePlayer::recvnblock(int fd) {
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

void game::ServerCreatePlayer::registerPlayer() {
    RTypeServer::Player *p = this->_players[0];

    this->_udp->init_socket(4243 + p->getId());
    this->_udp->bind_Socket();
    std::string initMessage;
    std::vector<int> ids;
    int i = 0;
    for (auto it : this->_players) {
        initMessage = std::to_string(4243 + p->getId() + i);
        ids.push_back(i);
        std::cout << "Message with id" << initMessage << std::endl;
        send(it->getFd(), initMessage.c_str(), initMessage.size() + 1, 0);
    }
    std::cout << "BEFORE RECV" << std::endl;
    std::string res;
    res = recvnblock(this->_udp->get_fd());
    while (!ids.empty())
    {
        res = recvnblock(this->_udp->get_fd());
        this->checkPlayer(&ids, res);

    }
    std::cout << "DATA RECV"<< res << std::endl;
}

bool    game::ServerCreatePlayer::checkPlayer(std::vector<int> *ids, std::string res) {


    return false;
}

void game::ServerCreatePlayer::createPlayer(engine::core::Scene *scene) {
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

