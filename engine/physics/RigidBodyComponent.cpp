//
// Created by Hamza Hammouche on 12/01/2018.
//

#include <core/GameObject.hpp>
#include "RigidBodyComponent.hpp"

engine::physics::RigidBodyComponent::RigidBodyComponent() : Component(engine::core::PHY_RIGIDBODY) {
    this->_size = core::Vector2d(0, 0);
}

engine::physics::RigidBodyComponent::~RigidBodyComponent() {
    if (!this->_box)
        return;
    delete this->_box;
}

const engine::core::Vector2d &engine::physics::RigidBodyComponent::getVelocity() const {
    return _velocity;
}

void engine::physics::RigidBodyComponent::setVelocity(const engine::core::Vector2d &velocity) {
    this->_velocity = velocity;
}

const engine::core::Vector2d &engine::physics::RigidBodyComponent::getSize() const {
    return _size;
}

void engine::physics::RigidBodyComponent::setSize(const engine::core::Vector2d &size) {
    this->_size.setY(size.getY());
    this->_size.setX(size.getX());
}

void engine::physics::RigidBodyComponent::SendMessage(engine::core::Message *msg) {

}

void engine::physics::RigidBodyComponent::Update(float dt) {
    this->ownerRef->pos.setX(static_cast<int>((this->ownerRef->pos.getX() + this->_velocity.getX()) * dt));
    this->ownerRef->pos.setY(static_cast<int>((this->ownerRef->pos.getY() + this->_velocity.getY()) * dt));
}

void engine::physics::RigidBodyComponent::Init(void) {
    this->_box = new Box(&this->ownerRef->pos, &this->_size);
}

void engine::physics::RigidBodyComponent::ShutDown(void) {

}

engine::physics::Box *engine::physics::RigidBodyComponent::getBox() const {
    return _box;
}

bool engine::physics::RigidBodyComponent::checkIntersect(const engine::physics::RigidBodyComponent *body) {
    return this->_box->intersectBox(body->getBox());
}
