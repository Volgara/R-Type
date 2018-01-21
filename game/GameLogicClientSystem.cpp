//
// Created by macdoy on 21/01/18.
//

#include "GameLogicClientSystem.hpp"

game::GameLogicClientSystem::GameLogicClientSystem(int width, int height) : _width(width), _height(height) {}


void game::GameLogicClientSystem::Update(float dt) {
    this->_currentDt = dt;
}

void game::GameLogicClientSystem::Init() {}

void game::GameLogicClientSystem::onNotify(engine::core::Message *message) {
    if (message->id == game::GameMessageID::PLAYER_ACTION) {
        auto *movePlayer = static_cast<game::PlayerActionMessage *>(message);

        engine::core::GameObject *source = movePlayer->m_ref;
        this->playAction(source, movePlayer->getAction());
    }
    else if (message->id == game::GameMessageID::SERVER_ACTION) {
        auto *eg = engine::core::Engine::GetInstance();
        auto *move = static_cast<game::ServerActionMessage *>(message);

        engine::core::GameObject *source = eg->getScene()->GetGameObject(move->getSource());
        this->move(source, move->getPos().getX(), move->getPos().getY());
    }
}

void game::GameLogicClientSystem::playAction(engine::core::GameObject *source, PlayerActionMessage::Action action) {
    if (source->HasComponent(engine::core::ComponentID::PHY_RIGIDBODY) &&
            source->HasComponent(engine::core::ComponentID::GAME_PLAYER)) {
        auto *body = static_cast<engine::physics::RigidBodyComponent *>(source->GetComponent(engine::core::ComponentID::PHY_RIGIDBODY));
        auto *player = static_cast<game::PlayerComponent *>(source->GetComponent(engine::core::ComponentID::GAME_PLAYER));
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
            case PlayerActionMessage::SHOOT:
                this->playerShoot(body->ownerRef);
                return;
        }
        body->setVelocity(vel);
        body->Update(this->_currentDt * 60);
    }
}

void game::GameLogicClientSystem::move(engine::core::GameObject *source, int x, int y){
    source->pos.setX(x);
    source->pos.setY(y);
}

void game::GameLogicClientSystem::playerShoot(engine::core::GameObject *player) {
    auto *eg = engine::core::Engine::GetInstance();

    if (this->_shoot == 1)
        return;
    core::GameObject *game = eg->getScene()->CreateEmptyObject();
    game->pos.setX(player->pos.getX());
    game->pos.setY(player->pos.getY());
    engine::projectile::BulletComponent *bullet1 = static_cast<engine::projectile::BulletComponent *>(eg->getScene()->CreateComponent(core::ComponentID::PRO_BULLET));
    engine::physics::RigidBodyComponent *comp2 = static_cast<engine::physics::RigidBodyComponent *>(eg->getScene()->CreateComponent(core::ComponentID::PHY_RIGIDBODY));
    game->attachComponent(bullet1);
    game->attachComponent(comp2);
    comp2->setVelocity(core::Vector2d(3, 0));
    comp2->setSize(core::Vector2d(10, 10));
    game->attachComponent(bullet1);
    game->attachComponent(comp2);
    comp2->Init();
    bullet1->Init();
    engine::graphics::GraphicsComponent *spriteComponent = static_cast<engine::graphics::GraphicsComponent *>(eg->getScene()->CreateComponent(engine::core::ComponentID::GRA_SPRITE));
    engine::graphics::SpriteSheet shipSheet = engine::graphics::SpriteSheet("assets/ship.png", 192, 16, 6, 1);
    engine::graphics::Animation *shipAnimIdle = new engine::graphics::Animation("idle", &shipSheet);
    shipAnimIdle->addFrame(0, 0);
    shipAnimIdle->addFrame(0, 1);
    shipAnimIdle->addFrame(0, 2);
    spriteComponent->addAnimation(shipAnimIdle);
    game->attachComponent(spriteComponent);
    this->_shoot = 1;
}
