/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 12/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_ANIMATION_HPP
#define RTYPE_ANIMATION_HPP


#include <string>
#include "SpriteSheet.hpp"

namespace engine {
    namespace graphics {
        class Animation {

        public:
            Animation(const std::string &name, engine::graphics::SpriteSheet *_spriteSheet);
            Animation(const Animation &anim);

            void setInitialFrame(int initialFrame);
            void setReverse(bool reverse);
        public:
            void loadSpriteSheet(std::string file, int width, int height, int cols, int rows);
            void setAnimationFrames(int start, int end);
            void addFrame(int x, int y);
            const std::string &getName() const;
            sf::Sprite getCurrentSprite();
            float getCurrenFrame() const;
            void setCurrentFrame(float currenFrame);
            void setLoop(bool loop);
            const SpriteSheet *getSpriteSheet() const;

        protected:
            std::string _name;
            SpriteSheet *_spriteSheet;
            std::vector<sf::Sprite> _frames;
        public:
            const std::vector<sf::Sprite> &getFrames() const;
        protected:
            float _currenFrame;
            bool _loop;
            bool _reverse;
        };
    }
}


#endif //RTYPE_ANIMATION_HPP
