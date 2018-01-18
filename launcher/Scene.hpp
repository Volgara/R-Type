/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_SCENE_HPP
#define RTYPE_SCENE_HPP

#include "Scene.hpp"

class Scene {
 public:
  Scene();
  virtual ~Scene();

 public:
  virtual void init();
  virtual void render();
  virtual void update();
};

#endif //RTYPE_SCENE_HPP
