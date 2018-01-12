/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 12/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_ANIMATION_HPP
#define RTYPE_ANIMATION_HPP


#include <string>
#include "SpriteSheet.hpp"

namespace RType {
    class Animation {

    public:
        Animation(std::string name, RType::SpriteSheet sheet);

        void loadSpriteSheet(std::string file, int width, int height, int cols, int rows);

        void setAnimationFrames(int start, int end);

        void addFrame(int index, int x, int y);
    };
}


#endif //RTYPE_ANIMATION_HPP
