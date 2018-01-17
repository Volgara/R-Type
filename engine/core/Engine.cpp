//
//-----------------------------------------------------------------------------
//Filename:    Engine.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/9/18.
//-----------------------------------------------------------------------------
//

#include <iostream>
#include "Engine.hpp"
#include "GameObject.hpp"

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
    // listen for events on the window
    for (auto system : _systems) {
        system.second->Update(dt);
    }
}

/**
 * Main Loop
 * Execute and Update windows
 */
void engine::core::Engine::MainLoop(void) {
#ifdef GRAPHICS
    while (_gameRunning) {
        const auto elapsed = _clock.getElapsedTime().asSeconds();
        if (elapsed >= 1.0f / 60)
        {
            _window.clear();
            Update(elapsed);
            _window.display();
            _clock.restart();
        }

    }
#endif
}

void engine::core::Engine::Init(void) {
    _gameRunning = true;

#ifdef GRAPHICS
    _window.create(sf::VideoMode(800, 600), "toto");

    if (!_window.isOpen()) {
        std::cout << "windows is closed" << std::endl;
        exit(EXIT_FAILURE);
    }
#endif

    _scene = new Scene();

#ifdef GRAPHICS
    auto *object = _scene->CreateEmptyObject();
    auto *spriteComponent = _scene->CreateComponent(GRA_SPRITE);
    object->AddComponent(spriteComponent);
#endif

    for (auto sys : _systems) {
        sys.second->Init();
    }
}

#ifdef GRAPHICS

sf::RenderWindow &engine::core::Engine::getWindow() {
    return _window;
}

#endif

void engine::core::Engine::addSystem(const std::string &systemId, engine::core::ASystem *system) {
    _systems[systemId] = system;
}

void engine::core::Engine::constructor() {

}

engine::core::Scene *engine::core::Engine::getScene() {
    return _scene;
}

bool engine::core::Engine::isRunning() const {
    return _gameRunning;
}

void engine::core::Engine::Shutdown(void) {
#ifdef GRAPHICS
    _window.close();
#endif
}

void engine::core::Engine::addMessage(void) {

}
