//
// Created by macdoy on 12/01/18.
//

#include "Enemy.hpp"

extern "C" Enemy *create_object(int x, int y, int id, int hp, float delay, etype type) {
    return new Enemy(x, y, id, hp, delay, type);
}

extern "C" void destroy_object(Enemy *enemy) {
    delete enemy;
}

Enemy::Enemy(int x, int y, int id, int hp, float delay, etype type) {
    _x = x;
    _y = y;
    _id = id;
    _hp = hp;
    _delay = delay;
    _type = type;
}

void Enemy::nextFrame() {
    std::cout << "next frame\n";
}

void Enemy::move() {
    std::cout << "moved\n";
}

void Enemy::shoot() const {
    std::cout << "shoot\n";
}

void Enemy::getNearPlayer() const {
    std::cout << "get near player\n";
}

void Enemy::loseHp(int dmg) {
    _hp -= dmg;
}

void Enemy::setX(int x) {
    _x = x;
}

void Enemy::setY(int y) {
    _y = y;
}

void Enemy::setId(int id) {
    _id = id;
}

void Enemy::setHp(int hp) {
    _hp = hp;
}

void Enemy::setDelay(float delay){
    _delay = delay;
}

void Enemy::setType(etype type) {
    _type = type;
}

int Enemy::getX() const {
    return _x;
}

int Enemy::getY() const {
    return _y;
}

int Enemy::getId() const {
    return _id;
}

int Enemy::getHp() const {
    return _hp;
}

float Enemy::getDelay() const {
    return _delay;
}

etype Enemy::getType() const {
    return _type;
}





