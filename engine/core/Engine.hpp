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
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "NonCopyable.hpp"
#include "ISystem.hpp"

namespace engine {
    namespace core {
        class Engine : private NonCopyable {
        private:
            std::map<std::string, ISystem *> _systems;
            std::deque<Message *> _messages;
            sf::RenderWindow _window;
            bool _gameRunning;

        public:
            Engine();

            ~Engine();

            void Init(void);

            void Update(float dt);

            void MainLoop(void);

            void addSystem(const std::string &systemId, ISystem *);

            ISystem *getSystem(const std::string &systemId);

            sf::RenderWindow &getWindow();
        };
    }
}


#endif //RTYPE_EVENTMANAGER_HPP
