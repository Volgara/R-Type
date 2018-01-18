/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_SETTINGS_HPP
#define RTYPE_SETTINGS_HPP

#include "Settings.hpp"
#include "Scene.hpp"

class Settings : public Scene {
 public:
  Settings(std::string name, sf::RenderWindow *win);
  virtual ~Settings();

 public:
  void init() override;
  void update() override;
};

#endif //RTYPE_SETTINGS_HPP
