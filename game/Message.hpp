//
//-----------------------------------------------------------------------------
//Filename:    Message.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/21/18.
//-----------------------------------------------------------------------------
//

#ifndef RTYPE_GAME_MESSAGE_HPP
#define RTYPE_GAME_MESSAGE_HPP

#include <core/Message.hpp>

namespace core = engine::core;

namespace game {
    enum GameMessageID : core::MessageID {
        PLAYER_ACTION = core::InternalMessageID::LAST,
        SERVER_ACTION
    };

    /**
     * @brief Exemple Player Action Message command
     */
    class PlayerActionMessage : public engine::core::MessageSourced {
    public:
        enum Action {
            GO_UP = 0,
            GO_DOWN,
            GO_LEFT,
            GO_RIGHT,
            SHOOT
        };
    private:
        const Action m_action;
    public:
        PlayerActionMessage(Action action) : MessageSourced(PLAYER_ACTION), m_action(action) {
            m_ref = nullptr;
        }

        const Action getAction() const {
            return m_action;
        }
    };

    /**
     * @brief Exemple Player Action Message command
     * // TODO: improvement storage data message server
     */
    class ServerActionMessage : public engine::core::MessageSourced {
    public:
        enum Action {
            GO_UP = 0,
            GO_DOWN,
            GO_LEFT,
            GO_RIGHT,
            SHOOT
        };
    private:
        const Action m_action;
        const GameMessageID m_source;
        core::Vector2d m_pos{};
    public:
        ServerActionMessage(GameMessageID source, Action action, const core::Vector2d &pos)
                : MessageSourced(SERVER_ACTION), m_action(action), m_source(source), m_pos(pos)  {
            m_ref = nullptr;
        }

        const Action getAction() const {
            return m_action;
        }

        const GameMessageID getSource() const {
            return m_source;
        }

        const core::Vector2d &getPos() const {
            return m_pos;
        }

        void setPos(const core::Vector2d &pos) {
            m_pos = pos;
        }
    };
}

#endif //RTYPE_GAME_MESSAGE_HPP
