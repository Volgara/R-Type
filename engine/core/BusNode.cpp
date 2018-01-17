//
// Created by Hamza Hammouche on 17/01/2018.
//

#include "BusNode.hpp"


engine::core::BusNode::BusNode() {}

std::function<void (engine::core::Message)> engine::core::BusNode::getNotifyFunc() {
    auto messageListener = [=](Message message) -> void {
        this->onNotify(message);
    };
    return messageListener;
}

void engine::core::BusNode::send(engine::core::Message message) {
    this->_messageBus->sendMessage(message);
}

void engine::core::BusNode::setMessageBus(engine::core::MessageBus *messageBus) {
    this->_messageBus = messageBus;
    this->_messageBus->addReceiver(this->getNotifyFunc());
}
