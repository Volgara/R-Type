//
//-----------------------------------------------------------------------------
//Filename:    Component.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/11/18.
//-----------------------------------------------------------------------------
//

#include "ID.hpp"
#include "BusNode.hpp"

#ifndef RTYPE_COMPONENT_HPP
#define RTYPE_COMPONENT_HPP

namespace engine {
    namespace core {

        struct GameObject;

        struct Component {
            GameObjectID owner;
            GameObject *ownerRef;
            ComponentID id;
            bool active = true;

            explicit Component(ComponentID id);

            virtual ~Component() {};

            virtual void SendMessage(Message *message) = 0;

            virtual void Update(float dt) = 0;

            virtual void Init() = 0;

            virtual void ShutDown(void) = 0;

            void detachGameObject();

            void attachGameObject(GameObject *object
            );
        };
    }
}


#endif //RTYPE_COMPONENT_HPP
