/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 12/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_GAME_HPP
#define RTYPE_GAME_HPP


#include <string>
#include "Event.hpp"
#include "Scene.hpp"
#include "Window.hpp"

namespace RType {

    namespace Engine {
        class Game {
        public:
            Game(unsigned int width, unsigned int height, std::string title);
            Game(Window window);
            ~Game();

        public:
            bool isRunning();
            bool getEvent(RType::Engine::Event event);
            bool close();
            void render();
            void clear();
            void loadScene();
            void addScene(RType::Engine::Scene scene);

        private:
            Window &window;
        };
    }

}

#endif //RTYPE_GAME_HPP
