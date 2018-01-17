//
//-----------------------------------------------------------------------------
//Filename:    InputSystem.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/17/18.
//-----------------------------------------------------------------------------
//

#include "Engine.hpp"
#include "InputSystem.hpp"

void engine::core::InputSystem::Update(float d) {
    auto *eg = engine::core::Engine::GetInstance();

    while (eg->getWindow().pollEvent(_event)) {
        if (_callbacks.find(_event.type) != _callbacks.end()) {
            _callbacks[_event.type](_event);
        }
    }
}

void engine::core::InputSystem::Init() {

}

void engine::core::InputSystem::SendMessage(engine::core::Message *msg) {

}

void engine::core::InputSystem::addEventListener(sf::Event::EventType type, engine::core::InputSystem::Callback fct) {
    _callbacks[type] = std::move(fct);
}
