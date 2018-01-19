/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include "ServerList.hpp"
#include "Helper.hpp"

ServerList::ServerList(std::string name, sf::RenderWindow *win) : Scene(name, win)  {

}
ServerList::~ServerList() {

}
void ServerList::init() {
    std::cout << "Init" << std::endl;
    if (!font.loadFromFile("assets/arial.ttf")) {
        std::cout << "Cannot load ARIAL font" << std::endl;
    }

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);

    if (!backButton_.loadFromFile("assets/backButton.png")) {
        std::cout << "An error occurred." << std::endl;
    }
    backButton.setTexture(backButton_);
    backButton.setPosition(60, 550);

    if (!lobbyView_.loadFromFile("assets/LobbyView.png")) {
        std::cout << "An error occurred." << std::endl;
    }
    lobbyView.setTexture(lobbyView_);
    //Helper::centerElement(lobbyView, this->_win);
    lobbyView.setPosition(50, 50);
}

void ServerList::update() {
    std::cout << "Drawing" << std::endl;
    this->_win->draw(backButton);
    this->_win->draw(lobbyView);
}
void ServerList::onEvent(sf::Event &event) {
    std::cout << "Event" << std::endl;
}
