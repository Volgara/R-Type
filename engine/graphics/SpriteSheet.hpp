/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 12/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_SPRITESHEET_HPP
#define RTYPE_SPRITESHEET_HPP

#include <string>
#include <SFML/Graphics/Texture.hpp>

namespace engine {
    namespace graphics {
        class SpriteSheet {
        public:
            SpriteSheet(std::string file, int width, int height, int cols, int rows);
            ~SpriteSheet();

        protected:
            int _width;
            int _height;
            int _cols;
            int _rows;
            int _frameWidth;
            int _frameHeight;
            sf::Texture *_texture;

        public:
            int getFrameWidth() const;
            void setFrameWidth(int _frameWidth);
            int getFrameHeight() const;
            void setFrameHeight(int _frameHeight);
            int getCols() const;
            void setCols(int _cols);
            int getRows() const;
            void setRows(int _rows);
            const sf::Texture *getTexture() const;
        };
    }
}


#endif //RTYPE_SPRITESHEET_HPP
