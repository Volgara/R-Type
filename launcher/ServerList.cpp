/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include "ServerList.hpp"
#include "Helper.hpp"
#include "GraphicalRoom.hpp"

ServerList::ServerList(const std::string &name, sf::RenderWindow *win) : Scene(name, win) {
    this->canType = false;
}
ServerList::~ServerList() {

}
void ServerList::init() {
    if (!font.loadFromFile("assets/arial.ttf")) {
        std::cout << "Cannot load ARIAL font" << std::endl;
    }

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);

    textCurrentlyTyped.setFont(font);
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

    if (!Cancel_.loadFromFile("assets/cancel.png")) {
        std::cout << "An error occurred." << std::endl;
    }
    Cancel.setTexture(Cancel_);
    Cancel.setPosition(645, 532);

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

    if (this->canType) {
        // update string typed
        textCurrentlyTyped.setString(this->currentTyped);

        // display both field and text
        this->_win->draw(InputText);

        textCurrentlyTyped.setPosition(0, 532);
        Helper::centerElement(textCurrentlyTyped, this->_win, true, false);
        this->_win->draw(textCurrentlyTyped);
        this->_win->draw(Cancel);

    } else {
        this->_win->draw(CreateServer);
    }

    int       i = 0;
    for (auto &room : this->graphicalRooms) {
        room->sprite.setPosition(0, 100 + (50 * i));
        Helper::centerElement(room->sprite, this->_win, true, false);
        //this->_win->draw(room->sprite);

        room->text.setPosition(120, 100 + (50 * i));
        room->text.setString(room->displayText.str());
        this->_win->draw(room->text);

        i++;
    }
}
void ServerList::onEvent(sf::Event &event) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        if (Helper::isSpriteClicked(backButton, *this->_win))
            this->requestSceneSwitch("menu");

        if (Helper::isSpriteClicked(Cancel, *this->_win))
            this->canType = false;
        if (Helper::isSpriteClicked(CreateServer, *this->_win))
            this->canType = true;
    }

    // concat string on input
    if (this->canType && event.type == sf::Event::TextEntered &&
        ((event.text.unicode >= 65 && event.text.unicode <= 90) ||
            (event.text.unicode >= 97 && event.text.unicode <= 122))) {
        std::cout << event.text.unicode << std::endl;
        this->currentTyped += static_cast<char>(event.text.unicode);
    }

    // Validate what you typed
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return && this->canType) {
        this->_connection->createAndJoin(this->currentTyped);
        this->requestSceneSwitch("lobby");
    }

    // Backspace
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::BackSpace && this->canType)
        this->currentTyped = this->currentTyped.substr(0, this->currentTyped.size() - 1);
}

void ServerList::onSwitch() {
    std::string list = this->_connection->getList();

    this->_connection->emptyRoomsFound();
    this->emptyGraphicalRoomsFound();

    auto      vecRooms = Helper::explode(list, '|');
    for (auto &r: vecRooms) {

        auto room = Helper::explode(r, ',');
        if (room.size() == 2)
            this->_connection->addRoomFound(room[0], std::stoi(room[1])); //TODO check value
        else
            std::cout << "Bad formatted room!" << std::endl;
    }

    for (auto &room : this->_connection->getRoomsFound()) {
        auto *r = new GraphicalRoom(room);
        this->graphicalRooms.push_back(r);
    }
}
void ServerList::emptyGraphicalRoomsFound() {
    this->graphicalRooms.clear();
}

