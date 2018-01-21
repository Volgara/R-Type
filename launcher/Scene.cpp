/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include "Scene.hpp"

Scene::Scene(const std::string &name, sf::RenderWindow *win) {
    this->_name = name;
    this->_win = win;
    this->_requestSwitch = "";
}

Scene::~Scene() {

}

const std::string &Scene::getName() const {
    return _name;
}
void Scene::requestSceneSwitch(const std::string &newScene) {
    this->_requestSwitch = newScene;
}
const std::string &Scene::getRequestSwitch() {
    return this->_requestSwitch;
}
void Scene::setRequestSwitch(const std::string &string) {
    this->_requestSwitch = string;
}
void Scene::setConnection(Connection *connection) {
    this->_connection = connection;
}
