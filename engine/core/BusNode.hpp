//
// Created by Hamza Hammouche on 17/01/2018.
//

#ifndef RTYPE_BUSNODE_HPP
#define RTYPE_BUSNODE_HPP

#include "MessageBus.hpp"

namespace engine {
    namespace core {
        class BusNode {
        public:
            BusNode();

            void setMessageBus(MessageBus *messageBus);

        protected:
            MessageBus *_messageBus;

        protected:
            std::function<void (Message *)> getNotifyFunc();
            void sendMsg(Message *message);

            virtual void onNotify(Message *message) = 0;
        };
    }
}

#endif //RTYPE_BUSNODE_HPP
