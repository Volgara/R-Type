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

void engine::input::InputSystem::Update(float) {

    auto *eg = engine::core::Engine::GetInstance();
    auto *listIC = eg->getScene()->GetComponents<InputComponent>(core::ComponentID::INPUT_GENERATE);

    /*
    for (auto component : *listIC) {
        component->sendEvent(_event);
    }
     */

    while (eg->getWindow().pollEvent(_event)) {
        for (auto callback : m_callbacks) {
            callback(_event);
        }
        for (auto component : *listIC) {
            component->sendEvent(_event);
        }
    }
}

void engine::input::InputSystem::Init() {

}

void engine::input::InputSystem::onNotify(engine::core::Message) {

}

void engine::input::InputSystem::addKeyCallback(engine::input::InputSystem::Callback callback) {
    m_callbacks.push_back(callback);
}

#endif
