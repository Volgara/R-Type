//
// Created by Hamza Hammouche on 20/01/2018.
//

#ifndef RTYPE_BULLETCOMPONENT_HPP
#define RTYPE_BULLETCOMPONENT_HPP

#include <core/Component.hpp>
#include <core/GameObject.hpp>
#include <physics/RigidBodyComponent.hpp>

namespace engine {
    namespace projectile {
        class BulletComponent : public core::Component {
        private:
            physics::RigidBodyComponent *_body;
            int _damage;
        public:
            BulletComponent();

            virtual ~BulletComponent();

            void SendMessage(core::Message *message) override;

            void Update(float dt) override;

            void Init() override;

            void ShutDown() override;

            int getDamage() const;

            void setDamage(int _damage);
        };
    }
}

#endif //RTYPE_BULLETCOMPONENT_HPP
