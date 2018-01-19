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
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include "SceneManager.hpp"
#include "Settings.hpp"
#include "Menu.hpp"
#include "Lobby.hpp"
#include "ServerList.hpp"

int main(int ac, char **av) {

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "RType Launcher", sf::Style::Titlebar | sf::Style::Close);
    window.setMouseCursorVisible(false); // Hide cursor

    sf::Texture texture;
    if (!texture.loadFromFile("assets/cursor.png")) {
        std::cout << "An error occurred." << std::endl;
    }
    sf::Sprite sprite(texture);

    sf::Texture textureBg;
    if (!textureBg.loadFromFile("assets/bg.png")) {
        std::cout << "An error occurred." << std::endl;
    }
    sf::Sprite bg(textureBg);
    bg.setPosition(0, 0);

    sf::View fixed = window.getView();

    SceneManager sm;

    sm.connection = new Connection();

    Menu       menu("menu", &window);
    Settings   settings("settings", &window);
    ServerList serverList("serverList", &window);
    Lobby      lobby("lobby", &window);

    sm.addScene(&menu);
    sm.addScene(&settings);
    sm.addScene(&serverList);
    sm.addScene(&lobby);

    sm.switchScene("menu");

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            sm.getCurrentScene()->onEvent(event);
        }

        window.clear(sf::Color::Black);

        window.draw(bg);

        sm.getCurrentScene()->update();

        sprite.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
        window.setView(fixed);
        window.draw(sprite);

        // end the current frame
        window.display();

        if (sm.isSwitchRequested())
            sm.switchScene();
    }

    return 0;

}