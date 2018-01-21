//
// Created by macdoy on 21/01/18.
//

#ifndef GAME_GAME_LOGIC_CLIENT_SYSTEM_HPP
#define GAME_GAME_LOGIC_CLIENT_SYSTEM_HPP

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
        void move(engine::core::GameObject *, int x, int y);
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


#endif //GAME_GAME_LOGIC_CLIENT_SYSTEM_HPP
