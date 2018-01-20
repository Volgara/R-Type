//
// Created by Hamza Hammouche on 14/01/2018.
//

#include <iostream>
#include <core/Engine.hpp>
#include "PhysicsSystem.hpp"

engine::physics::PhysicsSystem::PhysicsSystem(int width, int height) {
    int hCell = height / CELL_SIZE;
    this->_wCell = width / CELL_SIZE;
    this->_sizeTab = hCell * this->_wCell;
    Init();
}

void engine::physics::PhysicsSystem::Update(float dt) {
    this->_debugNbCollision = 0;
    this->_debugCheck = 0;
    this->clearMap();
    if (dt == -1)
        this->createHasheMapDebug();
    else
        this->createHasheMap();
    for (auto &it : this->_listState) {
        this->checkCellCollision(it.second);
    }
}

void engine::physics::PhysicsSystem::Init() {
    this->_debugNbCollision = 0;
    this->_debugCheck = 0;
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
    int cell = 0;

    core::Vector2d width(box->getLeft() / CELL_SIZE, box->getRight() / CELL_SIZE);
    core::Vector2d height(box->getTop() / CELL_SIZE, box->getBottom() / CELL_SIZE);
    for (int i = width.getX(); i <= width.getY(); i++) {
        for (int j = height.getX(); j <= height.getY(); j++) {
            cell = this->_wCell * i + j;
            if (cell > 0 && cell < this->_sizeTab)
                this->_listState[cell].push_back(comp);
        }
    }
}

void engine::physics::PhysicsSystem::onNotify(engine::core::Message message) {
    std::cout << "PhysicsSystem receive Message : " << message.id << std::endl;
}

void engine::physics::PhysicsSystem::checkCellCollision(std::vector<RigidBodyComponent *> vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (vec[i]->checkIntersect(vec[j])) {
                if (this->addCollision(vec[i], vec[j])) {
                    core::Collision2D msg;
                    msg.source = vec[i]->owner;
                    msg.target = vec[j]->owner;
                    //sendMsg(msg);
                    this->_debugNbCollision++;
                }
            }
            this->_debugCheck++;
        }
    }
}

bool engine::physics::PhysicsSystem::addCollision(engine::physics::RigidBodyComponent *two,
                                                  engine::physics::RigidBodyComponent *one) {
    if (two == one)
        return false;
    for (auto &it : this->_currentCollision) {
        if ((it.first == one && it.second == two)
            || (it.second == one && it.first == two))
            return false;
    }
    this->_currentCollision.emplace_back(one, two);
    return true;
}

int engine::physics::PhysicsSystem::get_debugNbColision() const {
    return this->_debugNbCollision;
}

int engine::physics::PhysicsSystem::get_debugCheck() const {
    return this->_debugCheck;
}
