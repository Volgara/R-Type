//
// Created by Hamza Hammouche on 17/01/2018.
//

#ifndef RTYPE_MESSAGEBUS_HPP
#define RTYPE_MESSAGEBUS_HPP

#include <iostream>
#include <functional>
#include <queue>
#include <vector>
#include "Message.hpp"

namespace engine {
    namespace core {
        class MessageBus {
        public:
            MessageBus();
            virtual ~MessageBus();

            void addReceiver(std::function<void (Message)> messageReceiver);
            void sendMessage(Message message);
            void notify();

        private:
            std::vector<std::function<void (Message)>> _receivers;
            std::queue<Message> _messages;
        };
    }
}


#endif //RTYPE_MESSAGEBUS_HPP
