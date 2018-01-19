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

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    this->name = room.getName();

    this->nbPlayer = room.getNbPlayers();

    std::string empty;
    for (int i = static_cast<int>(room.getName().length()); i < 70; ++i) {
        empty += " ";
    }

    this->displayText << room.getName() << empty << room.getNbPlayers();

    if (!texture.loadFromFile("assets/Field.png")) { // TODO change resource
        std::cout << "An error occurred." << std::endl;
    }
    sprite.setTexture(texture);
}

GraphicalRoom::~GraphicalRoom() {

}
