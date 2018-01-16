//
// Created by Hamza Hammouche on 12/01/2018.
//

#include "RigidBodyComponent.hpp"

engine::physics::RigidBodyComponent::RigidBodyComponent() : Component(engine::core::PHY_RIGIDBODY) {
    this->_box = new Box(this->_position, this->_size);
}

engine::physics::RigidBodyComponent::~RigidBodyComponent() {
    if (!this->_box)
        return;
    delete this->_box;
}


const engine::core::Vector2d &engine::physics::RigidBodyComponent::getPosition() const {
    return _position;
}

void engine::physics::RigidBodyComponent::setPosition(const engine::core::Vector2d &position) {
    this->_position = position;
    _box->updatePosition(this->_position, this->_size);
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
    this->_size = size;
    _box->updatePosition(this->_position, this->_size);
}

void engine::physics::RigidBodyComponent::move() {
    this->_position.setX(this->_position.getX() + this->_velocity.getX());
    this->_position.setY(this->_position.getY() + this->_velocity.getY());
    _box->updatePosition(this->_position, this->_size);
}

void engine::physics::RigidBodyComponent::SendMessage(Message *) {

}

void engine::physics::RigidBodyComponent::Update(float) {

}

void engine::physics::RigidBodyComponent::Init(void) {

}

void engine::physics::RigidBodyComponent::ShutDown(void) {

}

engine::physics::Box *engine::physics::RigidBodyComponent::getBox() const {
    return _box;
}

bool engine::physics::RigidBodyComponent::checkIntersect(const engine::physics::RigidBodyComponent *body) {
    return this->_box->intersectBox(body->getBox());
}
