//
// Created by macdoy on 18/01/18.
//

#include "BulletComponent.hpp"

game::BulletComponent::BulletComponent() : Component(engine::core::BULLET) {
    // TODO add a type to the owner
    _type = ALLY;
}

game::BulletComponent::~BulletComponent() {
}

void game::BulletComponent::SendMessage(engine::core::Message *message) {
    return;
}

void game::BulletComponent::Update(float dt) {
    std::cout << "yo . " << dt << std::endl;
}

void game::BulletComponent::Init() {
}

void game::BulletComponent::ShutDown() {
    return;
}