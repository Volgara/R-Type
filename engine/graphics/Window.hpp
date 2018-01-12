/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 12/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_WINDOW_HPP
#define RTYPE_WINDOW_HPP


#include <SFML/Graphics/RenderWindow.hpp>

namespace RType {
    namespace Engine {
        class Window : public sf::RenderWindow {
        public:
            Window(unsigned int width, unsigned int height, std::string title);
            Window();

            ~Window();

        public:

        };
    }
}


#endif //RTYPE_WINDOW_HPP
