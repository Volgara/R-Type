/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include <fstream>
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#ifdef _WIN32

#include <Windows.h>

#endif
#include "Menu.hpp"
#include "Connection.hpp"
#include "json.hpp"
#include "Helper.hpp"

Menu::Menu(const std::string &name, sf::RenderWindow *win) : Scene(name, win) {

}

Menu::~Menu() {

}

void Menu::onEvent(sf::Event &event) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (this->selectedButtonIndex == 3)
            this->selectedButtonIndex = 0;
        else
            this->selectedButtonIndex++;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (this->selectedButtonIndex == 0)
            this->selectedButtonIndex = 3;
        else
            this->selectedButtonIndex--;
    }

    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return) {
        menuSelection(this->selectedButtonIndex);
    }

    if (Helper::isMouseHover(button1, *this->_win))
        this->selectedButtonIndex = 0;
    if (Helper::isMouseHover(button2, *this->_win))
        this->selectedButtonIndex = 1;
    if (Helper::isMouseHover(button3, *this->_win))
        this->selectedButtonIndex = 2;
    if (Helper::isMouseHover(button4, *this->_win))
        this->selectedButtonIndex = 3;

    if (Helper::isSpriteClicked(button1, *this->_win))
        menuSelection(0);
    if (Helper::isSpriteClicked(button2, *this->_win))
        menuSelection(1);
    if (Helper::isSpriteClicked(button3, *this->_win))
        menuSelection(2);
    if (Helper::isSpriteClicked(button4, *this->_win))
        menuSelection(3);
}

void Menu::menuSelection(int index) {
    std::stringstream ss;
    switch (index) {
        case 0:
            ss << "Connecting to " << config["ip"].get<std::string>() << "...";
            text.setString(ss.str());
            centerText(text);

            if (!this->_connection->connect(config["ip"].get<std::string>(), 4242)) {
                text.setString("Server unreachable, please try again later...");
                centerText(text);
            } else {
                text.setString("Server found, entering lobby");
                centerText(text);

                requestSceneSwitch("serverList");
            }
            break;
        case 1:
#ifdef _WIN32
            ShellExecute(NULL, "open", "client.exe", NULL, NULL, SW_SHOWDEFAULT);
#endif

#if defined(linux) || defined(__APPLE__)
        system("./client");
#endif
        case 2:
            requestSceneSwitch("settings");
            break;
        case 3:
            _win->close();
        default:
            break;
    }
}

void Menu::init() {
    if (!texture1.loadFromFile("assets/PlayOnline.png")) {
        std::cout << "An error occurred." << std::endl;
    }

    if (!texture2.loadFromFile("assets/PlayOffline.png")) {
        std::cout << "An error occurred." << std::endl;
    }

    if (!texture3.loadFromFile("assets/Settings.png")) {
        std::cout << "An error occurred." << std::endl;
    }

    if (!texture4.loadFromFile("assets/Exit.png")) {
        std::cout << "An error occurred." << std::endl;
    }

    if (!textureSelected.loadFromFile("assets/Selected.png")) {
        std::cout << "An error occurred." << std::endl;
    }



    // Setting the texture for the sprites

    button1.setTexture(texture1);
    button2.setTexture(texture2);
    button3.setTexture(texture3);
    button4.setTexture(texture4);
    selected.setTexture(textureSelected);

    // Setting space and position for the sprites

    button1.setPosition(sf::Vector2f((this->_win->getSize().x / 2.0f) - (button1.getTexture()->getSize().x / 2.0f),
                                     250));
    button2.setPosition(sf::Vector2f((this->_win->getSize().x / 2.0f) - (button1.getTexture()->getSize().x / 2.0f),
                                     325));
    button3.setPosition(sf::Vector2f((this->_win->getSize().x / 2.0f) - (button1.getTexture()->getSize().x / 2.0f),
                                     400));
    button4.setPosition(sf::Vector2f((this->_win->getSize().x / 2.0f) - (button1.getTexture()->getSize().x / 2.0f),
                                     475));

    this->selectedButtonIndex = 0;

    std::ifstream file("assets/server_config.json");
    file >> config;

    if (!font.loadFromFile("assets/arial.ttf")) {
        std::cout << "Cannot load ARIAL font" << std::endl;
    }

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
}

void Menu::update() {
    this->_win->draw(button1);
    this->_win->draw(button2);
    this->_win->draw(button3);
    this->_win->draw(button4);

    selected.setPosition(sf::Vector2f((this->_win->getSize().x / 2.0f) - (button1.getTexture()->getSize().x / 2.0f),
                                      250 + (selectedButtonIndex * 75)));
    this->_win->draw(selected);

    this->_win->draw(text);
}

void Menu::centerText(sf::Text &text) {
    sf::FloatRect textRect;

    textRect = text.getLocalBounds();
    text.setPosition(sf::Vector2f(this->_win->getSize().x / 2.0f, this->_win->getSize().y - 35));
    text.setOrigin(textRect.left + textRect.width / 2.0f,
                   textRect.top + textRect.height / 2.0f);
}

void Menu::onSwitch() {

}
