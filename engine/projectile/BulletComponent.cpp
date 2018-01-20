//
// Created by Hamza Hammouche on 20/01/2018.
//

#include "BulletComponent.hpp"

engine::projectile::BulletComponent::BulletComponent() : Component(engine::core::PHY_RIGIDBODY) {}

engine::projectile::BulletComponent::~BulletComponent() {}

void engine::projectile::BulletComponent::SendMessage(engine::core::Message *) {}

void engine::projectile::BulletComponent::Update(float dt) {
    if (this->_body == nullptr)
        return;
    this->_body->Update(dt);
}

void engine::projectile::BulletComponent::Init() {
    if (this->ownerRef && this->ownerRef->HasComponent(core::ComponentID::PHY_RIGIDBODY))
        this->_body = dynamic_cast<physics::RigidBodyComponent *>(this->ownerRef->GetComponent(core::ComponentID::PHY_RIGIDBODY));
    else
        this->_body = nullptr;
}

void engine::projectile::BulletComponent::ShutDown() {}
