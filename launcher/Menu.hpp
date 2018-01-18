/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_MENU_HPP
#define RTYPE_MENU_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Menu.hpp"
#include "Scene.hpp"
#include "json.hpp"
#include "Connection.hpp"

class Menu : public Scene {
 public:
  Menu(std::string name, sf::RenderWindow *win);
  virtual ~Menu();

 public:
  void init() override;
  void update() override;
  void onEvent(sf::Event &event) override;

 private:
  void centerText(sf::Text &text);
  // Internal class values
 private:
  int selectedButtonIndex;

  sf::Texture texture1, texture2, texture3, texture4, textureSelected, textureBg;
  sf::Sprite  button1, button2, button3, button4, selected, bg;

  nlohmann::json config;
  sf::Font       font;
  sf::Text       text;

  Connection mm;
};

#endif //RTYPE_MENU_HPP
