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

#ifdef GRAPHICS

#include <functional>
#include <SFML/Window/Event.hpp>
#include <core/Message.hpp>
#include <core/ASystem.hpp>

namespace engine {
    namespace input {

        class InputComponent;

        class InputSystem : public core::ASystem {
        public:
            typedef std::function<void(sf::Event &)> Callback;
        private:
            std::vector<Callback> m_callbacks;
            std::vector<InputComponent *> m_components;
            sf::Event _event{};

        public:
            void Update(float d) override;

            void Init(void) override;

            ~InputSystem() override = default;

            void addKeyCallback(Callback callback);

        protected:
            void onNotify(core::Message message) override;
        };
    }
}
#endif

#endif //RTYPE_INPUTSYSTEM_HPP
