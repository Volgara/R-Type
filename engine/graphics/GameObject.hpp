/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 12/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_GAMEOBJECT_HPP
#define RTYPE_GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>
#include "Position.hpp"
#include "Orientation.hpp"
#include "Animation.hpp"

namespace RType {
    class GameObject {
    public:
        GameObject();

        ~GameObject();

        void addAnimation(Animation animation);

        void play(std::string str, bool b);

    private:
        sf::Sprite sprite;
        sf::Texture texture;
        RType::Position position;
        RType::Orientation orientation;
        std::vector<RType::Animation> animations;
    };
}

#endif //RTYPE_GAMEOBJECT_HPP
