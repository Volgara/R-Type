//
//-----------------------------------------------------------------------------
//Filename:    Component.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/11/18.
//-----------------------------------------------------------------------------
//

#include "ID.hpp"
#include "Message.hpp"

#ifndef RTYPE_COMPONENT_HPP
#define RTYPE_COMPONENT_HPP

namespace engine {
    namespace core {
        struct Component {
            GameObjectID owner;
            ComponentID id;
            bool active = true;

            explicit Component(ComponentID id);

            virtual void SendMessage(Message *message) = 0;

            virtual void Update(float dt) = 0;

            virtual void Init() = 0;

            virtual void ShutDown(void) = 0;
        };
    }
}


#endif //RTYPE_COMPONENT_HPP
