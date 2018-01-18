/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_SETTINGS_HPP
#define RTYPE_SETTINGS_HPP

#include "Settings.hpp"
#include "AScene.hpp"

class Settings : public AScene {
 public:
  Settings();
  virtual ~Settings();

 public:
  virtual void init();
  virtual void render();
  virtual void update();
};

#endif //RTYPE_SETTINGS_HPP
