/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 12/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "SpriteSheet.hpp"

engine::graphics::SpriteSheet::SpriteSheet(std::string file, int width, int height, int cols, int rows) {
    this->_width = width;
    this->_height = height;
    this->_cols = cols;
    this->_rows = rows;
    this->_frameWidth = this->_width / this->_cols;
    this->_frameHeight = this->_height / this->_rows;

    std::cout << "Creating texture from " << file << std::endl;

    if (!this->_texture.loadFromFile(file))
    {
        throw std::runtime_error("Cannot load texture");
    }
}

engine::graphics::SpriteSheet::~SpriteSheet() {

}

const sf::Texture &engine::graphics::SpriteSheet::getTexture() const {
    return _texture;
}

int engine::graphics::SpriteSheet::getCols() const {
    return _cols;
}

void engine::graphics::SpriteSheet::setCols(int _cols) {
    this->_cols = _cols;
}

int engine::graphics::SpriteSheet::getRows() const {
    return _rows;
}

void engine::graphics::SpriteSheet::setRows(int _rows) {
    this->_rows = _rows;
}

int engine::graphics::SpriteSheet::getFrameWidth() const {
    return _frameWidth;
}

void engine::graphics::SpriteSheet::setFrameWidth(int _frameWidth) {
    this->_frameWidth = _frameWidth;
}

int engine::graphics::SpriteSheet::getFrameHeight() const {
    return _frameHeight;
}

void engine::graphics::SpriteSheet::setFrameHeight(int _frameHeight) {
    this->_frameHeight = _frameHeight;
}
