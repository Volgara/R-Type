/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include "ServerList.hpp"
#include "Helper.hpp"

ServerList::ServerList(const std::string &name, sf::RenderWindow *win) : Scene(name, win) {
    this->canType = false;
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

    if (!backButton_.loadFromFile("assets/Back.png")) {
        std::cout << "An error occurred." << std::endl;
    }
    backButton.setTexture(backButton_);
    backButton.setPosition(5, 532);

    if (!CreateServer_.loadFromFile("assets/CreateServer.png")) {
        std::cout << "An error occurred." << std::endl;
    }
    CreateServer.setTexture(CreateServer_);
    CreateServer.setPosition(645, 532);

    if (!lobbyView_.loadFromFile("assets/LobbyView.png")) {
        std::cout << "An error occurred." << std::endl;
    }
    lobbyView.setTexture(lobbyView_);
    Helper::centerElement(lobbyView, this->_win);

    if (!InputText_.loadFromFile("assets/Field.png")) {
        std::cout << "An error occurred." << std::endl;
    }
    InputText.setTexture(InputText_);
    InputText.setPosition(0, 532);
    Helper::centerElement(InputText, this->_win, true, false);
}

void ServerList::update() {
    this->_win->draw(backButton);
    this->_win->draw(lobbyView);
    this->_win->draw(CreateServer);
    this->_win->draw(InputText);
}
void ServerList::onEvent(sf::Event &event) {
    if (Helper::isSpriteClicked(backButton, *this->_win))
        this->requestSceneSwitch("menu");

    // concat string on input
    if (this->canType && event.type == sf::Event::TextEntered)
        this->currentTyped += static_cast<char>(event.text.unicode);

    // Validate what you typed
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return && this->canType)
        this->_connection->createAndJoin(this->currentTyped);

    if (Helper::isSpriteClicked(CreateServer, *this->_win))
        this->canType = true;
}

void ServerList::onSwitch() {
    std::cout << "[ERROR: ServerList.cpp L76 vvv] Server availables:" << std::endl;
    std::cout << this->_connection->getList() << std::endl;
}
