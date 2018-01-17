//
// Created by Hamza Hammouche on 14/01/2018.
//

#include <iostream>
#include <core/Engine.hpp>
#include "PhysicsSystem.hpp"

engine::physics::PhysicsSystem::PhysicsSystem(int width, int height) {
    this->_width = width / CELL_SIZE;
    this->_height = height / CELL_SIZE;
    Init();
}

void engine::physics::PhysicsSystem::Update(float) {
    this->_debugNbCollision = 0;
    this->_debugNb = 0;
    this->_debugNbAdd = 0;
    this->_debugCheck = 0;

    this->clearMap();
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

void engine::physics::PhysicsSystem::SendMessage(engine::core::Message *msg) {
    auto *eg = engine::core::Engine::GetInstance();
    for (auto sprite : *eg->getScene()->GetComponents<RigidBodyComponent>(core::ComponentID::GRA_SPRITE)) {
        sprite->SendMessage(msg);
    }
}

void engine::physics::PhysicsSystem::debugAddComponent(engine::physics::RigidBodyComponent *c) {
    this->_listDebug.push_back(c);
}

void engine::physics::PhysicsSystem::clearMap() {
    this->_listState.clear();
    this->_currentCollision.clear();
}

void engine::physics::PhysicsSystem::createHasheMap() {
    for (auto &i : this->_listDebug) {
        addComponentInMap(i);
        this->_debugNbAdd++;
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

void engine::physics::PhysicsSystem::checkCellColision(std::vector<RigidBodyComponent *> vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (vec[i]->checkIntersect(vec[j])) {
                if (this->addCollision(vec[i], vec[j]))
                    this->_debugNbCollision++;
            }
            this->_debugCheck++;
        }
    }
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
