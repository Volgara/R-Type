/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_LOBBY_HPP
#define RTYPE_LOBBY_HPP

#include <SFML/Graphics/Sprite.hpp>
#include "Lobby.hpp"
#include "Scene.hpp"

class Lobby : public Scene {
 public:
  Lobby(const std::string &name, sf::RenderWindow *win);
  virtual ~Lobby();

 public:
  void init() override;
  void update() override;
  void onEvent(sf::Event &event);
  void onSwitch() override;

private:
    sf::Font font;
    sf::Text text;

    sf::Texture ready_;
    sf::Sprite ready;

    sf::Texture refresh_;
    sf::Sprite refresh;

    sf::Texture back_;
    sf::Sprite back;
    bool inGame;
};

#endif //RTYPE_LOBBY_HPP
