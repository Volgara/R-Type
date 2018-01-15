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
            bool _active;

            sf::Sprite sprite;
            sf::Texture texture;
            std::vector<engine::graphics::Animation> animations;

        public:

            GraphicsComponent() = default;

            virtual ~GraphicsComponent() = default;

            void Update(float dt) override;

            void SendMessage(Message *message) override;

            void Init(void) override;

            void ShutDown(void) override;

            bool Active(void) const;

            void addAnimation(engine::graphics::Animation animation);

            void play(std::string str, bool b);

        };

    }
}

#endif //RTYPE_DRAWABLE_HPP
