/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 19/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_HELPER_HPP
#define RTYPE_HELPER_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
class Helper {
 public:
  Helper();
  virtual ~Helper();

 public:
  static void centerElement(sf::Text &element, const sf::RenderWindow *win, bool = true, bool = true);
  static void centerElement(sf::Sprite &element, const sf::RenderWindow *win, bool = true, bool = true);
};

#endif //RTYPE_HELPER_HPP
