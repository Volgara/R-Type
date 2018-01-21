//
// Created by macdoy on 21/01/18.
//

#include "GameLogicClientSystem.hpp"

game::GameLogicClientSystem::GameLogicClientSystem() {}


void game::GameLogicClientSystem::Update(float dt) {
    this->_currentDt = dt;
}

void game::GameLogicClientSystem::Init() {}

void game::GameLogicClientSystem::onNotify(engine::core::Message message) {
    if (message.id == engine::core::MessageID::MOVE_PLAYER) {
        auto *eg = engine::core::Engine::GetInstance();
        auto *movePlayer = static_cast<engine::core::MovePlayer *>(&message);

        engine::core::GameObject *source = eg->getScene()->GetGameObject(movePlayer->source);
        this->movePlayer(source, movePlayer->direction);
    }
}

void game::GameLogicClientSystem::movePlayer(engine::core::GameObject *source, engine::core::Direction dir) {
    if (source->HasComponent(engine::core::ComponentID::PHY_RIGIDBODY)) {
        auto *body = dynamic_cast<engine::physics::RigidBodyComponent *>(source->GetComponent(engine::core::ComponentID::PHY_RIGIDBODY));
        auto *player = dynamic_cast<game::PlayerComponent *>(source->GetComponent(engine::core::ComponentID::GAME_PLAYER));
        engine::core::Vector2d vel(0, 0);

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
                vel.setX(-player->getSpeed());
                break;
        }
        body->setVelocity(vel);
        body->Update(this->_currentDt);
    }
}
