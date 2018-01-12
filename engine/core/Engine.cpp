//
//-----------------------------------------------------------------------------
//Filename:    Engine.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/9/18.
//-----------------------------------------------------------------------------
//

#include "Engine.hpp"

engine::core::Engine::Engine() : _gameRunning(true), _window(sf::VideoMode(800, 600), "HelloSFML") {
    Init();
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
    while (_gameRunning) {
        _window.clear();
        _window.display();
    }
}

engine::core::Engine::~Engine() {
    for (auto system : _systems) {
        delete(system.second);
    }
}

void engine::core::Engine::Init(void) {
    if (!_window.isOpen())
        exit(EXIT_FAILURE);
}

sf::RenderWindow &engine::core::Engine::getWindow() {
    return _window;
}
