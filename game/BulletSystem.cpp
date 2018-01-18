//
// Created by macdoy on 18/01/18.
//

#include "BulletSystem.hpp"

game::BulletSystem::BulletSystem() {
}

game::BulletSystem::~BulletSystem() {
}

void game::BulletSystem::Init() {
    return;
}

void game::BulletSystem::Update(float dt) {
    auto *eg = engine::core::Engine::GetInstance();

    std::cout << "debug 2\n";
    for (auto &body : *eg->getScene()->GetComponents<BulletComponent>(engine::core::ComponentID::BULLET)) {
        std::cout << "debug 4\n";
        body->Update(dt);
        std::cout << "debug 5\n";
    }
    std::cout << "debug 3\n";
}

void game::BulletSystem::onNotify(engine::core::Message message) {
    auto *eg = engine::core::Engine::GetInstance();
    for (auto &body : *eg->getScene()->GetComponents<BulletComponent>(engine::core::ComponentID::BULLET)) {
        body->SendMessage(&message);
    }
    std::cout << "BulletSystem receive Message : " << message.id << std::endl;
}
