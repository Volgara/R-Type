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
#include "EngineMsg.hpp"

namespace engine {
    namespace core {
        class ISystem {
        public:

            // All systems must update each game loop
            virtual void Update(float dt) = 0;

            // It's good practice to separate the construction and initialization code.
            virtual void Init(void) = 0;

            // This recieves any messages sent to the core engine in Engine.cpp
            virtual void SendMessage(EngineMsg *msg) = 0;

            // All systems need a virtual destructor to have their destructor called
            virtual ~ISystem() = default;
        };
    }
}


#endif //RTYPE_SYSTEM_HPP
