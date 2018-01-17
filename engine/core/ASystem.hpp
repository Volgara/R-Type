//
//-----------------------------------------------------------------------------
//Filename:    System.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/10/18.
//-----------------------------------------------------------------------------
//

#ifndef RTYPE_SYSTEM_HPP
#define RTYPE_SYSTEM_HPP


#include "NonCopyable.hpp"
#include "BusNode.hpp"

namespace engine {
    namespace core {
        class ASystem : public BusNode {
        public:

            // All systems must update each game loop
            virtual void Update(float dt) = 0;

            // It's good practice to separate the construction and initialization code.
            virtual void Init(void) = 0;

            // This recieves any messages sent to the core engine in Engine.cpp
            virtual void SendMessage(Message *msg) = 0;

            // All systems need a virtual destructor to have their destructor called
            virtual ~ASystem() = default;
        };
    }
}


#endif //RTYPE_SYSTEM_HPP
