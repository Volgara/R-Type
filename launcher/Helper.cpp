/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 19/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Helper.hpp"
Helper::Helper() {}
Helper::~Helper() {

}
void Helper::centerElement(sf::Text &element, const sf::RenderWindow *win, bool horiz, bool vert) {
    sf::FloatRect textRect;

    textRect = element.getLocalBounds();
    element.setPosition(sf::Vector2f(horiz ? win->getSize().x / 2.0f : element.getPosition().x,
                                     vert ? win->getSize().y / 2.0f : element.getPosition().y));
    element.setOrigin(textRect.left + textRect.width / 2.0f,
                      textRect.top + textRect.height / 2.0f);
}

void Helper::centerElement(sf::Sprite &element, const sf::RenderWindow *win, bool horiz, bool vert) {
    sf::FloatRect textRect;

    textRect = element.getLocalBounds();
    element.setPosition(sf::Vector2f(horiz ? win->getSize().x / 2.0f : element.getPosition().x,
                                     vert ? win->getSize().y / 2.0f : element.getPosition().y));
    element.setOrigin(textRect.left + textRect.width / 2.0f,
                      textRect.top + textRect.height / 2.0f);
}

bool Helper::isSpriteClicked(const sf::Sprite &sprite, const sf::RenderWindow &window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        // transform the mouse position from window coordinates to world coordinates
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        // retrieve the bounding box of the sprite
        sf::FloatRect bounds = sprite.getGlobalBounds();

        // hit test
        if (bounds.contains(mouse)) {
            return true;
        }
    }
    return false;
}

bool Helper::isMouseHover(const sf::Sprite &sprite, const sf::RenderWindow &window) {
    // transform the mouse position from window coordinates to world coordinates
    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    // retrieve the bounding box of the sprite
    sf::FloatRect bounds = sprite.getGlobalBounds();

    // hit test
    return bounds.contains(mouse);
}