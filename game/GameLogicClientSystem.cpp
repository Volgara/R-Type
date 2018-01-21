//
// Created by macdoy on 21/01/18.
//

#include "GameLogicClientSystem.hpp"
#include "Message.hpp"

game::GameLogicClientSystem::GameLogicClientSystem() {}


void game::GameLogicClientSystem::Update(float dt) {
    this->_currentDt = dt;
}

void game::GameLogicClientSystem::Init() {}

void game::GameLogicClientSystem::onNotify(engine::core::Message message) {
    if (message.id == game::GameMessageID::PLAYER_ACTION) {
        auto *eg = engine::core::Engine::GetInstance();
        auto *movePlayer = static_cast<game::PlayerActionMessage *>(&message);

        engine::core::GameObject *source = eg->getScene()->GetGameObject(movePlayer->m_ref->guid);
        this->playAction(source, movePlayer->getAction());
    }
    else if (message.id == game::GameMessageID::SERVER_ACTION) {
        auto *eg = engine::core::Engine::GetInstance();
        auto *move = static_cast<game::ServerActionMessage *>(&message);

        engine::core::GameObject *source = eg->getScene()->GetGameObject(move->getSource());
        this->move(source, move->getPos().getX(), move->getPos().getY());
    }
}

void game::GameLogicClientSystem::playAction(engine::core::GameObject *source, PlayerActionMessage::Action action) {
    if (source->HasComponent(engine::core::ComponentID::PHY_RIGIDBODY)) {
        auto *body = dynamic_cast<engine::physics::RigidBodyComponent *>(source->GetComponent(engine::core::ComponentID::PHY_RIGIDBODY));
        auto *player = dynamic_cast<game::PlayerComponent *>(source->GetComponent(engine::core::ComponentID::GAME_PLAYER));
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
        body->setVelocity(vel);
        body->Update(this->_currentDt);
    }
}

void game::GameLogicClientSystem::move(engine::core::GameObject *source, int x, int y){
    source->pos.setX(x);
    source->pos.setY(y);
}
