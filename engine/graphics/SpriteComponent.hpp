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

namespace engine {
    namespace graphics {
        class SpriteComponent : public core::Component {
        protected:
            bool _active;
            int _x = 0; // TODO : use another system point 2D
            int _y = 0;

        public:

            SpriteComponent() = default;

            virtual ~SpriteComponent() = default;

            void Update(float dt) override;

            void SendMessage(Message *message) override;

            void Init(void) override;

            void ShutDown(void) override;

            bool Active(void) const override;

            // TODO : use another system point 2D

            int getX() const;

            int getY() const;

            void setX(int _x);

            void setY(int _y);
        };

    }
}

#endif //RTYPE_DRAWABLE_HPP
