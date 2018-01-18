/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_SCENEMANAGER_HPP
#define RTYPE_SCENEMANAGER_HPP

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.hpp"
class SceneManager {
 public:
  SceneManager();
  virtual ~SceneManager();
  void addScene(Scene *scene);
  Scene *getCurrentScene();

 public:
  std::vector<Scene *> _scenes;
  int _currentScene;
  bool isSwitchRequested();
  void switchScene();
  Scene *findScene(const std::string &search);
  int findSceneIndex(const std::string &search);
  void switchScene(const std::string &basic_string);
};

#endif //RTYPE_SCENEMANAGER_HPP
