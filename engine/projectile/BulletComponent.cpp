//
// Created by Hamza Hammouche on 20/01/2018.
//

#include "BulletComponent.hpp"

engine::projectile::BulletComponent::BulletComponent() : Component(engine::core::PHY_RIGIDBODY) {}

engine::projectile::BulletComponent::~BulletComponent() {}

void engine::projectile::BulletComponent::SendMessage(engine::core::Message *) {}

void engine::projectile::BulletComponent::Update(float dt) {
    this->_body->Update(dt);
}

void engine::projectile::BulletComponent::Init() {
    if (this->ownerRef && this->ownerRef->HasComponent(core::ComponentID::PHY_RIGIDBODY))
        this->_body = dynamic_cast<physics::RigidBodyComponent *>(this->ownerRef->GetComponent(core::ComponentID::PHY_RIGIDBODY));
    else
        throw std::runtime_error("Cannot use BulletComponent without RigidBodyComponent");
}

void engine::projectile::BulletComponent::ShutDown() {}
