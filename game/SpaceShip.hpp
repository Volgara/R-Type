//
// Created by Hamza Hammouche on 20/01/2018.
//

#ifndef RTYPE_SPACESHIP_HPP
#define RTYPE_SPACESHIP_HPP

#include <core/Vector2D.hpp>

namespace game {
    class SpaceShip {
    protected:
        int _life;
        int _damage;
        int _speed;
        engine::core::Vector2d _size;
    public:
        SpaceShip(int _life, int _damage, int speed, const engine::core::Vector2d &size);

        int getLife() const;

        int getDamage() const;

        void takeDamage(int damage);

        int getSpeed() const;

        const engine::core::Vector2d &getSize() const;
    };
}


#endif //RTYPE_SPACESHIP_HPP
