/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include <iostream>
#include "SceneManager.hpp"
SceneManager::SceneManager() {
    this->_currentScene = 0;
}

SceneManager::~SceneManager() {

}

void SceneManager::addScene(Scene *scene) {
    scene->init();
    this->_scenes.push_back(scene);
}

Scene *SceneManager::getCurrentScene() {
    return _scenes[this->_currentScene];
}

bool SceneManager::isSwitchRequested() {
    return !this->getCurrentScene()->getRequestSwitch().empty();
}
void SceneManager::switchScene() {
    std::string scene = this->getCurrentScene()->getRequestSwitch();

    std::cout << "Switch requested to " << scene << std::endl;

    this->getCurrentScene()->setRequestSwitch("");
    this->switchScene(scene);
}
Scene *SceneManager::findScene(const std::string &search) {
    for (auto &scene : this->_scenes) {
        if (scene->getName() == search)
            return scene;
    }
    return nullptr;
}

int SceneManager::findSceneIndex(const std::string &search) {
    int       i = 0;
    for (auto &scene : this->_scenes) {
        if (scene->getName() == search)
            return i;
        i++;
    }
    return -1;
}
void SceneManager::switchScene(const std::string &scene) {
    int i = this->findSceneIndex(scene);
    if (i != -1)
    {
        this->_currentScene = i;
        std::cout << "Current scene switch to " << this->_currentScene << " (" << this->_scenes[this->_currentScene]->getName() << ")" << std::endl;
    }
    else
        std::cout << "Scene " << scene << " not found" << std::endl;
}
