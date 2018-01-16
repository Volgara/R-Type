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

#ifdef GRAPHICS
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#endif

#include <string>
#include <map>
#include <deque>
#include "NonCopyable.hpp"
#include "ASystem.hpp"
#include "Singleton.hpp"
#include "Scene.hpp"

namespace engine {
    namespace core {
        class Engine : private NonCopyable, public Singleton<Engine> {
        private:
            std::map<std::string, ASystem *> _systems;
            std::deque<Message *> _messages;
            Scene *_scene;
            bool _gameRunning;

#ifdef GRAPHICS
            sf::RenderWindow _window;
#endif

        public:
            void constructor() override;

        public:
            /**
             * Init each subsystem
             */
            void Init(void);

            /**
             * Update each subsystem
             * @param dt
             */
            void Update(float dt);

            /**
             * Only for debug
             */
            void MainLoop(void);

            /**
             * Insert a new system in engine list
             * @param systemId
             * @param system
             */
            void addSystem(const std::string &systemId, ASystem *system);

            /**
             * Get's system by name
             * @param systemId
             * @return
             */
            ASystem *getSystem(const std::string &systemId);

            /**
             * Get's engine status
             * @return true if is running
             */
            bool isRunning() const;

            /**
             * Before exit the application
             */
            void Shutdown(void);


#ifdef GRAPHICS
            sf::RenderWindow &getWindow();
#endif

            Scene *getScene();
        };
    }
}


#endif //RTYPE_EVENTMANAGER_HPP
