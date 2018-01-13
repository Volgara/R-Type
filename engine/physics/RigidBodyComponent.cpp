//
// Created by Hamza Hammouche on 12/01/2018.
//

#include "RigidBodyComponent.hpp"

engine::physics::RigidBodyComponent::RigidBodyComponent(Vector2d position,
                                                        Vector2d velocity, Vector2d size)
        : _position(position), _velocity(velocity), _size(size)
{
    this->_box = new Box(position, size);
}

engine::physics::RigidBodyComponent::~RigidBodyComponent() {
    if (!this->_box)
        return;
    delete this->_box;
}


const engine::physics::Vector2d &engine::physics::RigidBodyComponent::getPosition() const {
    return _position;
}

void engine::physics::RigidBodyComponent::setPosition(const engine::physics::Vector2d &_position) {
    RigidBodyComponent::_position = _position;
    _box->updatePosition(this->_position, this->_size);
}

const engine::physics::Vector2d &engine::physics::RigidBodyComponent::getVelocity() const {
    return _velocity;
}

void engine::physics::RigidBodyComponent::setVelocity(const engine::physics::Vector2d &_velocity) {
    RigidBodyComponent::_velocity = _velocity;
}

const engine::physics::Vector2d &engine::physics::RigidBodyComponent::getSize() const {
    return _size;
}

void engine::physics::RigidBodyComponent::setSize(const engine::physics::Vector2d &_size) {
    RigidBodyComponent::_size = _size;
    _box->updatePosition(this->_position, this->_size);
}

void engine::physics::RigidBodyComponent::move() {
    this->_position.setX(this->_position.getX() + this->_velocity.getX());
    this->_position.setY(this->_position.getY() + this->_velocity.getY());
}

void engine::physics::RigidBodyComponent::SendMessage(Message *message) {

}

void engine::physics::RigidBodyComponent::Update(float dt) {

}

void engine::physics::RigidBodyComponent::Init(void) {

}

void engine::physics::RigidBodyComponent::ShutDown(void) {

}
