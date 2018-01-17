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

         public:
            void setReverse(bool reverse);
            void setPingPong(bool pingpong);
            void setSpeed(int speed);
            void setLoop(bool loop);

          bool isReverse();
          bool isPingPong();
          bool isLoop();
        public:
            void setAnimationFrames(int start, int end);
            void addFrame(int x, int y);
            const std::string &getName() const;
            sf::Sprite getCurrentSprite();
            int getCurrenFrameIndex() const;
            sf::Sprite getCurrenFrame() const;
            void setCurrentFrameIndex(int currenFrame);
            const SpriteSheet *getSpriteSheet() const;
            int getSpeed() const;
            const std::vector<sf::Sprite> &getFrames() const;

        protected:
            std::string _name;
            SpriteSheet *_spriteSheet;
            std::vector<sf::Sprite> _frames;
            int _currenFrame;

            bool _loop;
            bool _reverse;
            bool _pingPong;
            int _speed;
        };
    }
}


#endif //RTYPE_ANIMATION_HPP
