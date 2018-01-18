/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_MENU_HPP
#define RTYPE_MENU_HPP

#include "Menu.hpp"
#include "AScene.hpp"

class Menu : public AScene {
 public:
  Menu();
  virtual ~Menu();

 public:
  virtual void init();
  virtual void render();
  virtual void update();
};

#endif //RTYPE_MENU_HPP
