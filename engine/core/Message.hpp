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
        using MessageID = unsigned;

        class GameObject;

        class Message {
        public:
            MessageID id;

            explicit Message(MessageID type = 0) : id(type) {}
        };

        class MessageSourced : public Message {
        public:
            GameObject *m_ref{};

            explicit MessageSourced(MessageID type = 0) : Message(type) {};
        };

        class Collision2D : public Message {
        public:
            Collision2D() : Message(0) {}

            GameObjectID source{0};
            GameObjectID target{0};
        };

        class SendBullet : public Message {
        public:
            SendBullet() : Message(1) {}

            GameObjectID source{0};
            GameObjectID bullet{0};
        };
    }
}
#endif //RTYPE_MESSAGE_HPP
