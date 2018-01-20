//
// Created by Hamza Hammouche on 20/01/2018.
//

#include "BulletSystem.hpp"

engine::projectile::BulletSystem::BulletSystem(int width, int height) : _width(width), _height(height) {}

engine::projectile::BulletSystem::~BulletSystem() {}


void engine::projectile::BulletSystem::Update(float dt) {
    auto *eg = core::Engine::GetInstance();

    for (auto &it : *eg->getScene()->GetComponents<BulletComponent>(core::ComponentID::PRO_BULLET)) {
        if (it->ownerRef->pos.getY() < this->_height && it->ownerRef->pos.getY() > 0
            && it->ownerRef->pos.getX() > 0 && it->ownerRef->pos.getX() < this->_width)
            it->Update(dt);
        else
            eg->getScene()->RemoveGameObject(it->owner);
    }
    eg->getScene()->cleanUp();
}

void engine::projectile::BulletSystem::Init() {}

void engine::projectile::BulletSystem::onNotify(core::Message) {}
