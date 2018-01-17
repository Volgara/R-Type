//
//-----------------------------------------------------------------------------
//Filename:    InputSystem.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/17/18.
//-----------------------------------------------------------------------------
//

#ifndef RTYPE_INPUTSYSTEM_HPP
#define RTYPE_INPUTSYSTEM_HPP

#include <functional>
#include <SFML/Window/Event.hpp>
#include "ASystem.hpp"

namespace engine {
    namespace core {
        class InputSystem : public ASystem {
        public:
            typedef std::function<void(sf::Event &)> Callback;
        private:
            sf::Event _event{};
            std::map<sf::Event::EventType, Callback> _callbacks;

        public:
            void Update(float d) override;

            void Init(void) override;

            void SendMessage(Message *msg) override;

            ~InputSystem() override = default;

            void addEventListener(sf::Event::EventType type, Callback fct);
        };
    }
}


#endif //RTYPE_INPUTSYSTEM_HPP
