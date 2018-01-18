/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>

int main(int ac, char **av) {

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "RType Launcher", sf::Style::Titlebar | sf::Style::Close);

    sf::Texture texture1;
    sf::Texture texture2;
    sf::Texture texture3;
    sf::Texture texture4;
    sf::Texture textureSelected;

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

    // Sprites declaration

    sf::Sprite button1, button2, button3, button4, selected;

    // Setting the texture for the sprites

    button1.setTexture(texture1);
    button2.setTexture(texture2);
    button3.setTexture(texture3);
    button4.setTexture(texture4);
    selected.setTexture(textureSelected);

    // Setting space and position for the sprites

    button1.setPosition(sf::Vector2f((window.getSize().x / 2) - (button1.getTexture()->getSize().x / 2), 300));
    button2.setPosition(sf::Vector2f((window.getSize().x / 2) - (button1.getTexture()->getSize().x / 2), 375));
    button3.setPosition(sf::Vector2f((window.getSize().x / 2) - (button1.getTexture()->getSize().x / 2), 450));
    button4.setPosition(sf::Vector2f((window.getSize().x / 2) - (button1.getTexture()->getSize().x / 2), 525));

    int selectedButtonIndex = 0;


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
        }


        // clear the window with black color
        window.clear(sf::Color::Black);

        window.draw(button1);
        window.draw(button2);
        window.draw(button3);
        window.draw(button4);

        selected.setPosition(sf::Vector2f((window.getSize().x / 2) - (button1.getTexture()->getSize().x / 2),
                                          300 + (selectedButtonIndex * 75)));
        window.draw(selected);


        // end the current frame
        window.display();
    }

    return 0;

}