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
  static void centerElement(sf::Text &element, const sf::RenderWindow *win, bool horiz = true, bool vert = true);
  static void centerElement(sf::Sprite &element, const sf::RenderWindow *win, bool horiz = true, bool vert = true);
  static bool isSpriteClicked(const sf::Sprite &sprite, const sf::RenderWindow &window);
  static bool isMouseHover(const sf::Sprite &sprite, const sf::RenderWindow &window);
  static std::vector<std::string> explode(const std::string &s, char delim);
};

#endif //RTYPE_HELPER_HPP
