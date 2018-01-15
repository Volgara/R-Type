//
//-----------------------------------------------------------------------------
//Filename:    Component.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/11/18.
//-----------------------------------------------------------------------------
//

#ifndef RTYPE_COMPONENT_HPP
#define RTYPE_COMPONENT_HPP

namespace engine {
    namespace core {
        class Component;

        typedef unsigned int ComponentID;
    }
}

#include "GameObject.hpp"

namespace engine {
    namespace core {
        class Component {
        protected:
            GameObjectID _owner;
            ComponentID _id;
            bool _isActive = true;

        public:
            virtual ~Component() = default;

            virtual void SendMessage(Message *message) = 0;

            virtual void Update(float dt) = 0;

            virtual void Init() = 0;

            virtual void ShutDown() = 0;

            bool Active() const;
        };
    }
}


#endif //RTYPE_COMPONENT_HPP
