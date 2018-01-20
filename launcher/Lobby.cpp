/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include <sstream>

#ifdef _WIN32

#include <Windows.h>

#endif

#include "Lobby.hpp"
#include "Helper.hpp"

Lobby::Lobby(const std::string &name, sf::RenderWindow *win) : Scene(name, win) {
    this->inGame = false;
}

Lobby::~Lobby() {

}

void Lobby::init() {
    if (!font.loadFromFile("assets/arial.ttf")) {
        std::cout << "Cannot load ARIAL font" << std::endl;
    }

    text.setFont(font);
    text.setCharacterSize(45);
    text.setFillColor(sf::Color::White);
    text.setString("Waiting for players to join...");
    Helper::centerElement(text, this->_win, true, true);

    if (!ready_.loadFromFile("assets/Ready.png")) {
        std::cout << "An error occurred." << std::endl;
    }
    ready.setTexture(ready_);
    ready.setPosition(0, 532);
    Helper::centerElement(ready, this->_win, true, false);

    if (!refresh_.loadFromFile("assets/refresh.png")) {
        std::cout << "An error occurred." << std::endl;
    }
    refresh.setTexture(refresh_);
    refresh.setPosition(732, 20);

    if (!back_.loadFromFile("assets/Back.png")) {
        std::cout << "An error occurred." << std::endl;
    }
    back.setTexture(back_);
    back.setPosition(5, 532);
}

void Lobby::update() {
    this->_win->draw(text);
    this->_win->draw(refresh);
    this->_win->draw(back);

    if (!this->inGame)
        //this->_win->draw(ingame);
        //else
        this->_win->draw(ready);
}

void Lobby::onEvent(sf::Event &event) {
    if (Helper::isSpriteClicked(ready, *this->_win)) {

        this->inGame = true;

        std::string port = _connection->SetReady();

        std::stringstream parameters;

        parameters << "-p " << port << " -ip " << this->_connection->getIp();

#ifdef _WIN32
        ShellExecute(NULL, "open", "client.exe", parameters.str().c_str(), NULL, SW_SHOWDEFAULT);
#endif

#if defined(linux) || defined(__APPLE__)
        system("./client " + parameters);
#endif

    }

    if (Helper::isSpriteClicked(back, *this->_win)) {
        _connection->leaveRoom();
        this->requestSceneSwitch("serverList");
    }

    if (Helper::isSpriteClicked(refresh, *this->_win)) {
        std::stringstream ss;
        std::string nb = _connection->getPlayerNumber();

        ss << "Waiting for players to join... (" << nb << "/" << "4)";
        text.setString(ss.str());
        Helper::centerElement(text, this->_win, true, true);

    }
}

void Lobby::onSwitch() {
    std::cout << "Welcome to the lobby, we are waiting for the other players to join :)" << std::endl;

    std::stringstream ss;
    std::string nb = _connection->getPlayerNumber();

    ss << "Waiting for players to join... (" << nb << "/" << "4)";
    text.setString(ss.str());
    Helper::centerElement(text, this->_win, true, true);
}
