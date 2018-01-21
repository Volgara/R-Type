//
//-----------------------------------------------------------------------------
//Filename:    Message.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/10/18.
//-----------------------------------------------------------------------------
//

#ifndef RTYPE_MESSAGE_HPP
#define RTYPE_MESSAGE_HPP

#include "ID.hpp"

namespace engine {
    namespace core {
        enum MessageID {
            COLLISION = 0,
            SEND_BULLET,
            MOVE_PLAYER,
            MOVE
        };

        enum Direction {
            UP = 0,
            DOWN,
            RIGHT,
            LEFT
        };
        struct Message {
            explicit Message(MessageID type) : id(type) {}
            MessageID id;
        };

        struct Collision2D : public Message {
            Collision2D() : Message(COLLISION) {}
            GameObjectID source{0};
            GameObjectID target{0};
        };

        struct SendBullet : public Message {
            SendBullet() : Message(SEND_BULLET) {}
            GameObjectID source{0};
        };

        struct MovePlayer : public Message {
            MovePlayer() : Message(MOVE_PLAYER) {}
            GameObjectID source{0};
            Direction  direction{};
        };

        struct Move : public Message {
            Move() : Message(MOVE) {}
            GameObjectID source{0};
            int x{0};
            int y{0};
        };
    }
}
#endif //RTYPE_MESSAGE_HPP
