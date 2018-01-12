//
// Created by macdoy on 12/01/18.
//

#ifndef RTYPE_IENEMY_HPP
#define RTYPE_IENEMY_HPP

#include <iostream>
#include <string>

enum etype {
    BUG,
    SNAKE,
    FLEAT,
    SNAIL
};

class IEnemy {
private:
    //to become a pair
    int _x;
    int _y;
    //maybe needed?
    int _id;
    int _hp;
    //delay between shoots
    float _delay;
    etype _type;
public:
    virtual void nextFrame() = 0;
    // return pair nouvelle position
    virtual void move() = 0;
    // return pointeur sur le projectil créé
    virtual void shoot() const = 0;
    // ask to the server the nearest player. expected pair pos
    virtual void getNearPlayer() const = 0;
    virtual void loseHp(int dmg) = 0;

    virtual void setX(int x) = 0;
    virtual void setY(int y) = 0;
    virtual void setId(int id) = 0;
    virtual void setHp(int hp) = 0;
    virtual void setDelay(float delay) = 0;
    virtual void setType(etype type) = 0;

    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual int getId() const = 0;
    virtual int getHp() const = 0;
    virtual float getDelay() const = 0;
    virtual etype getType() const = 0;
};


#endif //RTYPE_IENEMY_HPP
