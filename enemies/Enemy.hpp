//
// Created by macdoy on 12/01/18.
//

#ifndef RTYPE_ENEMY_HPP
#define RTYPE_ENEMY_HPP

#include "IEnemy.hpp"

class Enemy : public IEnemy {
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
    Enemy(int x, int y, int id, int hp, float delay, etype type);

    virtual void nextFrame();
    // return pair nouvelle position
    virtual void move();
    // return pointeur sur le projectil créé
    virtual void shoot() const;
    // ask to the server the nearest player. expected pair pos
    void getNearPlayer() const;
    void loseHp(int dmg);

    void setX(int x);
    void setY(int y);
    void setId(int id);
    void setHp(int hp);
    void setDelay(float delay);
    void setType(etype type);

    int getX() const;
    int getY() const;
    int getId() const;
    int getHp() const;
    float getDelay() const;
    etype getType() const;
};


#endif //RTYPE_ENEMY_HPP
