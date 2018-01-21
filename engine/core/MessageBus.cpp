//
// Created by Hamza Hammouche on 17/01/2018.
//

#include "MessageBus.hpp"

engine::core::MessageBus::MessageBus() = default;

engine::core::MessageBus::~MessageBus() = default;

void engine::core::MessageBus::addReceiver(std::function<void(Message)> messageReceiver) {
#ifdef DEBUG_MESSAGE_BUSS
    std::cout << "MessageBus::addReceiver" << std::endl;
#endif
    this->_receivers.push_back(messageReceiver);
}

void engine::core::MessageBus::sendMessage(Message &message) {
#ifdef DEBUG_MESSAGE_BUSS
    std::cout << "MessageBus::sendMessage: type = " << message.id << std::endl;
#endif
    this->_messages.push(message);
}

void engine::core::MessageBus::notify() {
    while(!this->_messages.empty()) {
        for (auto &_receiver : this->_receivers) {
            _receiver(this->_messages.front());
        }
        this->_messages.pop();
    }
}

