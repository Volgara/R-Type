//
// Created by macdoy on 12/01/18.
//

#include <iostream>
#include <dlfcn.h>
#include "Enemy.hpp"

int main() {
    void *handle = dlopen("enemy.so", RTLD_LAZY);

    Enemy* (*create)(int, int, int, int, float, etype);
    void (*destroy)(Enemy*);

    create = (Enemy* (*)(int, int, int, int, float, etype))dlsym(handle, "create_object");
    destroy = (void (*)(Enemy *))dlsym(handle, "destroy_object");

    Enemy *en = (Enemy*)create(0, 0, 0, 0, 0, SNAKE);

    std::cout << en->getHp() << std::endl;
    en->getNearPlayer();
    en->shoot();
    destroy(en);
    return 0;
}