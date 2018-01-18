/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_SCENE_HPP
#define RTYPE_SCENE_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "Scene.hpp"

class Scene {
 public:
  Scene(std::string name, sf::RenderWindow *win);
  virtual ~Scene();

  void setRequestSwitch(const std::string &string);
 public:
  virtual void init();
  virtual void update();
  virtual void onEvent(sf::Event &event);

 public:
  const std::string &getName() const;
  const std::string &getRequestSwitch();

 protected:
  void requestSceneSwitch(const std::string &newScene);

 protected:
  std::string      _name;
  sf::RenderWindow *_win;

 private:
  std::string      _requestSwitch;
};

#endif //RTYPE_SCENE_HPP
