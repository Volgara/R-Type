//
// Created by Hamza Hammouche on 17/01/2018.
//

#include "MessageBus.hpp"

engine::core::MessageBus::MessageBus() {

}

engine::core::MessageBus::~MessageBus() {

}

void engine::core::MessageBus::addReceiver(std::function<void(Message)> messageReceiver) {
    this->_receivers.push_back(messageReceiver);
}

void engine::core::MessageBus::sendMessage(engine::core::Message message) {
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

