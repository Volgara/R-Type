//
// Created by Hamza Hammouche on 12/01/2018.
//

#ifndef RTYPE_RIGIDBODYCOMPONENT_HPP
#define RTYPE_RIGIDBODYCOMPONENT_HPP

#include "../core/Component.hpp"
#include "Vector2D.hpp"
#include "Box.hpp"

namespace engine {
    namespace physics {
        class RigidBodyComponent : public core::Component {
        private:
            Vector2d    _position;
            Vector2d    _velocity;
            Vector2d    _size;
            Box      *_box;
        public:
            RigidBodyComponent(engine::physics::Vector2d position,
                                           engine::physics::Vector2d velocity, Vector2d size);

            virtual ~RigidBodyComponent();

            void SendMessage(Message *message) override;

            void Update(float dt) override;

            void Init(void) override;

            void ShutDown(void) override;

            void move();

            bool checkIntersect(const RigidBodyComponent *body);

            const Vector2d &getPosition() const;

            void setPosition(const Vector2d &position);

            const Vector2d &getVelocity() const;

            void setVelocity(const Vector2d &velocity);

            const Vector2d &getSize() const;

            void setSize(const Vector2d &size);

            Box *getBox() const;
        };
    }
}


#endif //RTYPE_RIGIDBODYCOMPONENT_HPP
