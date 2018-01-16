//
//-----------------------------------------------------------------------------
//Filename:    Engine.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/9/18.
//-----------------------------------------------------------------------------
//
#ifdef GRAPHICS
#include <graphics/GraphicsComponent.hpp>
#endif
#include <physics/RigidBodyComponent.hpp>
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
#ifdef GRAPHICS
    if (_window.isOpen()) {
        std::cout << "Checking for events" << std::endl;
        sf::Event event;
        while (_window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                _window.close();
        }
    }
#endif

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
        _window.clear();
        Update(1);
        _window.display();
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


    for (auto sys : _systems) {
        sys.second->Init();
    }

    _scene = new Scene();

    auto *object = _scene->CreateEmptyObject();
    auto *spriteComponent = _scene->CreateComponent(GRA_SPRITE);
    object->AddComponent(spriteComponent);
#endif
    //object->addComponent(GRA_SPRITE, new graphics::SpriteComponent);
    //gm->addObject(1, object);
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
    Init();
}

engine::core::Scene *engine::core::Engine::getScene() {
    return _scene;
}
