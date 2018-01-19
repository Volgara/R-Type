/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include <fstream>
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include "Menu.hpp"
#include "Connection.hpp"
#include "json.hpp"

Menu::Menu(std::string name, sf::RenderWindow *win) : Scene(name, win) {

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
        std::stringstream ss;

        switch (this->selectedButtonIndex) {
            case 0:
                ss << "Connecting to " << config["ip"].get<std::string>() << "...";
                text.setString(ss.str());
                this->centerText(text);

                if (!mm.connect(config["ip"].get<std::string>(), 4242)) {
                    text.setString("Server unreachable, please try again later...");
                    this->centerText(text);
                } else {
                    text.setString("Server found, entering lobby");
                    this->centerText(text);

                    this->requestSceneSwitch("serverList");
                }
                break;
            case 1:
                // play offline
            case 2:
                this->requestSceneSwitch("settings");
                break;
            case 3:
                this->_win->close();
            default:
                break;
        }
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
