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

enum MessageID {
    TAKE_DAMAGE = 0,
};

struct Message {
    MessageID id;
};

struct DamageMessage : public Message {
    int message;
};

#endif //RTYPE_MESSAGE_HPP
