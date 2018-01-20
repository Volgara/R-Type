/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 19/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include <iostream>
#include "GraphicalRoom.hpp"

GraphicalRoom::GraphicalRoom(Room &room) {
    if (!font.loadFromFile("assets/arial.ttf")) {
        std::cout << "Cannot load ARIAL font" << std::endl;
    }

    text_left.setFont(font);
    text_left.setCharacterSize(24);
    text_left.setFillColor(sf::Color::White);

    text_right.setFont(font);
    text_right.setCharacterSize(24);
    text_right.setFillColor(sf::Color::White);

    this->name = room.getName();

    this->nbPlayer = room.getNbPlayers();

    if (!texture.loadFromFile("assets/NotSelectedServer.png")) { // TODO change resource
        std::cout << "An error occurred." << std::endl;
    }
    sprite.setTexture(texture);
}

GraphicalRoom::~GraphicalRoom() {

}
