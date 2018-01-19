/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_SERVERLIST_HPP
#define RTYPE_SERVERLIST_HPP

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "ServerList.hpp"
#include "Scene.hpp"

class ServerList : public Scene {
 public:
  ServerList(std::string name, sf::RenderWindow *win);
  virtual ~ServerList();

 public:
  void init() override;
  void update() override;
  void onEvent(sf::Event &event) override;

 private:
  sf::Font font;
  sf::Text text;

  sf::Texture backButton_;
  sf::Texture lobbyView_;

  sf::Sprite backButton;
  sf::Sprite lobbyView;

};

#endif //RTYPE_SERVERLIST_HPP
