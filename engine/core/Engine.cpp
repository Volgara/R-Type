//
//-----------------------------------------------------------------------------
//Filename:    Engine.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/9/18.
//-----------------------------------------------------------------------------
//

#include "Engine.hpp"

engine::core::Engine::Engine() : _gameRunning(false) {

};

void engine::core::Engine::addSystem(const std::string &systemId, engine::core::ISystem *system) {
    _systems[systemId] = system;
}

engine::core::ISystem *engine::core::Engine::getSystem(const std::string &systemId) {
    return _systems[systemId];
}

void engine::core::Engine::Update(float dt) {
    for (auto system : _systems) {
        system.second->Update(dt);
    }
}

void engine::core::Engine::MainLoop(void) {

}