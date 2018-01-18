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

int main(int ac, char **av) {

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "RType Launcher", sf::Style::Titlebar | sf::Style::Close);
    window.setMouseCursorVisible(false); // Hide cursor

    sf::Texture texture;
    texture.loadFromFile("assets/cursor.png");
    sf::Sprite sprite(texture);

    sf::View fixed = window.getView();

    SceneManager sm;

    Menu menu("menu", &window);
    //Scene *settings = new Settings("menu", &window);

    sm.addScene(&menu);
    //sm.addScene(settings);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            sm.getCurrentScene()->onEvent(event);
        }

        window.clear(sf::Color::Black);

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