//
// Created by macdoy on 21/01/18.
//

#ifndef RTYPE_GAMELOGICCLIENTSYSTEM_HPP
#define RTYPE_GAMELOGICCLIENTSYSTEM_HPP

#include <core/ASystem.hpp>
#include <core/Scene.hpp>
#include <core/Engine.hpp>
#include <core/GameObject.hpp>
#include "PlayerComponent.hpp"
#include <projectile/BulletComponent.hpp>
namespace game {
    class GameLogicClientSystem : public engine::core::ASystem {
    private:
        float _currentDt;
    private:
        void movePlayer(engine::core::GameObject *, engine::core::Direction dir);
    public:
        GameLogicClientSystem();

        void Update(float d) override;

        void Init() override;

        ~GameLogicClientSystem() override = default;

        void onNotify(engine::core::Message message) override;
    };
}

class GameLogicServerSystem {

};


#endif //RTYPE_GAMELOGICCLIENTSYSTEM_HPP
