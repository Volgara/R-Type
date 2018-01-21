//
// Created by macdoy on 21/01/18.
//

#include "GameLogicClientSystem.hpp"

game::GameLogicClientSystem::GameLogicClientSystem(int width, int height) : _width(width), _height(height) {}


void game::GameLogicClientSystem::Update(float dt) {
    this->_currentDt = dt;
}

void game::GameLogicClientSystem::Init() {}

void game::GameLogicClientSystem::onNotify(engine::core::Message message) {
    std::cout << "In notify" << std::endl;
    if (message.id == game::GameMessageID::PLAYER_ACTION) {
        std::cout << "Player action" << std::endl;
        auto *eg = engine::core::Engine::GetInstance();
        auto *movePlayer = static_cast<game::PlayerActionMessage *>(&message);

        std::cout << "Before gameObject" << std::endl;
        engine::core::GameObject *source = movePlayer->m_ref;
        std::cout << "Before playAction" << std::endl;
        this->playAction(source, movePlayer->getAction());
    }
    else if (message.id == game::GameMessageID::SERVER_ACTION) {
        auto *eg = engine::core::Engine::GetInstance();
        auto *move = static_cast<game::ServerActionMessage *>(&message);

        engine::core::GameObject *source = eg->getScene()->GetGameObject(move->getSource());
        this->move(source, move->getPos().getX(), move->getPos().getY());
    }
    std::cout << "End value" << std::endl;
}

void game::GameLogicClientSystem::playAction(engine::core::GameObject *source, PlayerActionMessage::Action action) {
    std::cout << "In play action" <<  source->guid << std::endl;
    if (source->HasComponent(engine::core::ComponentID::PHY_RIGIDBODY)) {
        std::cout << "In comment" << std::endl;
        auto *body = static_cast<engine::physics::RigidBodyComponent *>(source->GetComponent(engine::core::ComponentID::PHY_RIGIDBODY));
        std::cout << "In comment 2" << std::endl;
        auto *player = static_cast<game::PlayerComponent *>(source->GetComponent(engine::core::ComponentID::GAME_PLAYER));
        std::cout << "Before vectore" << std::endl;
        engine::core::Vector2d vel(0, 0);
        switch (action) {
            case game::PlayerActionMessage::Action::GO_UP:
                vel.setY(-player->getSpeed());
                break;
            case game::PlayerActionMessage::Action::GO_DOWN:
                vel.setY(player->getSpeed());
                break;
            case game::PlayerActionMessage::Action::GO_RIGHT:
                vel.setX(player->getSpeed());
                break;
            case game::PlayerActionMessage::Action::GO_LEFT:
                vel.setX(-player->getSpeed());
                break;
        }
        std::cout << "Before velocity" << std::endl;
        body->setVelocity(vel);
        std::cout << "Before update" << std::endl;
        body->Update(this->_currentDt);
        std::cout << "Before end" << std::endl;
    }
}

void game::GameLogicClientSystem::move(engine::core::GameObject *source, int x, int y){
    source->pos.setX(x);
    source->pos.setY(y);
}
