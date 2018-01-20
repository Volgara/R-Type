//
//-----------------------------------------------------------------------------
//Filename:    InputComponent.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/20/18.
//-----------------------------------------------------------------------------
//

#ifndef RTYPE_INPUTCOMPONENT_HPP
#define RTYPE_INPUTCOMPONENT_HPP
#ifdef GRAPHICS

#include <map>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include "Command.hpp"

namespace engine {
    namespace input {
        class InputComponent : public core::Component {
        private:
            std::map<sf::Keyboard::Key, Command *> m_state_commands;
            std::map<sf::Keyboard::Key, Command *> m_action_commands;
        public:
            InputComponent();

            ~InputComponent() override;

            void attachState(sf::Keyboard::Key key, Command *cmd);

            void attachAction(sf::Keyboard::Key key, Command *cmd);

            void detachState(Command *cmd);

            void detachStateBykey(sf::Keyboard::Key key);

            void detachAction(Command *cmd);

            void detachActionByKey(sf::Keyboard::Key key);

            void detachStates();

            void detachActions();

            void sendEvent(sf::Event &event);

            void SendMessage(core::Message *message) override;

            void Update(float dt) override;

            void Init() override;

            void ShutDown(void) override;
        };
    }
}

#endif
#endif //RTYPE_INPUTCOMPONENT_HPP
