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

            /**
             * Constructor / Destructor
             */
        public:
            GraphicsComponent();
            virtual ~GraphicsComponent() = default;

            /**
             * Methods
             */
        public:
            void Update(float dt) override;
            void SendMessage(engine::core::Message *message) override;
            void Init(void) override;
            void ShutDown(void) override;
            void addAnimation(engine::graphics::Animation *animation);
            void play(const std::string &str);
            void update(float dt);

            /**
             * Getters / Setters
             */
        public:
            sf::Sprite &getDrawable();
            void setPosition(int x, int y);
            int getCurrentAnimationIndex() const;
            Animation *const & getCurrentAnimation() const;
            void setCurrentAnimation(int currentAnimation);
            const std::vector<Animation *> &getAnimations() const;

            /**
             * Properties
             */
        protected:
            sf::Sprite                                 _sprite;
            std::vector<engine::graphics::Animation *> _animations;
            int                                        _currentAnimation;
            float                                      _dtCounter;
        };
    }
}

#endif //RTYPE_DRAWABLE_HPP
