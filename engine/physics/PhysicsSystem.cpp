//
// Created by Hamza Hammouche on 14/01/2018.
//

#include <iostream>
#include <core/Engine.hpp>
#include "PhysicsSystem.hpp"

engine::physics::PhysicsSystem::PhysicsSystem(int width, int) {
    this->_width = width / CELL_SIZE;
    Init();
}

void engine::physics::PhysicsSystem::Update(float dt) {
    this->_debugNbCollision = 0;
    this->_debugNb = 0;
    this->_debugNbAdd = 0;
    this->_debugCheck = 0;
    if (dt == 1) {
        engine::core::Message message(engine::core::MessageID::COLLISION);
        sendMsg(message);
        return;
    }
    this->clearMap();
    if (dt == -1)
        this->createHasheMapDebug();
    else
        this->createHasheMap();
    for (auto &it : this->_listState) {
        this->checkCellColision(it.second);
    }
}

void engine::physics::PhysicsSystem::Init() {
    this->_debugNbCollision = 0;
    this->_debugNb = 0;
    this->_debugNbAdd = 0;
}

void engine::physics::PhysicsSystem::debugAddComponent(engine::physics::RigidBodyComponent *c) {
    this->_listDebug.push_back(c);
}

void engine::physics::PhysicsSystem::clearMap() {
    this->_listState.clear();
    this->_currentCollision.clear();
}

void engine::physics::PhysicsSystem::createHasheMapDebug() {
    for (auto &i : this->_listDebug) {
        addComponentInMap(i);
        this->_debugNbAdd++;
    }
}

void engine::physics::PhysicsSystem::createHasheMap() {
    auto *eg = engine::core::Engine::GetInstance();

    for (auto &body : *eg->getScene()->GetComponents<RigidBodyComponent>(core::ComponentID::PHY_RIGIDBODY)) {
        addComponentInMap(body);
    }
}

void engine::physics::PhysicsSystem::addComponentInMap(engine::physics::RigidBodyComponent *comp) {
    Box *box = comp->getBox();
    core::Vector2d width(box->getLeft() / CELL_SIZE, box->getRight() / CELL_SIZE);
    core::Vector2d height(box->getTop() / CELL_SIZE, box->getBottom() / CELL_SIZE);

    for (int i = width.getX(); i <= width.getY(); i++) {
        for (int j = height.getX(); j <= height.getY(); j++) {
            this->_listState[this->_width * i + j].push_back(comp);
            this->_debugNb++;
        }
    }
}

void engine::physics::PhysicsSystem::onNotify(engine::core::Message message) {
    auto *eg = engine::core::Engine::GetInstance();
    for (auto &body : *eg->getScene()->GetComponents<RigidBodyComponent>(core::ComponentID::PHY_RIGIDBODY)) {
        body->SendMessage(&message);
    }
    std::cout << "PhysicsSystem receive Message : " << message.id << std::endl;
}

void engine::physics::PhysicsSystem::checkCellColision(std::vector<RigidBodyComponent *> vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (vec[i]->checkIntersect(vec[j])) {
                if (this->addCollision(vec[i], vec[j])) {
                    this->_debugNbCollision++;
                }
            }
            this->_debugCheck++;
        }
    }
}

bool engine::physics::PhysicsSystem::addCollision(engine::physics::RigidBodyComponent *two,
                                                  engine::physics::RigidBodyComponent *one) {
    for (auto &it : this->_currentCollision) {
        if ((it.first == one && it.second == two)
            || (it.second == one && it.first == two))
            return false;
    }
    this->_currentCollision.emplace_back(one, two);
    return true;
}

int engine::physics::PhysicsSystem::get_debugNbAdd() const {
    return _debugNbAdd;
}

int engine::physics::PhysicsSystem::get_debugNbColision() const {
    return _debugNbCollision;
}

int engine::physics::PhysicsSystem::get_debugNb() const {
    return _debugNb;
}

int engine::physics::PhysicsSystem::get_debugCheck() const {
    return _debugCheck;
}

