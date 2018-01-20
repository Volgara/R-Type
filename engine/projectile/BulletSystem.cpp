//
// Created by Hamza Hammouche on 20/01/2018.
//

#include "BulletSystem.hpp"

engine::projectile::BulletSystem::BulletSystem() {}

engine::projectile::BulletSystem::~BulletSystem() {}


void engine::projectile::BulletSystem::Update(float dt) {
    auto *eg = core::Engine::GetInstance();

    for (auto &it : *eg->getScene()->GetComponents<BulletComponent>(core::ComponentID::PRO_BULLET))
        it->Update(dt);
}

void engine::projectile::BulletSystem::Init() {}

void engine::projectile::BulletSystem::onNotify(core::Message) {}
