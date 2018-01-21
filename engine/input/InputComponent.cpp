//
//-----------------------------------------------------------------------------
//Filename:    InputComponent.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/20/18.
//-----------------------------------------------------------------------------
//

#include <algorithm>
#include "InputComponent.hpp"

engine::input::InputComponent::InputComponent() : Component(core::ComponentID::INPUT_GENERATE) {

}

engine::input::InputComponent::~InputComponent() {

}

void engine::input::InputComponent::SendMessage(engine::core::Message *message) {

}

void engine::input::InputComponent::Update(float dt) {
    // TODO : make improvement with only one for
    for (auto command : m_action_commands) {
        command.second->do_execute(ownerRef, sf::Keyboard::isKeyPressed(command.first));
    }
    for (auto command : m_state_commands) {
        command.second->do_execute(ownerRef, sf::Keyboard::isKeyPressed(command.first));
    }
}

void engine::input::InputComponent::Init() {

}

void engine::input::InputComponent::ShutDown(void) {

}

void engine::input::InputComponent::attachState(sf::Keyboard::Key key, engine::input::Command *cmd) {
    m_state_commands[key] = cmd;
}

void engine::input::InputComponent::attachAction(sf::Keyboard::Key key, engine::input::Command *cmd) {
    m_action_commands[key] = cmd;
}

void engine::input::InputComponent::detachState(engine::input::Command *cmd) {
    for (auto it = m_state_commands.begin(); it != m_state_commands.end(); it++) {
        if (cmd == it->second) {
            delete (it->second);
            m_state_commands.erase(it);
        }
    }
}

void engine::input::InputComponent::detachStateBykey(sf::Keyboard::Key key) {
    auto it = m_state_commands.find(key);
    if (it == m_state_commands.end())
        std::exception();
    detachState(it->second);
}

void engine::input::InputComponent::detachAction(engine::input::Command *cmd) {
    for (auto it = m_action_commands.begin(); it != m_action_commands.end(); it++) {
        if (cmd == it->second) {
            delete (it->second);
            m_state_commands.erase(it);
        }
    }
}

void engine::input::InputComponent::detachActionByKey(sf::Keyboard::Key key) {
    m_action_commands.erase(key);
}

void engine::input::InputComponent::detachStates() {
    m_state_commands.clear();
}

void engine::input::InputComponent::detachActions() {
    m_action_commands.clear();
}

void engine::input::InputComponent::sendEvent(sf::Event &event) {
    const char keyState = event.type == event.KeyPressed || event.type == event.KeyReleased;
    const char keyToggle = event.type == event.KeyPressed;

    if (keyState) {
        auto it = m_action_commands.find(event.key.code);
        if (it != m_action_commands.end())
            it->second->do_execute(ownerRef, keyToggle);
        else {
            it = m_state_commands.find(event.key.code);
            if (it != m_state_commands.end())
                it->second->do_execute(ownerRef, keyToggle);
        }
    }
}
