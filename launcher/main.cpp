/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <fstream>
#include "json.hpp"
#include "Connection.hpp"
#include "SceneManager.hpp"
#include "Settings.hpp"
#include "Menu.hpp"

using json = nlohmann::json;

int main(int ac, char **av) {

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "RType Launcher", sf::Style::Titlebar | sf::Style::Close);
    window.setMouseCursorVisible(false); // Hide cursor

    sf::Texture texture;
    texture.loadFromFile("assets/cursor.png");
    sf::Sprite sprite(texture);

    sf::View fixed = window.getView();

    SceneManager sm;

    AScene *menu     = new Menu();
    AScene *settings = new Settings();

    sm.addScene("menu", menu);
    sm.addScene("settings", settings);

    sf::Texture texture1;
    sf::Texture texture2;
    sf::Texture texture3;
    sf::Texture texture4;
    sf::Texture textureSelected;
    sf::Texture textureBg;

    // Checking for loading errors

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

    if (!textureBg.loadFromFile("assets/bg.png")) {
        std::cout << "An error occurred." << std::endl;
    }

    // Sprites declaration

    sf::Sprite button1, button2, button3, button4, selected, bg;

    // Setting the texture for the sprites

    button1.setTexture(texture1);
    button2.setTexture(texture2);
    button3.setTexture(texture3);
    button4.setTexture(texture4);
    selected.setTexture(textureSelected);
    bg.setTexture(textureBg);

    // Setting space and position for the sprites

    button1.setPosition(sf::Vector2f((window.getSize().x / 2.0f) - (button1.getTexture()->getSize().x / 2.0f), 250));
    button2.setPosition(sf::Vector2f((window.getSize().x / 2.0f) - (button1.getTexture()->getSize().x / 2.0f), 325));
    button3.setPosition(sf::Vector2f((window.getSize().x / 2.0f) - (button1.getTexture()->getSize().x / 2.0f), 400));
    button4.setPosition(sf::Vector2f((window.getSize().x / 2.0f) - (button1.getTexture()->getSize().x / 2.0f), 475));
    bg.setPosition(0, 0);

    int selectedButtonIndex = 0;

    // play online
    MatchMaking   mm;
    std::ifstream file("assets/server_config.json");
    json          config;
    file >> config;

    sf::Font font;
    if (!font.loadFromFile("assets/arial.ttf")) {
        std::cout << "Cannot load ARIAL font" << std::endl;
    }
    sf::Text text;

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    sf::FloatRect textRect;

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                if (selectedButtonIndex == 3)
                    selectedButtonIndex = 0;
                else
                    selectedButtonIndex++;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                if (selectedButtonIndex == 0)
                    selectedButtonIndex = 3;
                else
                    selectedButtonIndex--;
            }

            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return) {
                std::stringstream ss;

                switch (selectedButtonIndex) {
                    case 0:
                        ss << "Connecting to " << config["ip"].get<std::string>() << "...";
                        text.setString(ss.str());

                        textRect = text.getLocalBounds();
                        text.setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y - 35));
                        text.setOrigin(textRect.left + textRect.width / 2.0f,
                                       textRect.top + textRect.height / 2.0f);

                        mm.connect(config["ip"].get<std::string>(), 4242);
                        break;
                    case 1:
                        // play offline
                    case 2:
                        // settings
                        break;
                    case 3:
                        window.close();
                        return (0);
                    default:
                        break;
                }
            }
        }


        // clear the window with black color
        window.clear(sf::Color::Black);

        window.draw(bg);
        window.draw(button1);
        window.draw(button2);
        window.draw(button3);
        window.draw(button4);

        selected.setPosition(sf::Vector2f((window.getSize().x / 2.0f) - (button1.getTexture()->getSize().x / 2.0f),
                                          250 + (selectedButtonIndex * 75)));
        window.draw(selected);


        sprite.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
        window.setView(fixed);
        window.draw(sprite);

        window.draw(text);

        // end the current frame
        window.display();
    }

    return 0;

}