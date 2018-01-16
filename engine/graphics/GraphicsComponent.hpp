//
//-----------------------------------------------------------------------------
//Filename:    SpriteComponent.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/15/18.
//-----------------------------------------------------------------------------
//

#ifndef RTYPE_DRAWABLE_HPP
#define RTYPE_DRAWABLE_HPP


#include <core/Component.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Animation.hpp"

namespace engine {
    namespace graphics {
        class GraphicsComponent : public core::Component {
        protected:
            sf::Sprite _sprite;
            std::vector<engine::graphics::Animation *> _animations;
            int currentAnimation;
        public:
            const std::vector<Animation *> &getAnimations() const;

        public:

            GraphicsComponent();
            virtual ~GraphicsComponent() = default;
            void Update(float dt) override;
            void SendMessage(Message *message) override;
            void Init(void) override;
            void ShutDown(void) override;
            void addAnimation(engine::graphics::Animation *animation);
            void play(const std::string &str);
            sf::Sprite &getDrawable();
            void update();
            void setPosition(int x, int y);
        };

    }
}

#endif //RTYPE_DRAWABLE_HPP
