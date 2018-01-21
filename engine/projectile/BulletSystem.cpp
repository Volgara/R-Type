//
// Created by Hamza Hammouche on 20/01/2018.
//

#include "BulletSystem.hpp"

engine::projectile::BulletSystem::BulletSystem(int width, int height) : _width(width), _height(height) {}

engine::projectile::BulletSystem::~BulletSystem() {}


void engine::projectile::BulletSystem::Update(float dt) {
    auto *eg = core::Engine::GetInstance();

    auto it = eg->getScene()->GetComponents<BulletComponent>(core::ComponentID::PRO_BULLET)->begin();
    for (;it != eg->getScene()->GetComponents<BulletComponent>(core::ComponentID::PRO_BULLET)->end();) {
        core::Component *component = *it;

        if (component->ownerRef->pos.getY() < this->_height && component->ownerRef->pos.getY() > 0
            && component->ownerRef->pos.getX() > 0 && component->ownerRef->pos.getX() < this->_width) {
            component->Update(dt * 60);
            ++it;
        }
        else {
            eg->getScene()->RemoveGameObject(component->owner);
            it = eg->getScene()->GetComponents<BulletComponent>(core::ComponentID::PRO_BULLET)->erase(it);
        }
    }
    eg->getScene()->cleanUp();
}

void engine::projectile::BulletSystem::Init() {}

void engine::projectile::BulletSystem::onNotify(core::Message *) {}
