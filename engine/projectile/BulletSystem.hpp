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
        class BulletSystem : public core::ASystem {
        private:
            int _width;
            int _height;
        public:
            BulletSystem(int width, int height);

            virtual ~BulletSystem();

            void Update(float dt) override;

            void Init() override;

            void onNotify(core::Message message) override;
        };
    }
}


#endif //RTYPE_BULLETSYSTEM_HPP
