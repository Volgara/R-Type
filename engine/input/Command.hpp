//
//-----------------------------------------------------------------------------
//Filename:    Command.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/20/18.
//-----------------------------------------------------------------------------
//

#ifndef RTYPE_COMMAND_HPP
#define RTYPE_COMMAND_HPP

#include <core/GameObject.hpp>
#include <core/Engine.hpp>
#include <core/MessageBus.hpp>

namespace engine {
    namespace input {
        /**
         * @brief Command interface
         */
        class Command {
        public:
            virtual ~Command() {};

            /**
             * Execute action with emitter
             * @param actor the emitter of the action
             */
            virtual void execute(core::GameObject *actor) = 0;

            /**
             * Don't touch !
             * @param actor
             * @param toggle
             */
            virtual void do_execute(core::GameObject *actor, bool toggle) = 0;
        };

        /**
         * @brief One shot action
         */
        class Action : public Command {
        private:
            bool m_action = false;
        private:
            void do_execute(core::GameObject *actor, bool toggle) override {
                if (!m_action && toggle) {
                    m_action = true;
                    execute(actor);
                } else if (!toggle && m_action) {
                    m_action = false;
                }
            }
        };

        class ActionDebug : public Action {
        public:
            void execute(core::GameObject *actor) override {
                std::cout << "action: execute: " << " - ID of game object: " << actor->guid << std::endl;
            }
        };

        /**
         * @brief Continuous action
         */
        class State : public Command {
        public:
        private:
            void do_execute(core::GameObject *actor, bool toggle) override {
                if (toggle)
                    execute(actor);
            }
        };

        class StateDebug : public State {
        public:
            void execute(core::GameObject *actor) override {
                std::cout << "state: execute: " << " - ID of game object: " << actor->guid << std::endl;
            }
        };

        class StateSendMessage : public State {
        private:
            core::MessageBus *m_bus;
            core::MessageSourced *m_message;
        public:
            explicit StateSendMessage(core::MessageSourced *message) : m_message(message) {
                m_bus = core::Engine::GetInstance()->getMessageBus();
            }

            void execute(core::GameObject *actor) override {
#ifdef DEBUG
      std::cout << "StateSendMessage: actor:" << actor->guid << " message_id: " << m_message->id << std::endl;
#endif
                m_message->m_ref = actor;
                m_bus->sendMessage(*m_message);
            }
        };
    }
}

#endif //RTYPE_COMMAND_HPP
