//
//-----------------------------------------------------------------------------
//Filename:    InputSystem.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/17/18.
//-----------------------------------------------------------------------------
//

#ifdef GRAPHICS

#include "core/Engine.hpp"
#include "InputSystem.hpp"
#include "InputComponent.hpp"

void engine::input::InputSystem::Update(float dt) {

    auto *eg = engine::core::Engine::GetInstance();
    auto *listIC = eg->getScene()->GetComponents<InputComponent>(core::ComponentID::INPUT_GENERATE);

    for (auto component : *listIC) {
        component->Update(dt);
    }

    while (eg->getWindow().pollEvent(_event)) {
        for (auto callback : m_callbacks) {
            callback(_event);
        }
    }
}

void engine::input::InputSystem::Init() {

}

void engine::input::InputSystem::onNotify(engine::core::Message) {

}

/**
 * This method insert a callback call after an sf::Event was polled
 * @param callback
 */
void engine::input::InputSystem::addKeyCallback(engine::input::InputSystem::Callback callback) {
    m_callbacks.push_back(callback);
}

#endif
