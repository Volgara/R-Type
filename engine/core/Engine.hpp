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
#include "ASystem.hpp"
#include "GameObjectManager.hpp"


namespace engine {
    namespace core {
        class Engine : private NonCopyable, public Singleton<Engine> {
        private:
            std::map<std::string, ASystem *> _systems;
            std::deque<Message *> _messages;
            sf::RenderWindow _window;
            bool _gameRunning;

        public:
            void constructor() override;

        public:
            void Init(void);

            void Update(float dt);

            void MainLoop(void);

            void addSystem(const std::string &systemId, ASystem *);

            ASystem *getSystem(const std::string &systemId);

            sf::RenderWindow &getWindow();
        };
    }
}


#endif //RTYPE_EVENTMANAGER_HPP
