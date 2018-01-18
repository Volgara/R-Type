/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_SCENEMANAGER_HPP
#define RTYPE_SCENEMANAGER_HPP

#include <string>
#include "Scene.hpp"
class SceneManager {
 public:
  SceneManager();
  virtual ~SceneManager();
  void addScene(std::string name, Scene *scene);
};

#endif //RTYPE_SCENEMANAGER_HPP
