/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 12/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include "GameObject.hpp"

RType::GameObject::GameObject(){

}

RType::GameObject::~GameObject() {

}

void RType::GameObject::addAnimation(RType::Animation animation) {
    this->animations.push_back(animation);
}

void RType::GameObject::play(std::string str, bool b) {

}
