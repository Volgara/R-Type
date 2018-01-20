/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

//#include <Windows.h>
#include "Lobby.hpp"
#include "Helper.hpp"

Lobby::Lobby(const std::string &name, sf::RenderWindow *win) : Scene(name, win) {

}

Lobby::~Lobby() {

}

void Lobby::init() {
    if (!font.loadFromFile("assets/arial.ttf")) {
        std::cout << "Cannot load ARIAL font" << std::endl;
    }

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setString("Waiting for players to join...");
    Helper::centerElement(text, this->_win, true, true);
}

void Lobby::update() {
    this->_win->draw(text);
}

void Lobby::onEvent(sf::Event &event) {

}

void Lobby::onSwitch() {
    std::cout << "Welcome to the lobby, we are waiting for the other players to join :)" << std::endl;
    //ShellExecute(NULL, "open", "client.exe", "-p 0000 -ip 127.0.0.1", NULL, SW_SHOWDEFAULT);
}
