/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 12/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Game.hpp"

bool RType::Engine::Game::isRunning() {
    return false; //this->window.isOpen();
}

bool RType::Engine::Game::getEvent(RType::Engine::Event event) {
    return false; //this->window.pollEvent(event);
}

bool RType::Engine::Game::close() {
    //this->window.close();
    return false;
}

void RType::Engine::Game::render() {
    //this->window.display();
}

void RType::Engine::Game::clear() {
    //this->window.clear();
}

void RType::Engine::Game::loadScene() {

}

void RType::Engine::Game::addScene(RType::Engine::Scene scene) {

}
RType::Engine::Game::~Game() {

}

RType::Engine::Game::Game(unsigned int width, unsigned int height, std::string title) {

}


RType::Engine::Game::Game(RType::Engine::Window window) : window(window) {

}
