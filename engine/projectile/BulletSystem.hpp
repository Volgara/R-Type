//
// Created by Hamza Hammouche on 20/01/2018.
//

#ifndef RTYPE_BULLETSYSTEM_HPP
#define RTYPE_BULLETSYSTEM_HPP

#include <vector>
#include <map>
#include "core/ASystem.hpp"
#include "core/Engine.hpp"
#include "core/Message.hpp"
#include "BulletComponent.hpp"

namespace engine {
    namespace projectile {
        class BulletSystem : core::ASystem {
        public:
            BulletSystem();

            virtual ~BulletSystem();

        private:
            void Update(float dt) override;

            void Init(void) override;

            void onNotify(core::Message message) override;
        };
    }
}


#endif //RTYPE_BULLETSYSTEM_HPP
