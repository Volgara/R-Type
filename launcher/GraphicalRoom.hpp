/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 19/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_GRAPHICALROOM_HPP
#define RTYPE_GRAPHICALROOM_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <sstream>
#include "Room.hpp"
class GraphicalRoom {
 public:
  GraphicalRoom(Room &r);
  virtual ~GraphicalRoom();

 public:

 public: //TODO switch to private
  sf::Texture texture;
  sf::Sprite sprite;
  sf::Font font;
  sf::Text text;

  int nbPlayer;

  Room *r;

  std::stringstream displayText;
  std::string name;
};

#endif //RTYPE_GRAPHICALROOM_HPP
