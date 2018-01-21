/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 12/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include "Window.hpp"

RTypeServer::Engine::Window::Window(unsigned int width, unsigned int height, std::string title) : sf::RenderWindow(
        sf::VideoMode(width, height),
        title) {

}

RTypeServer::Engine::Window::~Window() {

}

RTypeServer::Engine::Window::Window() {}
