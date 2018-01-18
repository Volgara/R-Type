//
// Created by macdoy on 18/01/18.
//

#ifndef RTYPE_BULLETSYSTEM_HPP
#define RTYPE_BULLETSYSTEM_HPP

#include "../engine/core/ASystem.hpp"
#include "../engine/core/Engine.hpp"
#include "../engine/core/Component.hpp"
#include "BulletComponent.hpp"

namespace game {
    class BulletSystem : public engine::core::ASystem {
    public:
        BulletSystem();

        ~BulletSystem();

        void Update(float dt) override;

        void Init() override;

    protected:
        void onNotify(engine::core::Message message) override;
    };
}

#endif //RTYPE_BULLETSYSTEM_HPP
