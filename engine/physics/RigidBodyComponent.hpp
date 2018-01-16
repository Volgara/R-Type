//
// Created by Hamza Hammouche on 12/01/2018.
//

#ifndef RTYPE_RIGIDBODYCOMPONENT_HPP
#define RTYPE_RIGIDBODYCOMPONENT_HPP

#include <core/Component.hpp>
#include "Box.hpp"

namespace engine {
    namespace physics {
        class RigidBodyComponent : public core::Component {
        private:
            core::Vector2d _position = core::Vector2d(0, 0);
            core::Vector2d _velocity = core::Vector2d(0, 0);
            core::Vector2d _size = core::Vector2d(0, 0);
            Box      *_box;
        public:
            RigidBodyComponent();

            virtual ~RigidBodyComponent();

            void SendMessage(Message *message) override;

            void Update(float dt) override;

            void Init(void) override;

            void ShutDown(void) override;

            void move();

            bool checkIntersect(const RigidBodyComponent *body);

            const core::Vector2d &getPosition() const;

            void setPosition(const core::Vector2d &position);

            const core::Vector2d &getVelocity() const;

            void setVelocity(const core::Vector2d &velocity);

            const core::Vector2d &getSize() const;

            void setSize(const core::Vector2d &size);

            Box *getBox() const;
        };
    }
}


#endif //RTYPE_RIGIDBODYCOMPONENT_HPP
