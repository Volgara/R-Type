/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_SCENE_HPP
#define RTYPE_SCENE_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "Scene.hpp"
#include "Connection.hpp"

class Scene {
 public:
  Scene(const std::string &name, sf::RenderWindow *win);
  virtual ~Scene();

  void setRequestSwitch(const std::string &string);
 public:
  virtual void init() = 0;
  virtual void update() = 0;
  virtual void onEvent(sf::Event &event) = 0;
  virtual void onSwitch() = 0;

 public:
  const std::string &getName() const;
  const std::string &getRequestSwitch();

 protected:
  void requestSceneSwitch(const std::string &newScene);

 protected:
  std::string      _name;
  sf::RenderWindow *_win;
  Connection  *_connection;
 public:
  void setConnection(Connection *_connection);

 private:
  std::string _requestSwitch;
};

#endif //RTYPE_SCENE_HPP
