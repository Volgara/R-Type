//
// Created by macdoy on 21/01/18.
//

#include "GameLogicClientSystem.hpp"
<<<<<<< HEAD
#include "Message.hpp"
=======
>>>>>>> 4fcbf692e2494b4a0ba20117eb300cca20968a44

game::GameLogicClientSystem::GameLogicClientSystem() {}


void game::GameLogicClientSystem::Update(float dt) {
    this->_currentDt = dt;
}

void game::GameLogicClientSystem::Init() {}

void game::GameLogicClientSystem::onNotify(engine::core::Message message) {
<<<<<<< HEAD
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
=======
    if (message.id == engine::core::MessageID::MOVE_PLAYER) {
        auto *eg = engine::core::Engine::GetInstance();
        auto *movePlayer = static_cast<engine::core::MovePlayer *>(&message);

        engine::core::GameObject *source = eg->getScene()->GetGameObject(movePlayer->source);
        this->movePlayer(source, movePlayer->direction);
    }
    else if (message.id == engine::core::MessageID::MOVE) {
        auto *eg = engine::core::Engine::GetInstance();
        auto *move = static_cast<engine::core::Move *>(&message);

        engine::core::GameObject *source = eg->getScene()->GetGameObject(move->source);
        this->move(source, move->x, move->y);
    }
}

void game::GameLogicClientSystem::movePlayer(engine::core::GameObject *source, engine::core::Direction dir) {
>>>>>>> 4fcbf692e2494b4a0ba20117eb300cca20968a44
    if (source->HasComponent(engine::core::ComponentID::PHY_RIGIDBODY)) {
        auto *body = dynamic_cast<engine::physics::RigidBodyComponent *>(source->GetComponent(engine::core::ComponentID::PHY_RIGIDBODY));
        auto *player = dynamic_cast<game::PlayerComponent *>(source->GetComponent(engine::core::ComponentID::GAME_PLAYER));
        engine::core::Vector2d vel(0, 0);

<<<<<<< HEAD
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
=======
        switch (dir) {
            case engine::core::UP:
                vel.setY(-player->getSpeed());
                break;
            case engine::core::DOWN:
                vel.setY(player->getSpeed());
                break;
            case engine::core::RIGHT:
                vel.setX(player->getSpeed());
                break;
            case engine::core::LEFT:
>>>>>>> 4fcbf692e2494b4a0ba20117eb300cca20968a44
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
