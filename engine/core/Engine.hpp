//
//-----------------------------------------------------------------------------
//Filename:    EventManager.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/9/18.
//-----------------------------------------------------------------------------
//

#ifndef RTYPE_EVENTMANAGER_HPP
#define RTYPE_EVENTMANAGER_HPP

#include <string>
#include <map>
#include <deque>
#include "NonCopyable.hpp"
#include "ISystem.hpp"

namespace engine {
    namespace core {
        class Engine : private NonCopyable {
        private:
            std::map<std::string, ISystem *> _systems;
            std::deque<EngineMsg *> _messages;

        public:
            Engine();

            void Update(float dt);

            void MainLoop(void);

            void addSystem(const std::string &systemId, ISystem *);

            ISystem *getSystem(const std::string &systemId);
        };
    }
}


#endif //RTYPE_EVENTMANAGER_HPP
