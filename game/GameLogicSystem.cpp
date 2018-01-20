//
//-----------------------------------------------------------------------------
//Filename:    GameLogicSystem.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/16/18.
//-----------------------------------------------------------------------------
//

#include "GameLogicSystem.hpp"


game::GameLogicSystem::GameLogicSystem(int _height, int _width) : _height(_height), _width(_width) {}


void game::GameLogicSystem::Update(float) {

}

void game::GameLogicSystem::Init() {}


void game::GameLogicSystem::onNotify(engine::core::Message message) {
    if (message.id == engine::core::MessageID::COLLISION) {
        auto *eg = engine::core::Engine::GetInstance();
        auto *collision2D = dynamic_cast<engine::core::Collision2D *>(&message);

        engine::core::GameObject *target = eg->getScene()->GetGameObject(collision2D->target);
        engine::core::GameObject *source = eg->getScene()->GetGameObject(collision2D->source);
        this->checkColision(target, source);
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
