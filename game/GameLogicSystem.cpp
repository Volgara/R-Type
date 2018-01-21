//
//-----------------------------------------------------------------------------
//Filename:    GameLogicSystem.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/16/18.
//-----------------------------------------------------------------------------
//

#include "GameLogicSystem.hpp"
#include "Message.hpp"


game::GameLogicSystem::GameLogicSystem(int _height, int _width) : _height(_height), _width(_width) {}


void game::GameLogicSystem::Update(float dt) {
    this->_currentDt = dt;
}

void game::GameLogicSystem::Init() {}

void game::GameLogicSystem::onNotify(engine::core::Message message) {
    if (message.id == engine::core::InternalMessageID::COLLISION) {
        auto *eg = engine::core::Engine::GetInstance();
        auto *collision2D = static_cast<engine::core::Collision2D *>(&message);

        engine::core::GameObject *target = eg->getScene()->GetGameObject(collision2D->target);
        engine::core::GameObject *source = eg->getScene()->GetGameObject(collision2D->source);
        this->checkColision(target, source);
    }
    else if (message.id == game::GameMessageID::PLAYER_ACTION) {
        auto *eg = engine::core::Engine::GetInstance();
        auto *movePlayer = static_cast<game::PlayerActionMessage *>(&message);

        engine::core::GameObject *source = eg->getScene()->GetGameObject(movePlayer->m_ref->guid);
        this->playAction(source, movePlayer->getAction());
    }
}

void game::GameLogicSystem::checkColision(engine::core::GameObject *target, engine::core::GameObject *source) {
    if (target->HasComponent(engine::core::ComponentID::GAME_PLAYER) && source->HasComponent(engine::core::ComponentID::PRO_BULLET)) {
        this->addDamageToPlayer(dynamic_cast<game::PlayerComponent *>(target->GetComponent(engine::core::ComponentID::GAME_PLAYER)), dynamic_cast<engine::projectile::BulletComponent *>(source->GetComponent(engine::core::ComponentID::PRO_BULLET)));
    } else if (target->HasComponent(engine::core::ComponentID::PRO_BULLET) && source->HasComponent(engine::core::ComponentID::GAME_PLAYER)) {
        this->addDamageToPlayer(dynamic_cast<game::PlayerComponent *>(source->GetComponent(engine::core::ComponentID::GAME_PLAYER)), dynamic_cast<engine::projectile::BulletComponent *>(target->GetComponent(engine::core::ComponentID::PRO_BULLET)));
    }
}

void game::GameLogicSystem::addDamageToPlayer(game::PlayerComponent *player, engine::projectile::BulletComponent *bullet) {
    player->takeDamage(bullet->getDamage());
}

void game::GameLogicSystem::playAction(engine::core::GameObject *source, PlayerActionMessage::Action action) {
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
