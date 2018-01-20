//
// Created by Hamza Hammouche on 20/01/2018.
//

#ifndef RTYPE_SPACESHIP_HPP
#define RTYPE_SPACESHIP_HPP

namespace game {
    class SpaceShip {
    protected:
        int _life;
        int _damage;
        int _shield;
        int _speed;
    public:
        SpaceShip(int _life, int _damage, int _shield, int _speed);

        int getLife() const;

        int getDamage() const;

        int getShield() const;

        void takeDamage(int damage);

        int getSpeed() const;
    };
}


#endif //RTYPE_SPACESHIP_HPP
