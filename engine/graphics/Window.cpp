/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 12/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include "Window.hpp"

RType::Engine::Window::Window(unsigned int width, unsigned int height, std::string title) : sf::RenderWindow(
        sf::VideoMode(width, height),
        title) {

}

RType::Engine::Window::~Window() {

}

RType::Engine::Window::Window() {}
