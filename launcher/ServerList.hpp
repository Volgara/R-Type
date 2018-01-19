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
#include "Connection.hpp"
#include "GraphicalRoom.hpp"

class ServerList : public Scene {
 public:
  ServerList(const std::string &name, sf::RenderWindow *win);
  virtual ~ServerList();

 public:
  void init() override;
  void update() override;
  void onEvent(sf::Event &event) override;
  void onSwitch() override;

 private:
  sf::Font font;
  sf::Text text;
  sf::Text textCurrentlyTyped;

  sf::Texture backButton_;
  sf::Texture lobbyView_;
  sf::Texture CreateServer_;
  sf::Texture Cancel_;
  sf::Texture InputText_;

  sf::Sprite backButton;
  sf::Sprite lobbyView;
  sf::Sprite CreateServer;
  sf::Sprite Cancel;
  sf::Sprite InputText;

  bool canType;
  std::string currentTyped;
  std::vector<GraphicalRoom *> graphicalRooms;
  void emptyGraphicalRoomsFound();
};

#endif //RTYPE_SERVERLIST_HPP
