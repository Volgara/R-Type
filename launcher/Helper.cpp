/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 19/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
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
