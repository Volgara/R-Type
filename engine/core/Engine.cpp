//
//-----------------------------------------------------------------------------
//Filename:    Engine.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/9/18.
//-----------------------------------------------------------------------------
//

#include <graphics/SpriteComponent.hpp>
#include <iostream>
#include "Engine.hpp"

/**
 * Get's system with ID
 * @param systemId
 * @return
 */
engine::core::ASystem *engine::core::Engine::getSystem(const std::string &systemId) {
    return _systems[systemId];
}

/**
 * Update each system with the delta-time
 * @param dt
 */
void engine::core::Engine::Update(float dt) {
    for (auto system : _systems) {
        system.second->Update(dt);
    }
}

void engine::core::Engine::MainLoop(void) {
    while (_gameRunning) {
        _window.clear();
        Update(1);
        _window.display();
    }
}

void engine::core::Engine::Init(void) {
    _gameRunning = true;
    _window.create(sf::VideoMode(800, 600), "toto");

    if (!_window.isOpen()) {
        std::cout << "windows is closed" << std::endl;
        exit(EXIT_FAILURE);
    }

    for (auto sys : _systems) {
        sys.second->Init();
    }

    // TODO : replace by Scene loader
    auto *gm = GameObjectManager::GetInstance();
    auto object = new GameObject();

    object->addComponent(1, new graphics::SpriteComponent);

    gm->addObject(1, object);
}

sf::RenderWindow &engine::core::Engine::getWindow() {
    return _window;
}

void engine::core::Engine::addSystem(const std::string &systemId, engine::core::ASystem *system) {
    _systems[systemId] = system;
}

void engine::core::Engine::constructor() {
    Init();
}
