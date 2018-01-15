/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 12/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_SPRITESHEET_HPP
#define RTYPE_SPRITESHEET_HPP

#include <string>

namespace engine {
    namespace graphics {
        class SpriteSheet {
        public:
            SpriteSheet(std::string file, int width, int height, int cols, int rows);

            ~SpriteSheet();
        };
    }
}


#endif //RTYPE_SPRITESHEET_HPP
